#include <iostream>
#include <string>

#include "tablero.h"
#include "casillero.h"

using namespace std;

int main(int argc, char ** argv){
	Tablero * tablero = inicializarTablero();
	int posicionX;
	int posicionY;
	string archivoSalida = "tablero.txt";
	bool preguntarPosicion;
	int cantidadJugadas = 0;
	tipoFicha ficha = primeraFicha; // ficha que juega primera

	while(cantidadJugadas < MAXFICHAS){
		preguntarPosicion = true;
		switch(ficha){
			case primeraFicha:
				cout << "Ingrese una posicion:" << endl;
				while(preguntarPosicion){
					cin >> posicionX;
					cin >> posicionY;
					try{
						asignarFicha(tablero,posicionX,posicionY, ficha);
						preguntarPosicion = false;
				} catch (string&) {
						cout << "La posicion es invalida, ingrese otra posicion" << endl;
					  }
				}
				imprimirTablero(tablero, archivoSalida);
				ficha = ultimaFicha;
				cantidadJugadas++;
			break;

			case ultimaFicha:
				cout << "Ingrese una posicion:" << endl;
				while(preguntarPosicion){
					cin >> posicionX;
					cin >> posicionY;
					try{
						asignarFicha(tablero,posicionX,posicionY, ficha);
						preguntarPosicion = false;
				} catch (string&) {
						cout << "La posicion es invalida, ingrese otra posicion" << endl;
						}
				}
				imprimirTablero(tablero, archivoSalida);
				ficha = primeraFicha;
				cantidadJugadas++;
			break;

			default:
				break;
		}

	}
	imprimirTablero(tablero, archivoSalida);
	destruirTablero(tablero);
	//verificarGanador(tablero);

	return 0;
}


