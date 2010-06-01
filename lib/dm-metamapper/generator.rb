module DataMapper
  module MetaMapper
    class Generator
      GeneratedFile = Struct.new(:template, :file_name_prefix, :file_name_suffix)

      @subclasses = []

      class << self
        attr_reader :subclasses,
                    :generator_name,
                    :generated_model_files
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

        def generates_file
          @generated_model_files ||= []
          @generated_model_files << yield(GeneratedFile.new)
        end

        def generates_global_file
          @generated_global_files ||= []
          @generated_global_files << yield(GeneratedFile.new)
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
  name :cpp

  generates_global_file do |f|
    f.template = "dmmm_identifiers.hpp"
  end

  generates_file do |f|
    f.file_name_suffix = ".hpp"
  end

  generates_file do |f|
    f.file_name_suffix ".hpp"
    f.file_name_prefix "T_"
    f.template "class.hpp.erb"
  end
end

