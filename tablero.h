#ifndef TABLERO_H_
#define TABLERO_H_

#include "casillero.h"

#define ANCHO  3
#define ALTO 3

typedef struct{
	Casillero *** casilleros;
	int ancho;
	int alto;
} Tablero;

Tablero * inicializarTablero();
void imprimirTablero(Tablero * tablero, std::string archivoSalida);
void destruirTablero(Tablero * tablero);
void asignarFicha(Tablero * tablero, int x, int y, char ficha);
void asignarFicha(Casillero * casillero, char ficha);
void quitarFicha(Tablero * tablero, int x, int y, char ficha);
void quitarFicha(Casillero * casillero, char ficha);
void moverFicha(Tablero * tablero, int x, int y, int xInicial, int yInicial, char ficha);
bool verificarGanador(Tablero* tablero, int x, int y, char ficha);
bool verificarColumna(Tablero* tablero, int x, int y, char ficha);
bool verificarFila(Tablero* tablero, int x, int y, char ficha);
bool verificarDiagonal(Tablero* tablero, int x, int y, char ficha);
bool verificarAntiDiagonal(Tablero* tablero, int x, int y, char ficha);
void imprimirGanador(char ficha);

#endif /* TABLERO_H_ */
