/*
 * Casilla.h
 *
 * Created on: 30 nov. 2018
 * Author: Rubén Costa Barriga
 */

#ifndef CASILLA_H_
#define CASILLA_H_

struct Casilla {
	bool bloqueada;
	int ocupada;
	bool activada;
	int valor;
};

/*
 * POST: inicia la casilla
 * COMPLEJIDAD:O(1)
 */
void iniciar(Casilla &c);

/*
 * PRE=: c.valor = 0 , valor>0
 * POST: Coloca un valor en la casilla
 * COMPLEJIDAD:O(1)
 */
void ponerValor(Casilla &c, int valor);

/*
 * PRE=: Casilla iniciada
 * POST: Cambia de estado activada o desactivada
 * COMPLEJIDAD:O(1)
 */
void activado(Casilla &c);

/*
 * PRE=: Casilla iniciada,c.activada=false
 * POST: activa la casilla
 * COMPLEJIDAD:O(1)
 */

void activarTodoCasilla(Casilla &c);

/*
 * PRE=: Casilla iniciada
 * POST: Varia el estado de bloqueo
 * COMPLEJIDAD:O(1)
 */

void bloqueo(Casilla &c);

/*
 * PRE=: Casilla iniciada ,c.activada=true
 * POST: Desactiva la casilla
 * COMPLEJIDAD:O(1)
 */

void desactivarTodoCasilla(Casilla &c);

/*
 * PRE=: Casilla iniciada
 * POST: Devuelve el valor que tiene la casilla
 * COMPLEJIDAD:O(1)
 */

int obtenerValorCasilla(Casilla &c);

/*
 * PRE=: Casilla iniciada
 * POST: Devuelve sí esta activada o no la casilla
 * COMPLEJIDAD:O(1)
 */

bool obtenerActivadoCasilla(Casilla &c);

/*
 * PRE=: Casilla iniciada
 * POST: Devuelve sí esta bloqueada o no la casilla
 * COMPLEJIDAD:O(1)
 */

bool obtenerBloqueoCasilla(Casilla &c);

#endif /* CASILLA_H_ */
