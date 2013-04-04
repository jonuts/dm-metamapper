module MetaMapper
  class << self
    attr_reader :models

    def register(klass)
      models << klass unless models.member?(klass)
    end

    def models
      @models ||= []
    end

    def generate(format, opts={})
      context = opts.delete(:context)
      generator = Generator[format].new(context, opts)

      generator.run

      unless context
        models.each do |model|
          opts[:context] = model
          generate(format, opts)
        end
      end
    end
  end
end

__END__

MetaMapper.generate(:cpp, template_dir: '/tmp/lol/', output_dir: '/tmp/lol-output/', orm: :active_record)

generator = Generator.new orm: orm, type: type
generator.run!
generator.generated_files.models.each do |template|
  generator.generate template
end
