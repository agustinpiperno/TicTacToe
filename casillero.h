#ifndef INCLUDE_CASILLERO_H_
#define INCLUDE_CASILLERO_H_

#define CASILLEROVACIO '-'
#define MAXFICHAS 6 // MAXFICHAS = cantidad de jugadores * 3

typedef struct{
	char valor;
} Casillero;

enum tipoFicha {primeraFicha = 'O', ultimaFicha = 'X'};

Casillero * inicializarCasillero();
void destruirCasillero(Casillero * casillero);



#endif /* INCLUDE_CASILLERO_H_ */
