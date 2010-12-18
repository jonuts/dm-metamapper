lib = File.dirname(__FILE__)
$:.push lib unless $:.include?(lib)

require 'dm-core'
require 'dm-metamapper/property'
require 'dm-metamapper/model'
require 'dm-metamapper/config'
require 'dm-metamapper/metamapper'
require 'dm-metamapper/template'
require 'dm-metamapper/generator'

