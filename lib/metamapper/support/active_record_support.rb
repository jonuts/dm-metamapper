module MetaMapper
  module ActiveRecordSupport

     def setup_orm_specific_fields 
      enums = {}
      # Adds cpp_name to each column
      # Adds enums 

      # works on "Columns" ActiveRecord::ConnectionAdapters::Mysql2Adapter::Colmn

      model.columns.each do |c|
        cpp_name = if c.primary
         "Field<I_#{decolonize(model.name)}>"

        elsif is_key_to_parent(c.name) # is this a key to a parent
          "Field<I_#{decolonize(c.name)}>"  # uses column name

        elsif model.methods.include?(:enum_field?) &&
              model.enum_field?(c.name.to_sym)
          name = c.name.upcase # enum name
          enums[name] =  model.send("#{c.name}_native")# or just the enum
          "Field<Enum#{decolonize(model.name)}#{name}>"

        else           
          "F_#{decolonize(c.type.to_s).capitalize}"
        end

        (class << c; self; end).instance_eval{ attr_accessor :cpp_name }
        c.cpp_name = cpp_name
      end

      (class << model; self; end).instance_eval{ attr_accessor :enums }
      model.enums = enums
    end

    # return tru is name is a key to a parent on model
    def is_key_to_parent(name)
      keys = model.reflections.select{ |s,v| v.macro == :belongs_to }
      keys = keys.map{ |k,v| v.foreign_key }
      keys.include?(name)
    end
 
    # Returns the key (string) 'child_model' uses to reference me
    def child_key(child_model)
      children = child_model.reflect_on_all_associations(:belongs_to)
      children.select!{ |c| c.class_name == model.name }
      children.first.foreign_key
    end

    # my key to refernce parrent
    # r is a columns, so we know this is the key to the parent?
    def get_key_to_parent(r)
      r.foreign_key 
    end

    # "belongs to"
    def many_to_one
      return unless model
      @many_to_one = model.reflect_on_all_associations(:belongs_to)
      @many_to_one.select!{ |v| MetaMapper.has_class(v.class_name) }
      @many_to_one
    end

    # "has many"
    def one_to_many
      return unless model
      @one_to_many = model.reflect_on_all_associations(:has_many)

      #what do we want to do with 'through'
      threws = @one_to_many.map{ |r| r.through_reflection }.compact
      @one_to_many = @one_to_many - threws

      # get rid of has many through
      @one_to_many.select!{ |v| MetaMapper.has_class(v.class_name) }
      @one_to_many
    end

    # child => Child
    def child_model_name(child)
      child.class_name
    end

    def primary_key(model)
      model.primary_key
    end

    def table_name(model)
      model.table_name
    end
    
    def parent_name(r)
      r.class_name
    end

    def child_plural_name(m)
      m.name.to_s
    end
    
    def get_enum(name, e, class_name)
       e.map{|k,v| class_name.upcase + "_" + name.to_s.upcase + "_" + k.to_s.sub(".","_").upcase + " = " + v.to_s}.join(", ")
    end

    # get columns
    def generated_properties
      @generated_properties ||= model.columns
    end

    def is_enum?(c)
      model.methods.include?(:enum_field?) &&
        model.enum_field?(c.name.to_sym)
    end

    private

    # probably don't need this...
    def relationship_by_type(association)
      Hash[model.relationships.select {|r|
        r.class == association
      }.map {|r|
        [r.name, r]
      }]
    end
  end

end
