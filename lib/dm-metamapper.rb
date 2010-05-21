require 'dm-core'

DataMapper::Property.accepts_options :skip_generation

module DataMapper
  module MetaMapper
    module Extension
      def generates(*layouts)
        @_generation_formats = Array(layouts)
      end

      def generate(format)
      end

      def generated_properties
        @_generated_properties ||= properties.select {|prop|
          !prop.opts[:skip_generation]
        }
      end
    end

    def self.extended(base)
      base.instance_variable_set(:@_generation_formats, [])
      class <<base; attr_reader :_generation_formats end
    end

    class Format; end
    class Generator; end
  end
end
