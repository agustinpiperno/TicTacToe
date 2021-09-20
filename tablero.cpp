#include <iostream>
#include <fstream>
#include <string>

#include "tablero.h"
#include "casillero.h"
#include "mensajes.h"

using namespace std;

Tablero * inicializarTablero(){
	Tablero * tablero = new Tablero();
	tablero -> ancho = ANCHO;
	tablero -> alto = ALTO;
	tablero -> casilleros = new Casillero**[ALTO];
	for(int z= 0; z < ALTO; z++){
		tablero -> casilleros[z] = new Casillero*[ANCHO];
	}
	for(int i = 0; i < ANCHO; i++){
		for(int j = 0; j < ALTO; j++){
			tablero -> casilleros[i][j] = inicializarCasillero();
		}
	}
	return tablero;
}

void imprimirTablero(Tablero * tablero, string archivoSalida){
	ofstream salida;
	salida.open(archivoSalida.c_str());

	for(int i = 0; i < ALTO; i++){
		salida << std::endl;
		cout << std::endl;
		for(int j= 0; j < ANCHO; j++){
			salida << tablero -> casilleros[i][j] -> valor;
			cout << tablero -> casilleros[i][j] -> valor;
		}
	}
	cout << std::endl;
	salida.close();
}

void destruirTablero(Tablero * tablero){
	for(int i = 0; i < ALTO; i++){
		for(int j = 0; j < ANCHO; j++){
			destruirCasillero(tablero -> casilleros[i][j]);
		}
	}
	for(int j= 0; j < ALTO; j++){
		delete[] tablero -> casilleros[j];
	}
	delete[] tablero -> casilleros;
	delete tablero;
	tablero = NULL;
}

void asignarFicha(Tablero * tablero, int x, int y, char ficha){
	if( (x >= ALTO || x < 0) || (y >= ANCHO || y < 0)){
		throw string(MSGPOSINVALIDA);
	}
	asignarFicha(tablero -> casilleros[x][y], ficha);
}

void asignarFicha(Casillero * casillero, char ficha){
	if(casillero -> valor != CASILLEROVACIO){
		throw string(MSGCASILLEROOCUPADO);
	}
	casillero -> valor = ficha;
}

void quitarFicha(Tablero * tablero, int x, int y, char ficha){
	if((x >= ALTO || x < 0) || (y >= ANCHO || y < 0)){
		throw string(MSGPOSINVALIDA);
	}
	if(x == 0 && y == 0){
		if(tablero -> casilleros[x+1][y] -> valor != CASILLEROVACIO
		   && tablero -> casilleros[x][y+1] -> valor != CASILLEROVACIO){
			throw string(MSGFICHABLOQUEADA);
		}
	}
	if(x == 0 && y == ANCHO-1){
			if(tablero -> casilleros[x+1][y] -> valor != CASILLEROVACIO
			   && tablero -> casilleros[x][y-1] -> valor != CASILLEROVACIO){
				throw string(MSGFICHABLOQUEADA);
			}
	}
	if(x == ALTO-1 && y == 0){
			if(tablero -> casilleros[x-1][y] -> valor != CASILLEROVACIO
			   && tablero -> casilleros[x][y+1] -> valor != CASILLEROVACIO){
				throw string(MSGFICHABLOQUEADA);
			}
	}
	if(x == ALTO-1 && y == ANCHO-1){
			if(tablero -> casilleros[x-1][y] -> valor != CASILLEROVACIO
			   && tablero -> casilleros[x][y-1] -> valor != CASILLEROVACIO){
				throw string(MSGFICHABLOQUEADA);
			}
	}
	quitarFicha(tablero -> casilleros[x][y], ficha);
}

void quitarFicha(Casillero * casillero, char ficha){
	if(casillero -> valor != ficha){
		throw string(MSGFICHANOENCONTRADA);
	}
	casillero -> valor = CASILLEROVACIO;
}

void moverFicha(Tablero * tablero, int x, int y, int xInicial, int yInicial, char ficha){
	if( (x >= ALTO || x < 0) || (y >= ANCHO || y < 0)
		|| (x > xInicial+1 || x < xInicial-1)
		|| (y > yInicial+1 || y < yInicial-1)
		|| (x != xInicial && y != yInicial)
		|| (x == xInicial && y == yInicial)
	  ){
		throw string(MSGPOSINVALIDA);
	}
	asignarFicha(tablero -> casilleros[x][y], ficha);
}

bool verificarGanador(Tablero* tablero, int x, int y, char ficha){
	if(verificarColumna(tablero, x, y, ficha) == false){
		return false;
	}
	if(verificarFila(tablero, x, y, ficha) == false){
		return false;
	}
	if(verificarDiagonal(tablero, x, y, ficha) == false){
		return false;
	}
	if(verificarAntiDiagonal(tablero, x, y, ficha) == false){
		return false;
	}
	return true;
}

bool verificarColumna(Tablero* tablero, int x, int y, char ficha){
	for(int i = 0; i < ALTO; i++){
		if(tablero -> casilleros[i][y] -> valor != ficha){
			break;
		}
		if(i == ALTO-1){
			return false;
		}
	}
	return true;
}
bool verificarFila(Tablero* tablero, int x, int y, char ficha){
	for(int j = 0; j < ANCHO; j++){
		if(tablero -> casilleros[x][j] -> valor != ficha){
			break;
		}
		if(j == ANCHO-1){
			return false;
		}
	}
	return true;
}
bool verificarDiagonal(Tablero* tablero, int x, int y, char ficha){
	if(x == y){
		for(int i = 0; i < ALTO; i++){
			if(tablero -> casilleros[i][i] -> valor != ficha){
				break;
			}
			if(i == ALTO-1){
				return false;
			}
		}
	}
	return true;
}
bool verificarAntiDiagonal(Tablero* tablero, int x, int y, char ficha){
	if(x + y == ALTO - 1){
		for(int i = 0; i < ALTO; i++){
			if(tablero -> casilleros[i][(ALTO-1)-i] -> valor != ficha){
				break;
			}
			if(i == ALTO-1){
				return false;
			}
		}
	}
	return true;
}

void imprimirGanador(char ficha){
	cout << MSGGANADOR1 << ficha << MSGGANADOR2 << endl;
}
