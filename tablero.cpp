#include <iostream>
#include <fstream>
#include <string>

#include "tablero.h"
#include "casillero.h"

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

void imprimirTablero(Tablero * tablero, std::string archivoSalida){
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
			delete tablero -> casilleros[i][j];
		}
	}
	delete[] tablero -> casilleros;
	delete tablero;
	tablero = NULL;
}

void asignarFicha(Tablero * tablero, int x, int y, char ficha){
	if( (x >= ALTO || x < 0) || (y >= ANCHO || y < 0)){
		throw string("Posicion invalida");
	}
	asignarFicha(tablero -> casilleros[x][y], ficha);
}

void asignarFicha(Casillero * casillero, char ficha){
	if(casillero -> valor != '-'){
		throw string("El casillero esta ocupado");
	}
	casillero -> valor = ficha;
}
