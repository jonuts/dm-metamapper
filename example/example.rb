require "erb"
require "rubygems"
require "bundler"
Bundler.setup(:default, :test)
require "dm-core"
require "lib/dm-metamapper.rb"

#DataMapper.setup(:default, "sqlite3::memory:")
DataMapper.setup(:default, "mysql://root@localhost/dmmm")

class User
  include DataMapper::Resource
  extend DataMapper::MetaMapper::Extension

  generates :cpp

  has n,    :dogs

  property :id,           Serial
  property :name,         String
  property :balance,      Float
  property :weight,       Integer
end

class Dog
  include DataMapper::Resource
  extend DataMapper::MetaMapper::Extension

  generates :cpp

  belongs_to :user
  has n,     :little_fleas

  property :id,       Serial
  property :user_id,  Integer
  property :name,     String
  property :stinks,   Boolean
end

class LittleFlea
  include DataMapper::Resource
  extend DataMapper::MetaMapper::Extension

  generates :cpp
 
  belongs_to :dog

  property :id,       Serial
  property :dog_id,   Integer
end
