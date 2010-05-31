require "erb"
require "rubygems"
require "bundler"
Bundler.setup
require "dm-core"
require "lib/dm-metamapper.rb"

DataMapper.setup(:default, "sqlite3::memory:")

class User
  include DataMapper::Resource
  extend DataMapper::MetaMapper::Extension

  has n,    :dogs

  property :id,           Serial
  property :name,         String
  property :balance,      Float
  property :weight,       Integer
end

class Dog
  include DataMapper::Resource
  extend DataMapper::MetaMapper::Extension

  belongs_to :user

  property :id,     Serial
  property :name,   String
  property :stinks, Boolean
end

