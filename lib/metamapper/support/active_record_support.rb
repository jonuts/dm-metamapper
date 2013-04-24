module MetaMapper
  module ActiveRecordSupport

     def setup_orm_specific_fields 
      enums = {}

      # get "columbs/attributes"
      # model.columns or .columns_hash
      model.properties.each do |prop|
        cpp_name = if prop.serial?
         "Field<I_#{decolonize(model.name)}>"

        elsif key_to_parent[prop.name]
         "Field<I_#{key_to_parent[prop.name]}>"

        elsif DataMapper::Property::Enum === prop
          name = prop.name.to_s.upcase
          enums[name] = prop
          "Field<Enum#{decolonize(model.name)}#{name}>"

        else           
          "F_#{decolonize(prop.primitive.to_s)}"
        end

        (class << prop; self; end).instance_eval{ attr_accessor :cpp_name }
        prop.cpp_name = cpp_name

      end

      (class << model; self; end).instance_eval{ attr_accessor :enums }

      model.enums = enums
    end

    def key_to_parent
      many_to_one.inject({}) do |hash, (r,m)|
        hash[m.child_key.first.name] = decolonize(m.parent_model_name.to_const_string)
        hash
      end
    end
        
    def child_key(child_model)
      child_model.relationships.select {|m|
        m.class.name == 'DataMapper::Associations::ManyToOne::Relationship' && m.parent_model_name == model.name
          }.first.child_key.first.name.to_s
    end

    # "belongs to"
    def many_to_one
      return unless model
      
      @many_to_one ||= model.reflect_on_all_associations(:belongs_to)
 
      #in case of ruby < 1.9
      if Array === @many_to_one
        temp = @many_to_one
        @many_to_one = {}
        temp.each{|t| @many_to_one[t.name] = t}
      end 

      @many_to_one.select!{|k,v| MetaMapper.has_class(v.parent_model_name)}

      @many_to_one.select!{|k,v| MetaMapper.has_class(v.parent_model_name)}
      @many_to_one
    end

    # "has many"
    def one_to_many
      return unless model
      @one_to_many ||= model.relationships.select {|m|
        m.class.name == 'DataMapper::Associations::OneToMany::Relationship'
      }

      #in case of ruby < 1.9
      if Array === @one_to_many
        temp = @one_to_many
        @one_to_many = {}
        temp.each{|t| @one_to_many[t.name] = t}
      end

      @one_to_many.select!{|k,v| MetaMapper.has_class(v.child_model_name)}
      @one_to_many
    end

    def generated_properties
      @generated_properties ||= model.properties
    end

    private

    def relationship_by_type(association)
      Hash[model.relationships.select {|r|
        r.class == association
      }.map {|r|
        [r.name, r]
      }]
    end
  end

end
