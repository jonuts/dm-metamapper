if DataMapper::VERSION > "1.0"
  module DataMapper
    class Property
      accept_options :skip_generation
    end
  end
end

