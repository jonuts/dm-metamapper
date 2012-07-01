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

        def run(model, opts)
          @model = model
          @config.use :output_dir => opts[:output_dir] if opts[:output_dir]
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

        def snake_case(s)
          s.gsub(/::/, '/').
            gsub(/([A-Z]+)([A-Z][a-z])/,'\1_\2').
            gsub(/([a-z\d])([A-Z])/,'\1_\2').
            tr("-", "_").
            downcase
        end

        def inherited(klass)
          @subclasses ||= []
          @subclasses << klass
          klass.instance_variable_set(:@generator_name, snake_case(klass.name.split("::").last).to_sym)
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

#        puts "generating " + template.inspect
        compiled = ERB.new(File.read(template.full_path), nil, "%<>-").result(binding)
        path = respond_to?(:output_path) ? output_path(model, template) : template.output_name
        if !File.exists?(path) || File.read(path) != compiled
          File.open(path, 'w') {|f| f << compiled}
        end

      end
    end

  end
end

