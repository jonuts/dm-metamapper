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
                    :generator_name,
                    :generated_model_files,
                    :generated_global_files

        def [](generator)
          @subclasses.find {|klass| klass.generator_name == generator}
        end

        def file_name_prefix(prefix = nil)
          return @file_name_prefix unless prefix
          @file_name_prefix = prefix
        end

        def file_name_suffix(suffix = nil)
          return @file_name_suffix unless suffix
          @file_name_suffix = suffix
        end

        def template(template=nil)
          return @template unless template
          @template = template
        end

        def generator_name(name=nil)
          return @generator_name unless name
          @generator_name = name
        end

        protected

        def generates_file(&blk)
          @generated_model_files ||= []
          @generated_model_files << GeneratedFile.new(&blk)
        end

        def generates_global_file(&blk)
          @generated_global_files ||= []
          @generated_global_files << GeneratedFile.new(&blk)
        end

        private

        def inherited(klass)
          @subclasses ||= []
          @subclasses << klass
          klass.instance_variable_set(:@generator_name, @generator_name)
        end
      end
    end
  end
end

class DataMapper::MetaMapper::Generator::CPP < DataMapper::MetaMapper::Generator
  generator_name :cpp

  generates_global_file{ template_name "dmmm_identifiers.hpp.erb" }
  generates_global_file{ template_name "dmmm_comparators.hpp.erb" }
  generates_global_file{ template_name "dmmm_fields.hpp.erb" }
  generates_global_file{ template_name "dmmm_utils.hpp.erb" }
  generates_global_file{ template_name "dmmm_utils.cpp.erb" }
  generates_global_file{ template_name "dmmm_dbface.cpp.erb" }
  generates_global_file{ template_name "dmmm_dbface.h.erb" }
  generates_global_file{ template_name "dmmm_id.hpp.erb" }

  generates_file do |f|
    suffix ".hpp"
    prefix "O_"
    template_name "instance.hpp.erb"
  end

  generates_file do |f|
    suffix".hpp"
    prefix "T_"
    template_name "class.hpp.erb"
  end
end

