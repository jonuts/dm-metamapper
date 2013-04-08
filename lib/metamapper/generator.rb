module MetaMapper
  class Generator
    class << self
      attr_accessor :model_setup, :generated_files

      def subclasses
        @subclasses ||= []
      end

      def [](format)
        subclasses.find {|klass| klass.format == format}
      end

      def format(name=nil)
        return @format unless name
        @format = name
      end

      def setup_model(&blk)
        self.model_setup = blk
      end

      def template_dir(dir=nil)
        return @template_dir unless dir
        @template_dir = dir
      end

      private

      def decolonize(str)
        str.sub(/::/,'_')
      end

      def generates_file(type, name, opts={})
        generated_files << Template.new(name, opts.merge(type: type, generator: self))
      end

      def inherited(klass)
        subclasses << klass
        klass.format(klass.name.demodulize.underscore)
        klass.setup_model Proc.new{}
        klass.generated_files = TemplateCollection.new
      end
    end

    def initialize(model, opts={})
      @model = model
      @opts  = opts
      extract_args_from_opts!
      add_support!

      instance_eval(&model_setup) if model && Proc === model_setup

      @templates = model ? generated_files.models : generated_files.global
    end

    attr_reader :templates, :opts
    attr_accessor :orm, :output_dir

    def run!
      templates.each do |template|
        compiled = ERB.new(File.read(template.full_path), nil, "%<>-").result(binding)
        File.open(template.output_path, 'w') {|f| f << compiled}
      end
    end

    private

    def model_setup
      self.class.model_setup
    end

    def generated_files
      self.class.generated_files
    end

    def extract_args_from_opts!
      self.orm = opts[:orm] || :datamapper
      self.output_dir = opts[:output_dir]
    end

    def add_support!
      case orm
      when :activerecord
        require File.expand_path('../support/active_record_support', __FILE__)
        extend ActiveRecordSupport
      when :datamapper
        require File.expand_path('../support/data_mapper_support', __FILE__)
        extend DataMapperSupport
      else
        raise "ORM #{generator.orm} not supported"
      end
    end
  end
end

