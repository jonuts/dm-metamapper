$:.push File.expand_path('../lib', __FILE__)

require 'rubygems'
require 'bundler'
Bundler.setup(:default, :test)
require 'spec'

require 'dm-metamapper'
