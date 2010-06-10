module DataMapper
  module MetaMapper
    module Generators
      class CPP < DataMapper::MetaMapper::Generator
        generates_file :global, "dmmm_identifiers.hpp"
        generates_file :global, "dmmm_comparators.hpp"
        generates_file :global, "dmmm_fields.hpp"
        generates_file :global, "dmmm_utils.hpp"
        generates_file :global, "dmmm_utils.cpp"
        generates_file :global, "dmmm_dbface.cpp"
        generates_file :global, "dmmm_dbface.h"
        generates_file :global, "dmmm_id.hpp"

        generates_file :model, "O_instance.hpp", :template => "instance.hpp.erb"
        generates_file :model, "T_class.hpp", :template => "class.hpp.erb"

        setup_model do |model|
          key_to_parent = model.relationships.inject({}) do |hash, (r,m)|
            next unless m.class.name == 'DataMapper::Associations::ManyToOne::Relationship'
            hash[m.child_key.first.name] = decolonize(m.parent_model_name.to_const_string)
            hash
          end

          model.properties.each do |prop|
            cpp_name = if prop.serial?
              "Field<I_#{decolonize(model.name)}>"
            elsif key_to_parent[prop.name.to_s]
              "Field<I_#{key_to_parent[prop.name.to_s]}>"
            else           
              "F_#{decolonize(prop.primitive)}"
            end

            prop.instance_variable_set(:@cpp_name, cpp_name)
          end
        end

        private

        def decolonize(str)
          str.sub(/::/,'_')
        end
      end
    end
  end
end


