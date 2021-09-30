output: principal.o tablero.o casillero.o
	g++ -pedantic -std=c++98 principal.o tablero.o casillero.o -o tateti
	rm *.o

principal.o:principal.cpp mensajes.h
	g++ -c principal.cpp

tablero.o: tablero.cpp tablero.h mensajes.h
	g++ -c tablero.cpp		

casillero.o: casillero.cpp casillero.h mensajes.h
	g++ -c casillero.cpp		
