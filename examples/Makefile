all:
	echo "generating code"
	cd ..; 	bundle exec ruby -r ./example/example.rb -e "DataMapper::MetaMapper.generate(:cpp, :output_dir => './output')"
	g++ ../output/dmmm_utils.cpp ../output/dmmm_dbface.cpp example.cpp -I ../output -I /usr/include/mysql -I /usr/local/include/mysql++ -I /usr/local/mysql/include/mysql -lmysqlpp -lmysqlclient /usr/lib/libboost_thread-mt.so -L/usr/lib -L/usr/local/lib -Wall -o example
