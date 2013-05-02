module MetaMapper
  module ActiveRecordSupport

     # 1) convert every column name to a cpp_name
     # 2) If enums are defined for the model, they are converted to cpp
     def setup_orm_specific_fields 
      enums = {}
      model.columns.each do |c|
        cpp_name = if c.primary
         "Field<I_#{decolonize(model.name)}>"
        elsif is_key_to_parent(c.name) 
          "Field<I_#{decolonize(get_column_parent_model_name(c))}>" 
        elsif model.methods.include?(:enum_field?) &&
              model.enum_field?(c.name.to_sym)
          name = c.name.upcase # enum name
          enums[name] =  model.send("#{c.name}_native")
          "Field<Enum#{decolonize(model.name)}#{name}>"
        else   
          "F_#{decolonize(c.klass.to_s)}"
        end
        (class << c; self; end).instance_eval{ attr_accessor :cpp_name }
        c.cpp_name = cpp_name
      end
      (class << model; self; end).instance_eval{ attr_accessor :enums }
      model.enums = enums
    end

    def is_key_to_parent(name)
      keys = model.reflections.select{ |s,v| v.macro == :belongs_to }
      keys = keys.map{ |k,v| v.foreign_key }
      keys.include?(name)
    end
 
    # Returns the key (string) 'child_model' uses to reference me (the parent)
    # Probably dont need this method due to method 'get_key_to_parent'
    def child_key(child_model)
      children = child_model.reflect_on_all_associations(:belongs_to)
      children.select!{ |c| c.class_name == model.name }
      children.first.foreign_key
    end

    # my key to refernce parrent
    def get_key_to_parent(r)
      r.foreign_key 
    end

    # Handle all "belongs to" associations
    def many_to_one
      return unless model
      @many_to_one = model.reflect_on_all_associations(:belongs_to)
      @many_to_one.select!{ |v| MetaMapper.has_class(v.class_name) }
      @many_to_one
    end

    # Handle all "has many" associations, excluding 'through' associations
    def one_to_many
      return unless model
      return @one_to_many if @one_to_many
      @one_to_many = model.reflect_on_all_associations(:has_many)

      threws = @one_to_many.select{ |r| r.through_reflection }.compact
      @one_to_many = @one_to_many - threws

      @one_to_many.select!{ |v| MetaMapper.has_class(v.class_name) }
      @one_to_many
    end
  
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

    def generated_properties
      @generated_properties ||= model.columns
    end

    def is_enum?(c)
      model.methods.include?(:enum_field?) &&
        model.enum_field?(c.name.to_sym)
    end

    private

    def get_column_parent_model_name(c)
      parents = model.reflect_on_all_associations(:belongs_to)  
      parents.select!{ |r| r.foreign_key == c.name }
      parents.first.class_name
    end
  end # module active_record_support 
end
