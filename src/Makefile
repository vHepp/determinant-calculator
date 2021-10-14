a.out: main.o determinant.o fraction.o
	g++ -o a.out main.o determinant.o fraction.o

main.o: main.cpp determinant.hpp
	g++ -c main.cpp

determinant.o: determinant.cpp determinant.hpp
	g++ -c determinant.cpp

fraction.o: fraction.cpp fraction.hpp
	g++ -c fraction.cpp