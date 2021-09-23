output: principal.o tablero.o casillero.o
	g++ -ansi -pedantic -std=c++98 principal.o tablero.o casillero.o -o tateti
	rm *.o

principal.o:principal.cpp
	g++ -c principal.cpp

tablero.o: tablero.cpp tablero.h
	g++ -c tablero.cpp		

casillero.o: casillero.cpp casillero.h
	g++ -c casillero.cpp		
