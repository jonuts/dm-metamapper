require "erb"
require "rubygems"
require "bundler"
Bundler.setup(:default, :test)
require "dm-core"
require "dm-types"
require File.expand_path("../../lib/dm-metamapper.rb", __FILE__)
require "dm-metamapper/generators/cpp"

#DataMapper.setup(:default, "sqlite3::memory:")
DataMapper.setup(:default, "mysql://root@localhost/dmmm")

COLORS = [
  :blue,
  :white
]

class User
  include DataMapper::Resource

  has n,    :dogs

  property :id,           Serial
  property :name,         String
  property :balance,      Float
  property :weight,       Integer
end

class Dog
  include DataMapper::Resource

  belongs_to :user
  has n,     :little_fleas

  property :id,       Serial
  property :user_id,  Integer
  property :name,     String
  property :color,    Enum[*COLORS]
  property :stinks,   Boolean
end

class LittleFlea
  include DataMapper::Resource

  belongs_to :dog

  property :id,       Serial
  property :dog_id,   Integer
end
