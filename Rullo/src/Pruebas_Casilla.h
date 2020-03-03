/*
 * Pruebas_Casilla.h
 *
 *  Created on: 10 ene. 2019
 *      Author: Rubén Costa Barriga
 */

#ifndef PRUEBAS_CASILLA_H_
#define PRUEBAS_CASILLA_H_
#include <iostream>
using namespace std;

#include "Casilla.h"
#include"entorno.h"

/*
 * POST: Modulo de prueba para iniciar,
 * para esto iniciamos una casilla y comprobamos que este vacia, sin valor, desactivada, desbloqueada.
 * COMPLEJIDAD:O(1)
 */
void prueba_iniciar();

/*
 * POST: Modulo de prueba para ponerValor,
 * para esto iniciamos una casilla ,le introducimos un valor y comprovamos que se ha puesto el valor.
 * COMPLEJIDAD:O(1)
 */

void prueba_ponerValor();

/*
 * POST: Modulo de prueba para activado,
 * para esto iniciamos una casilla ,la activamos y comprobamos que esta activada.
 * COMPLEJIDAD:O(1)
 */
void prueba_activado();

/*
 * POST: Modulo de prueba para activarTodoCasilla,
 * para esto iniciamos una casilla ,la activamos y comprobamos que esta actiada.
 * COMPLEJIDAD:O(1)
 */
void prueba_activarTodoCasilla();

/*
 * POST: Modulo de prueba para desactivarTodoCasilla,
 * para esto iniciamos una casilla ,la desactivamos y comprobamos que esta desactivada.
 * COMPLEJIDAD:O(1)
 */
void prueba_desactivarTodoCasilla();

/*
 * POST: Modulo de prueba para bloqueo,
 * para esto iniciamos una casilla,la bloqueamos y comprobamos que esta bloqueada.
 * COMPLEJIDAD:O(1)
 */
void prueba_bloqueo();

/*
 * POST: Modulo de prueba para obtenerValorCasilla,
 * para esto iniciamos una casilla,le introducimos un valor y comprobamos que nos devuelve ese valor.
 * COMPLEJIDAD:O(1)
 */
void prueba_obtenerValorCasilla();

/*
 * POST: Modulo de prueba para obtenerActivadoCasilla,
 * para esto iniciamos una casilla ,la activamos y comprobamos nos devuelve que esta activada.
 * COMPLEJIDAD:O(1)
 */
void prueba_obtenerActivadoCasilla();

/*
 * POST: Modulo de prueba para obtenerBloqueoCasilla,
 * para esto iniciamos una casilla,la bloqueamos y comprobamos que este bloqueada.
 * COMPLEJIDAD:O(1)
 */
void prueba_obtenerBloqueoCasilla();

/*
 * POST: Modulo de prueba para pruebas_casillas,
 * Junta todos los modulos de prueba.
 * COMPLEJIDAD:O(1)
 */
void pruebas_casillas();



#endif /* PRUEBAS_CASILLA_H_ */
