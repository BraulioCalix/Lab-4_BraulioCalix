laboratorio: main.o
	g++ main.o -o laboratorio

main.o: Lab_4_BraulioCalix.cpp
	g++ -c Lab_4_BraulioCalix.cpp
