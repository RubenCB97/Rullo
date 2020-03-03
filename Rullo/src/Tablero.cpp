/*
 * Tablero.cpp
 *
 * Created on: 30 nov. 2018
 * Author: Rubén Costa Barriga
 */
#include "Tablero.h"

void iniciarAleatorio(Tablero &t, int dimensionReal, int cargarDeFichero) { //Inicia un tablero con datos aleatorio con el tamaño dado

	int contador = 0;
	int filaRand, colRand, aleatorio = 0;

	srand(time(NULL));
	t.dimReal = dimensionReal;

	for (int i = 0; i < t.dimReal; i++) {
		for (int j = 0; j < t.dimReal; j++) {
			iniciar(t.matrizTablero[i][j]); //Inicia toda el tablero

			//Coloca los valores en el tablero

			aleatorio = rand() % 9 + 1;
			cambiarValor(t, i, j, aleatorio);
			cambiarActivado(t, i, j);

		}
	}
	while (contador < cargarDeFichero) {
		filaRand = rand() % dimensionReal;
		colRand = rand() % dimensionReal;
		if (obtenerActivado(t, filaRand, colRand) == true) {
			cambiarActivado(t, filaRand, colRand);
			contador = contador + 1;
		}

	}

	for (int i = 0; i < t.dimReal; i++) { //Colocamos en los vect
		t.sumaFila[i] = obtenerSumaCol(t, i);
		t.sumaCol[i] = obtenerSumaFila(t, i);

	}

	for (int i = 0; i < t.dimReal; i++) { //Pone  el tablero funcional por el cual nos moveremos activado
		for (int j = 0; j < t.dimReal; j++) {
			activarTodo(t, i, j);
		}
	}
}
void iniciarConfg(Tablero &t, int dimensionReal, TipoMatriz m,
		TipoVector vSumaFilas, TipoVector vSumaCol) { //Inicia un tablero con los datos obtenidos del fichero
	t.dimReal = dimensionReal;

	for (int i = 0; i < t.dimReal; i++) {
		for (int j = 0; j < t.dimReal; j++) {
			iniciar(t.matrizTablero[i][j]); //Inicia toda la matriz

			cambiarValor(t, i, j, m[i][j]);	//Coloca en el tablero funcional con las casillas activadas con su valor
			activarTodo(t, i, j);

		}
		t.sumaFila[i] = vSumaFilas[i]; //Colocamos en los vectores la suma de filas y la suma de columnas
		t.sumaCol[i] = vSumaCol[i];

	}

}

int obtenerTam(Tablero &t) { //Obtiene el tamaño del tablero

	return t.dimReal;

}

void cambiarValor(Tablero &t, int fila, int col, int valor) { //Cambia el valor de la casilla en la que estemos
	ponerValor(t.matrizTablero[fila][col], valor);

}

void cambiarActivado(Tablero &t, int fila, int col) { //Alterna entre activado o desactivado en la casilla en la que estemos
	activado(t.matrizTablero[fila][col]);

}
void activarTodo(Tablero &t, int fila, int col) { //Activa la casilla en la que estamos
	activarTodoCasilla(t.matrizTablero[fila][col]);
}
void desactivarTodo(Tablero &t, int fila, int col) { //Desactiva la casilla en la que estamos
	desactivarTodoCasilla(t.matrizTablero[fila][col]);
}

void cambiarBloqueado(Tablero &t, int fila, int col) { //Alterna entre bloqueado o desbloqueado en la casilla en la que estemos
	bloqueo(t.matrizTablero[fila][col]);

}

int obtenerValor(Tablero &t, int fila, int col) { //Obtiene el valor de una casilla

	return obtenerValorCasilla(t.matrizTablero[fila][col]);
}
int obtenerValorResFila(Tablero&t, int i) { //obtiene el valor del vector

	return t.sumaFila[i];

}

int obtenerValorResCol(Tablero&t, int i) { //obtiene el valor del vector
	return t.sumaCol[i];
}

bool obtenerActivado(Tablero &t, int fila, int col) { //Devuelve si esta activado o no una casilla
	return obtenerActivadoCasilla(t.matrizTablero[fila][col]);
}

bool obtenerBloqueado(Tablero &t, int fila, int col) { //Devuelve si esta bloqueada o no una casilla
	return obtenerBloqueoCasilla(t.matrizTablero[fila][col]);
}

int obtenerSumaFila(Tablero t, int col) { //Devuelve la suma de la fila deseada
	int conti = 0;

	for (int i = 0; i < t.dimReal; i++) {
		if (obtenerActivado(t, i, col) == true) {

			conti = conti + obtenerValor(t, i, col);

		}

	}

	return conti;
}

int obtenerSumaCol(Tablero t, int fila) { //Devuelve la suma de las col deseada
	int contj = 0;

	for (int j = 0; j < t.dimReal; j++) {
		if (obtenerActivado(t, fila, j) == true) {
			contj = contj + obtenerValor(t, fila, j);

		}

	}

	return contj;
}

bool resuelto(Tablero &t) { //Comprueba si esta resuelto el juego
	bool result = true;

	for (int i = 0; i < t.dimReal && result; i++) {
		if (obtenerSumaCol(t, i) != t.sumaFila[i]) {
			result = false;
		}

	}
	for (int j = 0; j < t.dimReal && result; j++) {
		if (obtenerSumaFila(t, j) != t.sumaCol[j]) {
			result = false;
		}

	}

	return result;
}

