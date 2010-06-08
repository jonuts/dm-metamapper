module DataMapper
  module MetaMapper
    class Generator
      class GeneratedFile
        def initialize(&blk)
          instance_eval(&blk) if block_given?
        end

        attr_reader :template, :file_name_prefix, :file_name_suffix

        def template_name(template)
          @template = template
        end

        def prefix(str)
          @file_name_prefix = str
        end

        def suffix(str)
          @file_name_suffix = str
        end
      end

      @subclasses = []

      class << self
        attr_reader :subclasses,
                    :generated_model_files,
                    :generated_global_files,
                    :proxy_blk

        def [](generator)
          @subclasses.find {|klass| klass.generator_name == generator}
        end

        def generator_name(name=nil)
          return @generator_name unless name
          @generator_name = name
        end

        private

        def generates_file(&blk)
          @generated_model_files ||= []
          @generated_model_files << GeneratedFile.new(&blk)
        end

        def generates_global_file(&blk)
          @generated_global_files ||= []
          @generated_global_files << GeneratedFile.new(&blk)
        end

        def proxy(&blk)
          @proxy_blk = blk
        end

        def inherited(klass)
          @subclasses ||= []
          @subclasses << klass
          klass.instance_variable_set(:@generator_name, @generator_name)
        end
      end
    end
  end
end

class DataMapper::MetaMapper::Proxy; end

class CPPGenerator < DataMapper::MetaMapper::Generator
  generator_name :cpp

  generates_global_file{ template_name "dmmm_identifiers.hpp.erb" }
  generates_global_file{ template_name "dmmm_comparators.hpp.erb" }
  generates_global_file{ template_name "dmmm_fields.hpp.erb" }
  generates_global_file{ template_name "dmmm_utils.hpp.erb" }
  generates_global_file{ template_name "dmmm_utils.cpp.erb" }
  generates_global_file{ template_name "dmmm_dbface.cpp.erb" }
  generates_global_file{ template_name "dmmm_dbface.h.erb" }
  generates_global_file{ template_name "dmmm_id.hpp.erb" }

  proxy do
    key_to_parent = {}
    relationships.select{|r,m| m.class.name == 'DataMapper::Associations::ManyToOne::Relationship'}.each do |r|
      key_to_parent[r[1].child_key.first.name.to_s] = r[0].to_const_string
      puts "#{r[1].child_key.first.name.to_s} -> #{r[0].to_const_string}"
    end

    properties.each do |e| 
      cpp_name = if e.serial?
        "Field<I_#{e.model.name}>"
      elsif !key_to_parent[e.name.to_s].nil?
        "Field<I_#{key_to_parent[e.name.to_s]}>"
      else           
        "F_#{e.primitive}"
      end

      e.instance_variable_set(:@cpp_name, cpp_name)
    end
  end

  generates_file do
    suffix ".hpp"
    prefix "O_"
    template_name "instance.hpp.erb"
  end

  generates_file do
    suffix".hpp"
    prefix "T_"
    template_name "class.hpp.erb"
  end
end

