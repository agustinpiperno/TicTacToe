#include <iostream>
#include <string>

#include "tablero.h"
#include "casillero.h"
#include "mensajes.h"

#define MAXJUGADAS 100

using namespace std;

int main(int argc, char ** argv){
	Tablero * tablero = inicializarTablero();
	int posicionX, posicionY, posicionInicialX, posicionInicialY, cantidadJugadas = 0;
	string archivoSalida = "tablero.txt";
	bool preguntarPosicion, verificar = true;
	tipoFicha ficha = primeraFicha; // ficha que juega primera

	while(verificar && cantidadJugadas < MAXFICHAS){
		preguntarPosicion = true;
		switch(ficha){
			case primeraFicha:
				cout << MSG_INGRESAR_POS << endl;
				while(preguntarPosicion){
					cin >> posicionX;
					cin >> posicionY;
					try{
						asignarFicha(tablero, posicionX, posicionY, ficha);
						preguntarPosicion = false;
					} catch (string &s) {
					cout << s << endl;
					  }
				}
				imprimirTablero(tablero, archivoSalida);
				if(!verificarGanador(tablero, posicionX, posicionY, ficha)){
					imprimirGanador(ficha);
					verificar = false;
				}
				ficha = ultimaFicha;
				cantidadJugadas++;
				break;

			case ultimaFicha:
				cout << MSG_INGRESAR_POS << endl;
				while(preguntarPosicion){
					cin >> posicionX;
					cin >> posicionY;
					try{
						asignarFicha(tablero, posicionX, posicionY, ficha);
						preguntarPosicion = false;
					} catch (string &s) {
					cout << s << endl;
				      }
				}
				imprimirTablero(tablero, archivoSalida);
				if(!verificarGanador(tablero, posicionX, posicionY, ficha)){
					imprimirGanador(ficha);
					verificar = false;
				}
				ficha = primeraFicha;
				cantidadJugadas++;
				break;

			default:
				break;
		}
	}
	while(verificar && cantidadJugadas < MAXJUGADAS){
		preguntarPosicion = true;
		switch(ficha){
			case primeraFicha:
				while(preguntarPosicion){
					cout << MSG_MOVER_POS << endl;
					cin >> posicionInicialX;
					cin >> posicionInicialY;
					try{
						quitarFicha(tablero, posicionInicialX, posicionInicialY, ficha);
						preguntarPosicion = false;
					} catch (string &s){
						cout << s << endl;
					  }
				}
				preguntarPosicion = true;
				while(preguntarPosicion){
					cout << MSG_INGRESAR_POS << endl;
					cin >> posicionX;
					cin >> posicionY;
					try{
						moverFicha(tablero, posicionX, posicionY, posicionInicialX, posicionInicialY, ficha);
						preguntarPosicion = false;
					} catch (string &s){
						cout << s << endl;
					  }
				}
				imprimirTablero(tablero, archivoSalida);
				if(!verificarGanador(tablero, posicionX, posicionY, ficha)){
					imprimirGanador(ficha);
					verificar = false;
				}
				ficha = ultimaFicha;
				break;

			case ultimaFicha:
				while(preguntarPosicion){
					cout << MSG_MOVER_POS << endl;
					cin >> posicionInicialX;
					cin >> posicionInicialY;
					try{
						quitarFicha(tablero, posicionInicialX, posicionInicialY, ficha);
						preguntarPosicion = false;
					} catch (string &s){
						cout << s << endl;
					  }
				}
				preguntarPosicion = true;
				while(preguntarPosicion){
					cout << MSG_INGRESAR_POS << endl;
					cin >> posicionX;
					cin >> posicionY;
					try{
						moverFicha(tablero, posicionX, posicionY, posicionInicialX, posicionInicialY, ficha);
						preguntarPosicion = false;
					} catch (string &s){
						cout << s << endl;
					  }
				}
				imprimirTablero(tablero, archivoSalida);
				if(!verificarGanador(tablero, posicionX, posicionY, ficha)){
					imprimirGanador(ficha);
					verificar = false;
				}
				ficha = primeraFicha;
				break;

			default:
				break;
		}
	}
	destruirTablero(tablero);
	return 0;
}
