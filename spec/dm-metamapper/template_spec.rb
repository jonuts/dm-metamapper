require File.expand_path("../../spec_helper", __FILE__)

class LolGenerator < DMMM::Generator
  config.use :template_dir => "/tmp/lol/templates",
    :output_dir => "/tmp/lol/output"
end

describe "Template" do
  context "invalid" do
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

  context "valid" do
    before :all do
      @template = DMMM::Template.new :foo, 
        generator: LolGenerator,
        type: :global
    end

    it "has a generator" do
      @template.instance_variable_get(:@generator).should eql(LolGenerator)
    end

    it "has a template type" do
      @template.type.should eql(:global)
    end

    it "has a template filename" do
      @template.instance_variable_get(:@template_name).should eql("foo.erb")
    end

    it "has a full path" do
      @template.full_path.should eql("/tmp/lol/templates/foo.erb")
    end

    it "has an output directory" do
      @template.output_path.should eql("/tmp/lol/output/foo")
    end
  end
end

