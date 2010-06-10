module DataMapper
  module MetaMapper
    class NoGeneratorError < ArgumentError; end

    class TemplateCollection < Array
      def models
        self.select {|t| t.type == :model}
      end

      def global
        self.select {|t| t.type == :global}
      end
    end

    class Template
      def initialize(name, opts={})
        @name = name
        @type = opts.delete(:type)
        @generator = opts.delete(:generator) || raise(NoGeneratorError "opts did not contain :generator")
        @template = (opts.delete(:template) || @name) + ".erb"
      end

      attr_reader :name, :type

      def output_path
        File.join(@generator.config.output_dir, @name)
      end

      def full_path
        File.join(@generator.config.template_dir, @template)
      end
    end
  end
end

