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
        @models = opts[:models]
        context = opts.delete(:context)
        generator = Generator[format]
        generator.run(context, opts)

        @models = models.select{ |m| m.key.size == 1}

        models.each {|model|
          puts "generating #{model}"
          opts[:context] = model
          generate(format, opts)
        } if !context
      end

      def has_class(klass)
        @models.count{|m| m.name == klass} == 1
      end
    end
  end
end

