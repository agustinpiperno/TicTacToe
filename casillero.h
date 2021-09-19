#ifndef INCLUDE_CASILLERO_H_
#define INCLUDE_CASILLERO_H_

#include "tablero.h"

typedef struct{
	char valor;
} Casillero;

enum tipoFicha {primeraFicha = 'O', ultimaFicha = 'X'};

Casillero * inicializarCasillero();




#endif /* INCLUDE_CASILLERO_H_ */
