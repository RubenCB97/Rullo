/*
 * juego.h
 *
 *  Created on: 3 dic. 2018
 *      Author: Rubén Costa Barriga
 */

#ifndef JUEGO_H_
#define JUEGO_H_
#include "entorno.h"
#include <iostream>
using namespace std;
#include "Tablero.h"

struct Juego {
	Tablero tablero;
	int numMvtos;
};

/*
 * PRE=: Existe juego y esta inicializado
 * POST: Controla el juego,las teclas pulsadas, los movimientos usados,...
 * COMPLEJIDAD:O(n)
 */
void gestionJuego(Juego &J);
/*
 * PRE=: Existe juego
 * POST: Inicia el juego con los valores de el archivo de configuracion dependiendo del archivo rullo ,inicia el entorno y
 * pinta el tablero en el entorno
 * COMPLEJIDAD:O(1)
 */
bool iniciarJuego(Juego &J);
/*
 * PRE=: Existe juego y esta inicializado
 * POST: Comprueba que el juego ha sido terminado, lanza un mensaje  y termina el entorno
 * COMPLEJIDAD:O(1)
 */

void finalizarJuego(Juego &J);
/*
 * PRE=: Existe juego
 * POST: Pinta el tablero en el entorno
 * COMPLEJIDAD:O(n²)
 */
void pintarJuego(Juego &J);

#endif /* JUEGO_H_ */
