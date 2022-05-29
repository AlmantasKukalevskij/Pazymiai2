main : main.o
	g++ -o main*.o -O3
main.o :
	g++ -c v1.5.cpp cppFailai/*.cpp -O3
clean :
	del main.exe *.o
