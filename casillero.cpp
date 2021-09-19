#include <iostream>
#include "tablero.h"
#include "casillero.h"

Casillero * inicializarCasillero(){
	Casillero * casillero = new Casillero();
	casillero -> valor = '-';
	return casillero;
}
