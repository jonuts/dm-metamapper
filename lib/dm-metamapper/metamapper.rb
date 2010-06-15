module DataMapper
  module MetaMapper
    @_default_opts = {
      :template_dir => Dir.pwd,
      :output_dir => Dir.pwd
    }

    class << self
      attr_reader :models, :_default_opts

      def use(opts)
        @_default_opts.merge! opts
      end

      def register(klass)
        @models ||= []
        @models << klass unless models.member?(klass)
      end

      def generate(format, opts = {})
        context = opts.delete(:context)
        generator = Generator[format]
        generator.run(context, opts)

        models.each {|model| 
          opts[:context] = model
          generate(format, opts)
        } if !context
      end
    end
  end
end

