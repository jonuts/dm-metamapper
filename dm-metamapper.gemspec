lib = File.expand_path('../lib', __FILE__)
$:.unshift lib unless $:.include?(lib)

require 'dm-metamapper/version'

Gem::Specification.new do |s|
  s.name = %q{dm-metamapper}
  s.version = DataMapper::MetaMapper::VERSION
  s.platform = Gem::Platform::RUBY

  s.required_rubygems_version = ">= 1.3.6"
  s.authors = ["Jonah Honeyman", "Omer Tamuz"]
  s.description = %q{C++ API for databases created with DM. Hard typing, compile time checked queries.}
  s.email = %q{jonah@honeyman.org}
  s.rubyforge_project = "dm-metamapper"
  s.extra_rdoc_files = [
    "README.md"
  ]
  s.files = Dir.glob("lib/**/*") 
  s.homepage = %q{http://github.com/jonuts/dm-metamapper}
  s.rdoc_options = ["--charset=UTF-8"]
  s.require_paths = ["lib"]
  s.rubygems_version = %q{1.3.6}
  s.summary = %q{Code generating C++ ORM}
end

