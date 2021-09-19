#ifndef TABLERO_H_
#define TABLERO_H_

#include <string>
#include "casillero.h"

#define ANCHO  3
#define ALTO 3
#define MAXFICHAS 6 // MAXFICHAS = cantidad de jugadores * 3

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
#endif /* TABLERO_H_ */
