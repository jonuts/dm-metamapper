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

      def generate(format, context=nil)
        generator = Generator[format]
        generator.run(context)

        models.each {|model| generate(format,model)} if !context
      end
    end
  end
end

