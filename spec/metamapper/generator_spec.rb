require File.expand_path("../../spec_helper", __FILE__)

class MyGenerator < DMMM::Generator;end

class LolModel
  include DataMapper::Resource

  property :id, Serial
  property :name, String
end

describe "Generator" do
  describe "General" do
    it "is configurable" do
      MyGenerator.config.should == DMMM.instance_variable_get(:@_default_opts)
    end

    it "stores a block to extend models" do
      blk = lambda { @__foo__ = "lol" }
      MyGenerator.send(:setup_model, &blk)
      MyGenerator.setup_model_blk.should == blk
    end
  end

  describe "Templates" do
    it "has a template store" do
      DMMM::TemplateCollection.should === MyGenerator.generated_files
    end

    it "stores template info" do
      MyGenerator.send(:generates_file, :model, "foo")
      MyGenerator.generated_files.size.should == 1
      MyGenerator.generated_files.first.name.should == "foo"
    end
  end

  describe ".new" do
    before :each do
      MyGenerator.instance_variable_set :@generated_files, DMMM::TemplateCollection.new
      model_files = ["foo", "bar", "baz", "bleh"]

      model_files.each do |f|
        MyGenerator.send :generates_file, :model, f
      end
    end

    it "requires model info" do
      lambda {MyGenerator.new}.should raise_error(ArgumentError)
    end

    it "has model templates when called with model" do
      @generator = MyGenerator.new(LolModel)
      @generator.instance_variable_get(:@templates).should == MyGenerator.generated_files.models
    end

    it "has global templates when called without model" do
      @generator = MyGenerator.new nil
      @generator.instance_variable_get(:@templates).should == MyGenerator.generated_files.global
    end
  end
end

