module DataMapper
  module Model
    class << self
      alias_method :_extended, :extended

      def extended(model)
        _extended(model)
        DataMapper::MetaMapper.register(model)
        model.instance_variable_set(:@_skipped_generation_formats, [])
        class <<model; attr_reader :_skipped_generation_formats end
      end
    end

    def doesnt_generate(*layouts)
      @_skipped_generation_formats = Array(layouts)
    end
    alias_method :dont_generate, :doesnt_generate
    alias_method :skip_generation, :doesnt_generate

    def generates?(format)
      !@_skipped_generation_formats.include?(format)
    end

    def generate(format)
      DataMapper::MetaMapper.generate(format, self)
    end

    def generated_properties
      @_generated_properties ||= properties.select {|prop|
        !prop.options[:skip_generation]
      }
    end

  end
end

