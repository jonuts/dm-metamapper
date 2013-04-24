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
      @models = opts[:models] if opts[:models]
      # @models = models.select{ |m| m.key.size == 1}

      context = opts.delete(:context)
      generator = Generator[format].new(context, opts)
      generator.run()
            
      models.each { |model|
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





__END__

MetaMapper.generate(:cpp, template_dir: '/tmp/lol/', output_dir: '/tmp/lol-output/', orm: :active_record)

generator = Generator.new orm: orm, type: type
generator.run!
generator.generated_files.models.each do |template|
  generator.generate template
end
