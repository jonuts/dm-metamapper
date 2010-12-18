source :rubygems

dm_gems_version   = "~> 1.0"
do_gems_version   = "~> 1.0"

gem "dm-core", dm_gems_version
gem "dm-types", dm_gems_version


group :test do
  gem "rspec"
  gem "dm-sqlite-adapter", do_gems_version
  gem "dm-mysql-adapter", do_gems_version
  gem "ZenTest"
end

group :deploy do
  gem "jeweler"
end

# vim: set ft=ruby:
