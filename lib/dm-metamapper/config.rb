module DataMapper
  module MetaMapper
    class Config < Hash
      def initialize
        super
        self.merge! DataMapper::MetaMapper._default_opts
      end

      alias_method :use, :merge!
    end
  end
end

