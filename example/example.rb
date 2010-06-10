require "erb"
require "rubygems"
require "bundler"
Bundler.setup(:default, :test)
require "dm-core"
require "lib/dm-metamapper.rb"
DataMapper::MetaMapper.use :output_dir => File.expand_path('../../output', __FILE__)
require "dm-metamapper/generators/cpp"

#DataMapper.setup(:default, "sqlite3::memory:")
DataMapper.setup(:default, "mysql://root@localhost/dmmm")

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
  has n,     :little_fleas

  property :id,       Serial
  property :user_id,  Integer
  property :name,     String
  property :stinks,   Boolean
end

class LittleFlea
  include DataMapper::Resource
  extend DataMapper::MetaMapper::Extension

  belongs_to :dog

  property :id,       Serial
  property :dog_id,   Integer
end
