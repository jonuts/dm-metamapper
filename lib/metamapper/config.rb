module MetaMapper
  class Config < Hash
    def initialize
      super
      self.merge! MetaMapper._default_opts
    end

    alias_method :use, :merge!

    def method_missing(meth, *args)
      if keys.include?(meth.to_sym)
        self[meth.to_sym]
      else
        raise NoMethodError, "undefined method `#{meth}' for #{self.class}:#{self.class.class}"
      end
    end
  end
end


