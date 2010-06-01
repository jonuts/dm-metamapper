$:.push(File.join(File.dirname(__FILE__), "../lib"))

require 'rubygems'
require 'bundler'
Bundler.setup(:default, :test)
require 'spec'

require 'dm-metamapper'
