module MetaMapper
  class TemplateCollection < Array
    def models
      select {|t| t.type == :model}
    end

    def global
      select {|t| t.type == :global}
    end
  end

  class Template
    def initialize(name, opts={})
      @name      = name.to_s
      @generator = opts.delete(:generator)
      @type      = opts.delete(:type)
      @template_name  = parse_template(opts.delete(:template))

      @output_path    = opts[:output_dir] #should be expanede?
      @full_path      = opts[:template_dir]
    end

    attr_reader :name, :type

    def output_path
      File.join(@output_path, name)
    end

    def full_path
      File.join(@full_path, @template_name)
    end

    private

    def parse_template(template_name)
      (template_name || name).to_s + ".erb"
    end
  end
end
