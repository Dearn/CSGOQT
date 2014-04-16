all:
	g++ test.cpp -o LinusCSGO -lcurl -I/usr/include/jsoncpp -l:libjsoncpp.so
