require 'dm-core'

DataMapper::Property.accepts_options :skip_generation

module DataMapper
  module MetaMapper
    class << self
      attr_reader :models

      def register(klass)
        (@models ||= []) << klass
      end
    end

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

      def self.extended(base)
        DataMapper::MetaMapper.register(base)
        base.instance_variable_set(:@_generation_formats, [])
        class <<base; attr_reader :_generation_formats end
      end
    end

    class Generator
      @subclasses = []

      class << self
        attr_reader :subclasses, :generator_name

        def [](generator)
          @subclasses.find {|klass| klass.generator_name == generator}
        end

        protected
        
        def template(template=nil)
          return @template unless template
          @template = template
        end

        def name(name)
          @generator_name = name
        end

        private

        def inherited(klass)
          @subclasses << klass
        end
      end
    end
  end
end

class DataMapper::MetaMapper::Generator::JS < DataMapper::MetaMapper::Generator
  name :js
  template <<EOTEMPLATE
<%= model.class_name %> = MetaMapper.register("<%= model.table_name %>", function() {

  <% model.generated_properties.each do |property| %>
  this.property("<%= property.name %>", "<%= property.type %>");
  <% end %>

});
EOTEMPLATE

end

