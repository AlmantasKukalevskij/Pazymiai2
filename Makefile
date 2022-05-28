main : main.o
	g++ -o main v1.1.cpp *.o -O3
main.o :
	g++ -c cppFailai/*.cpp -O3
clean :
	del main.exe *.o
