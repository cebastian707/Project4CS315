
make.x: main.o Reader.o Graph.o 
	g++ -std=c++17 Graph.o main.o Reader.o -o make.x

Graph.o: Graph.hpp Graph.cpp Reader.hpp 
	g++ -std=c++17 Graph.cpp -o Graph.o -c

main.o: main.cpp Graph.hpp
	g++ -std=c++17 main.cpp -o main.o -c

Reader.o: Reader.hpp Reader.cpp
	g++ -std=c++17 Reader.cpp -o Reader.o -c