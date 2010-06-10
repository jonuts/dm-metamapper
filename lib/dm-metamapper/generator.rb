module DataMapper
  module MetaMapper
    class Generator
      class NoTemplateError < StandardError; end

      @subclasses = []

      class << self
        attr_reader :subclasses,
                    :generated_files,
                    :config,
                    :setup_model_blk

        def [](generator)
          @subclasses.find {|klass| klass.generator_name == generator}
        end

        def generator_name(name=nil)
          return @generator_name unless name
          @generator_name = name
        end

        def run(model)
          @model = model
          new(model).run
        end

        private

        def generates_file(type, name, opts={})
          opts.merge! :type => type, :generator => self
          @generated_files << Template.new(name, opts)
        end

        def setup_model(&blk)
          @setup_model_blk = blk
        end

        def inherited(klass)
          @subclasses ||= []
          @subclasses << klass
          klass.instance_variable_set(:@generator_name, klass.name.split("::").last.snake_case.to_sym)
          klass.instance_variable_set(:@setup_model_blk, Proc.new{})
          klass.instance_variable_set(:@config, Config.new)
          klass.instance_variable_set(:@generated_files, TemplateCollection.new)
        end
      end

      # model can be nil or DataMapper::Model
      def initialize(model)
        @model = model

        instance_eval(&self.class.setup_model_blk) if model

        @templates = if model
          self.class.generated_files.models
        else
          self.class.generated_files.global
        end
      end

      attr_reader :model

      def run
        @templates.each {|template| generate template }
      end

      private

      def models
        DataMapper::MetaMapper.models
      end

      def generate(template)
        if !File.exists? template.full_path
          raise NoTemplateError, "Template does not exist at path #{template.full_path}"
        end

        compiled = ERB.new(File.read(template.full_path)).result(binding)
        File.open(template.output_path(model), 'w') {|f| f << compiled}
      end
    end

  end
end

