all: main json
	g++ main.o json.o -o CSGOQT  -lcurl -l:libjsoncpp.so 
main: 
	g++ -c main.cpp  -I/usr/include/jsoncpp

json: 
	g++ -c json.cpp  -I/usr/include/jsoncpp
clean:
	rm *o a.out ./CSGOQT ./a.out ./bbb.json
