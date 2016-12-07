class Database
  include Mongoid::Document
  include Mongoid::Timestamps

  has_many :parts
  has_many :comments
  has_many :jobs

  field :name, type: String
  field :user_id, type: Integer
  field :description, type: String
  field :data_type, type: String
  field :data_format, type: String
  field :size, type: String
end
