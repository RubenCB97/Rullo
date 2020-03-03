/*
 * Pruebas_Tablero.h
 *
 *  Created on: 10 ene. 2019
 *      Author: Rubén Costa Barriga
 */

#ifndef PRUEBAS_TABLERO_H_
#define PRUEBAS_TABLERO_H_

#include <iostream>
using namespace std;

#include "Tablero.h"
#include"entorno.h"


/*
 * POST: Modulo de prueba para iniciar el tablero de forma aleatoria(),
 * para esto iniciamos una tablero con un tamanio determinado y
 * comprobamos que se ha creado bien
 * COMPLEJIDAD:O(n²)
 */
void P_iniciarAleatorio();

/*
 * POST: Modulo de prueba para iniciar el tablero cargando la configuracion del fichero RULLO(),
 * para esto iniciamos una tablero con un tamanio determinado, cargamos la configuracion y comprobamos
 * que se ha iniciado correctamente.
 * COMPLEJIDAD:O(n²)
 */

void P_iniciarConfg();

/*
 * POST: Modulo de prueba para obtenerTam(),
 * para esto iniciamos una tablero con un tamanio determinado y
 * comprobamos que al obtener el tamanio del tablaro sea el correcto.
 * COMPLEJIDAD:O(1)
 */

void P_obtenerTam();

/*
 * POST: Modulo de prueba para cambiarValor(),
 * para esto iniciamos una tablero con un tamanio determinado e introducimos un valor en
 * una casilla y comprobamos que el valor ha sido introducido correctamente.
 * COMPLEJIDAD:O(1)
 */

void P_cambiarValor();

/*
 * POST: Modulo de prueba para cambiarActivado(),
 * para esto iniciamos una tablero con un tamanio determinado ,activamos una de las casillas y
 * comprobamos que ha sido activada.
 * COMPLEJIDAD:O(1)
 */

void P_cambiarActivado();

/*
 * POST: Modulo de prueba para activarTodo(),
 * para esto iniciamos una tablero con un tamanio determinado ,activamos una de las casillas y
 * comprobamos que ha sido activada.
 * COMPLEJIDAD:O(1)
 */
void P_activarTodo();
/*
 * POST: Modulo de prueba para cambiarBloqueado(),
 * para esto iniciamos una tablero con un tamanio determinado ,bloqueamos una de las casillas y
 * comprobamos que ha sido bloqueada.
 * COMPLEJIDAD:O(1)
 */

void P_cambiarBloqueado();
/*
 * POST: Modulo de prueba para obtenerVAlor(),
 * para esto iniciamos una tablero con un tamanio determinado ,introducimos un valor en una casilla
 * y comprobamos que nos devuelve dicho valor.
 * COMPLEJIDAD:O(1)
 */

void P_obtenerValor();
/*
 * POST: Modulo de prueba para desactivarTodo(),
 * para esto iniciamos una tablero con un tamanio determinado ,desactivamos una de las casillas y
 * comprobamos que ha sido desactivada.
 * COMPLEJIDAD:O(1)
 */

void P_desactivarTodo();
/*
 * POST: Modulo de prueba para obtenerActivado(),
 * para esto iniciamos una tablero con un tamanio determinado ,activamos una de las casillas y
 * comprobamos que nos devuelve que este activada.
 * COMPLEJIDAD:O(1)
 */

void P_obtenerActivado();
/*
 * POST: Modulo de prueba para obtenerBloqueado(),
 * para esto iniciamos una tablero con un tamanio determinado ,bloqueamos una de las casillas y
 * comprobamos que nos devuelve que este bloqueada.
 * COMPLEJIDAD:O(1)
 */


void P_obtenerBloqueado();
/*
 * POST: Modulo de prueba para obtenerSumaFila(),
 * para esto iniciamos una tablero con un tamanio determinado ,cargamos la configuracion del archivo rullo,
 * y comprobaremos si nos devuelve la suma de todas las casillas activadas
 * COMPLEJIDAD:O(1)
 */


void P_obtenerSumaFila();
/*
 * POST: Modulo de prueba para obtenerSumaCol(),
 * para esto iniciamos una tablero con un tamanio determinado ,cargamos la configuracion del archivo rullo,
 * y comprobaremos si nos devuelve la suma de todas las casillas activadas
 * COMPLEJIDAD:O(1)
 */

void P_obtenerSumaCol();
/*
 * POST: Modulo de prueba para obtenerSumaFila(),
 * para esto iniciamos una tablero con un tamanio determinado ,cargamos la configuracion del archivo rullo,
 * y desactivamos las casillas claves para que finalice el juego y comprobamos si ha finalizado bien el juego
 * COMPLEJIDAD:O(1)
 */

void P_resuelto();
/*
 * POST: Modulo que contiene todos los modulos de pruebas(),
 * COMPLEJIDAD:O(1)
 */

void pruebas_tablero();






#endif /* PRUEBAS_TABLERO_H_ */
