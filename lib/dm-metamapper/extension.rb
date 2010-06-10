module DataMapper
  module MetaMapper
    module Extension
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

      def self.extended(base)
        DataMapper::MetaMapper.register(base)
        base.instance_variable_set(:@_skipped_generation_formats, [])
        class <<base; attr_reader :_skipped_generation_formats end
      end
    end
  end
end

