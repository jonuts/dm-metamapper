module DataMapper
  module MetaMapper
    module Generators
      class CPP < DataMapper::MetaMapper::Generator
        config[:template_dir] = File.expand_path('../../../templates/cpp', __FILE__)

        generates_file :global, "dmmm_identifiers.hpp"
        generates_file :global, "dmmm_comparators.hpp"
        generates_file :global, "dmmm_fields.hpp"
        generates_file :global, "dmmm_utils.hpp"
        generates_file :global, "dmmm_utils.cpp"
        generates_file :global, "dmmm_dbface.cpp"
        generates_file :global, "dmmm_dbface.h"
        generates_file :global, "dmmm_id.hpp"

        generates_file :model, "O_%model%.hpp", :template => "instance.hpp"
        generates_file :model, "T_%model%.hpp", :template => "class.hpp"

        setup_model do
          enums = {}
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
            hash[m.child_key.first.name] = decolonize(m.parent_model_name)
            hash
          end
        end

        def child_key(child_model)
          child_model.relationships.find {|k,m|
            m.class.name == 'DataMapper::Associations::ManyToOne::Relationship' && m.parent_model_name == model.name
          }[1].child_key.first.name.to_s
        end

        def output_path(model, template)
          name = model ? template.name.sub("%model%", decolonize(model.name)) : template.name
          File.join(self.class.config.output_dir, name)
        end

        private

        def decolonize(str)
          str.sub(/::/,'_')
        end

        def many_to_one
          return unless model
          @many_to_one ||= model.relationships.select {|k,m|
            m.class.name == 'DataMapper::Associations::ManyToOne::Relationship'
          }
          
          #in case of ruby < 1.9
#          if Array === @many_to_one
#            temp = @many_to_one
#            @many_to_one = {}
#            temp.each{|t| @many_to_one[t.name] = t}
#          end

          @many_to_one
        end
        def one_to_many
          return unless model
          @one_to_many ||= model.relationships.select {|k,m|
            m.class.name == 'DataMapper::Associations::OneToMany::Relationship'
          }
          #in case of ruby < 1.9
#          if Array === @one_to_many
#            temp = @one_to_many
#            @one_to_many = {}
#            temp.each{|t| @one_to_many[t.name] = t}
#          end

          @one_to_many
        end
      end
    end
  end
end


