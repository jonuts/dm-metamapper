begin
  require 'bundler'
  Bundler.setup :deploy
  require 'jeweler'
  Jeweler::Tasks.new do |gemspec|
    gemspec.name = "dm-metamapper"
    gemspec.summary = "Code generating C++ ORM"
    gemspec.description = "C++ API for databases created with DM. Hard typing, compile time checked queries."
    gemspec.email = "jonah@honeyman.org"
    gemspec.homepage = "http://github.com/jonuts/dm-metamapper"
    gemspec.authors = ["Jonah Honeyman", "Omer Tamuz"]
  end
rescue LoadError
  puts "Jeweler not available. Install it with: gem install jeweler"
end

desc "local gem build and install"
task :local do
  sh "rvm ree@drive"
  sh "gem uninstall -a dm-metamapper"
  sh "gem build dm-metamapper.gemspec"
  version = File.read("VERSION").chomp
  sh "gem install -l ./dm-metamapper-#{version}.gem"
end
