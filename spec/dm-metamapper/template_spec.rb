require File.expand_path("../../spec_helper", __FILE__)

class LolGenerator < DMMM::Generator; end

describe "Template" do
  describe "invalid" do
    it "requires a name" do
      lambda {DMMM::Template.new}.should raise_error(ArgumentError)
    end

    it "requires a generator" do
      lambda {DMMM::Template.new(:foo)}.should raise_error(DMMM::NoGeneratorError)
    end

    it "requires a valid type" do
      lambda {DMMM::Template.new(:few, generator: LolGenerator)}.
        should raise_error(DMMM::InvalidTypeError)
    end
  end

  describe "valid" do
    before :all do
      @template = DMMM::Template.new :foo, 
        generator: LolGenerator,
        type: :global
    end
  end
end

