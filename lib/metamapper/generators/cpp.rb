module MetaMapper
  module Generators
    class CPP < MetaMapper::Generator
      template_dir File.expand_path('../../../templates/cpp', __FILE__)

      generates_file :global, "dmmm_identifiers.hpp"
      generates_file :global, "dmmm_comparators.hpp"
      generates_file :global, "dmmm_fields.hpp"
      generates_file :global, "dmmm_utils.hpp"
      generates_file :global, "dmmm_utils.cpp"
      generates_file :global, "dmmm_dbface.cpp"
      generates_file :global, "dmmm_dbface.h"
      generates_file :global, "dmmm_id.hpp"

      generates_file :model, "O_%model%.hpp", :template => "instance.hpp"
      generates_file :model, "T_%model%.hpp", :template => "class.hpp"

    end
  end
end
