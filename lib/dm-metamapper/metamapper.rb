module DataMapper
  module MetaMapper
    class << self
      attr_reader :models

      def register(klass)
        (@models ||= []) << klass
      end

      def generate(format, context=nil)
        type, _binding = if context
          [:generated_model_files, context.send(:binding)]
        else
          [:generated_global_files, binding]
        end

        generator = Generator[format]

        generator.send(type).each do |generated_file|
          temp_filename = [
            File.dirname(__FILE__), 
            "templates", 
            generated_file.generator_name, 
            generated_file.template
          ].join('/')

          result_base_name = context ? context.name.to_s : generated_file.template.sub(/\.erb$/,'')

          result_filename = File.join(
            File.dirname(__FILE__), "../output", [
              generated_file.file_name_prefix,
              result_base_name,
              generated_file.file_name_suffix
            ].join
          )

          if File.exists?(temp_filename)
            puts "writing file " + result_filename
            template = ERB.new(File.read(temp_filename))
            result = template.result(_binding)
            File.open(result_filename, 'w') { |f| f << result }
          else
            puts "ERROR: " + temp_filename + " does not exist"
          end
        end

        if !context
          generator.models.select {|model| 
            model.generates?(format)
          }.each {|model| 
            model.generate(format)
          } 
        end

      end
    end
  end
end

