
systemInterface.x: systemInterface_main.o systemInterface.o
	g++ -std=c++17 systemInterface_main.o systemInterface.o -o systemInterface.x

systemInterface.o: systemInterface.hpp systemInterface.cpp
	g++ -std=c++17 -c systemInterface.cpp -o systemInterface.o

systemInterface_main.o: systemInterface_main.cpp systemInterface.hpp
	g++ -std=c++17 -c systemInterface_main.cpp -o systemInterface_main.o

clean:
	rm -fr systemInterface.x *.o
