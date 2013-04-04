module MetaMapper
  module DataMapperSupport
    def many_to_one
      return unless model

      @many_to_one ||= relationship_by_type(DataMapper::Associations::ManyToOne::Relationship)
    end

    def one_to_many
      return unless model

      @one_to_many ||= relationship_by_type(DataMapper::Associations::OneToMany::Relationship)
    end

    private

    def relationship_by_type(association)
      Hash[model.relationships.select {|r|
        r.class == association
      }.map {|r|
        [r.name, r]
      }]
    end
  end
end
