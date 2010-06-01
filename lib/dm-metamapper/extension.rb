module DataMapper
  module MetaMapper
    module Extension
      def generates(*layouts)
        @_generation_formats = Array(layouts)
      end

      def generates?(format)
        @_generation_formats.include?(format)
      end

      def generate(format)
        DataMapper::MetaMapper.generate(format, self)
      end

      def generated_properties
        @_generated_properties ||= properties.select {|prop|
          !prop.options[:skip_generation]
        }
      end

      def _get_binding
        binding
      end

      def self.extended(base)
        DataMapper::MetaMapper.register(base)
        base.instance_variable_set(:@_generation_formats, [])
        class <<base; attr_reader :_generation_formats end
      end

    end
  end
end

