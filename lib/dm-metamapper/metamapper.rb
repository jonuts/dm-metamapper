module DataMapper
  module MetaMapper
    class << self
      attr_reader :models

      def register(klass)
        @models ||= []
        @models << klass unless models.member?(klass)
      end

      def generate(format, context=nil)
        generator = Generator[format]

        if context
          context.instance_eval(&generator.proxy_blk) if generator.proxy_blk
          type, _binding = :generated_model_files, context._get_binding
        else
          type, _binding = :generated_global_files, binding
        end

        generator.send(type).each do |generated_file|
          temp_filename = [
            File.dirname(__FILE__), 
            "../templates", 
            generator.generator_name, 
            generated_file.template
          ].join('/')

          result_base_name = context ? context.name.to_s.sub(/::/,'_') : generated_file.template.sub(/\.erb$/,'')

          result_filename = File.join(
            File.dirname(__FILE__), "../../output", [
              generated_file.file_name_prefix,
              result_base_name,
              generated_file.file_name_suffix
            ].join
          )

          if File.exists?(temp_filename)
            STDOUT.puts "writing file " + result_filename
            template = ERB.new(File.read(temp_filename))
            result = template.result(_binding)
            File.open(result_filename, 'w') { |f| f << result }
          else
            STDERR.puts "ERROR: " + temp_filename + " does not exist"
          end
        end

        if !context
          models.select {|model| 
            model.generates?(format)
          }.each {|model| 
            model.generate(format)
          } 
        end

      end
    end
  end
end

