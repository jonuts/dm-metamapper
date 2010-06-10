module DataMapper
  module MetaMapper
    class Generator
      @subclasses = []

      class << self
        attr_reader :subclasses,
                    :generated_files,
                    :proxy_blk,
                    :config

        def [](generator)
          @subclasses.find {|klass| klass.generator_name == generator}
        end

        def generator_name(name=nil)
          return @generator_name unless name
          @generator_name = name
        end

        def run(model)
          @model = model
          new(model, &@setup_model_blk).run
        end

        private

        def generates_file(type, name, opts={})
          opts.merge! :type => type, :generator => self

          @generated_files ||= TemplateCollection.new
          @generated_files << Template.new(name, opts)
        end

        def setup_model(&blk)
          @setup_model_blk = blk
        end

        def inherited(klass)
          @subclasses ||= []
          @subclasses << klass
          klass.instance_variable_set(:@generator_name, klass.name.snake_case)
          klass.instance_variable_set(:@setup_model_blk, lambda{|lolwut|})
          klass.instance_variable_set(:@config, Config.new)
        end
      end

      # model can be nil or DataMapper::Model
      def initialize(model)
        yield model if model

        @model = model
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

      def generate(template)
        if !File.exists? template.full_path
          raise NoTemplateError, "Template does not exist at path #{template.full_path}"
        end

        compiled = ERB.new(File.read(template.full_path)).result
        File.open(template.output_path, 'w') {|f| f << compiled}
      end
    end

  end
end

