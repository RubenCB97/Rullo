/*
 * Tablero.h
 *
 * Created on: 30 nov. 2018
 * Author: Rubén Costa Barriga
 */

#ifndef TABLERO_H_
#define TABLERO_H_
#include <cstdlib>
#include <iostream>
#include "entorno.h"
#include "Casilla.h"
const int MAX = 8;

typedef int TipoVector[MAX];
typedef int TipoMatriz[MAX][MAX];
typedef Casilla MatrizTablero[MAX][MAX];
struct Tablero {
	MatrizTablero matrizTablero;
	int dimReal;
	TipoVector sumaFila;
	TipoVector sumaCol;

};

/*
 * PRE=: dimenionReal>3 , numMvtos>0
 * POST: Dado el tamaño, inicia un tablero aleatorio
 * COMPLEJIDAD:O(n²)
 */
void iniciarAleatorio(Tablero &t, int dimensionReal,int cargarDeFichero);

/*
 * PRE=: dimenionReal>3 , numMvtos>0
 * POST: Dado el tamaño, inicia el tablero con la configuracion del archivo RULLO
 * COMPLEJIDAD:O(n²)
 */
void iniciarConfg(Tablero &t, int dimensionReal,TipoMatriz m, TipoVector vSumaFilas,
		TipoVector vSumaCol);

/*
 * PRE=: Tablero iniciado
 * POST: Devuelve el tamañaño del tablero
 * COMPLEJIDAD:O(1)
 */
int obtenerTam(Tablero &t);

/*
 * PRE=: Tablero iniciado, valor>0,fila>=0,Col>=0
 * POST: Cambia un valor en la posicion introducida
 * COMPLEJIDAD:O(1)
 */
void cambiarValor(Tablero &t, int fila, int col, int valor);

/*
 * PRE=: Tablero iniciado, fila>=0,Col>=0
 * POST: Cambia el estado de activada de la posicion introducida
 * COMPLEJIDAD:O(1)
 */
void cambiarActivado(Tablero &t, int fila, int col);

/*
 * PRE=: Tablero iniciado, fila>=0,Col>=0
 * POST: activa la casilla de la posicion introducida
 * COMPLEJIDAD:O(1)
 */

void activarTodo(Tablero &t , int fila ,int col);

/*
 * PRE=: Tablero iniciado, fila>=0,Col>=0
 * POST: Cambia el estado de bloqueo de la posicion introducida
 * COMPLEJIDAD:O(1)
 */
void cambiarBloqueado(Tablero &t, int fila, int col);

/*
 * PRE=: Tablero iniciado,fila>=0,Col>=0
 * POST: Obtiene el valor de la posicion introducida
 * COMPLEJIDAD:O(1)
 */

int obtenerValor(Tablero &t, int fila, int col);

/*
 * PRE=: Tablero iniciado, fila>=0,Col>=0
 * POST: Desactiva la casilla  de la posicion introducida
 * COMPLEJIDAD:O(1)
 */

void desactivarTodo(Tablero &t , int fila ,int col);
/*
 * PRE=: Tablero iniciado, i>=0
 * POST: Obtiene el valor del vector
 * COMPLEJIDAD:O(1)
 */


int obtenerValorResFila(Tablero&t ,int i);
/*
 * PRE=: Tablero iniciado, i>=0
 * POST: Obtiene el valor del vecotr
 * COMPLEJIDAD:O(1)
 */

int obtenerValorResCol(Tablero&t ,int i);
/*
 * PRE=: Tablero iniciado,fila>=0,Col>=0
 * POST: Devuelve el estado de actiada de la posicion introducida
 * COMPLEJIDAD:O(1)
 */
bool obtenerActivado(Tablero &t, int fila, int col);

/*
 * PRE=: Tablero iniciado,fila>=0,Col>=0
 * POST: Devuelve el estado de bloqueada de la posicion introducida
 * COMPLEJIDAD:O(1)
 */

bool obtenerBloqueado(Tablero &t, int fila, int col);

/*
 * PRE=: Tablero iniciado,Col>=0
 * POST: Obtiene la suma de las casillas activadas en la fila
 * COMPLEJIDAD:O(n)
 */

int obtenerSumaFila(Tablero t, int col);

/*
 * PRE=: Tablero iniciado,Fila>=0
 * POST: Obtiene la suma de las casillas activadas en la columna
 * COMPLEJIDAD:O(n)
 */
int obtenerSumaCol(Tablero t, int fila);

/*
 * PRE=: Tablero iniciado
 * POST: Comrueba si la suma de las casillas activadas son iguales a los resultados
 * COMPLEJIDAD:O(n²)
 */

bool resuelto(Tablero &t);

#endif /* TABLERO_H_ */
