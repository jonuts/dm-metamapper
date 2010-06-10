module DataMapper
  module MetaMapper
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
        @template = opts.delete(:template)
      end

      attr_reader :name, :template, :type

      def output_path
      end

      def full_path
      end
    end
  end
end

