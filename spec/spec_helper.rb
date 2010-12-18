$:.push File.expand_path('../lib', __FILE__)

require 'rubygems'
require 'bundler'
Bundler.setup(:default, :test)
require 'rspec'

require 'dm-metamapper'

DMMM = DataMapper::MetaMapper
