/*
 * Pruebas_Casilla.cpp
 *
 *  Created on: 10 ene. 2019
 *      Author: Rubén Costa Barriga
 */

#include "Pruebas_Casilla.h"

#include <iostream>
using namespace std;

void prueba_iniciar() {

	cout << "P_iniciar" << endl;
	Casilla c;
	iniciar(c);

	if (obtenerActivadoCasilla(c) != false && obtenerBloqueoCasilla(c) != false
			&& obtenerValorCasilla(c) != 0 && c.ocupada != 0) {
		cout << "error en iniciar la casilla" << endl;
	}

}

void prueba_ponerValor() {
	cout << "P_ponerValor" << endl;
	Casilla c;
	iniciar(c);
	ponerValor(c, 15);

	if (obtenerValorCasilla(c) != 15) {
		cout << "error en ponerValor" << endl;
	}
}

void prueba_activado() {
	cout << "P_activado" << endl;
	Casilla c;
	iniciar(c);
	activado(c);

	if (obtenerActivadoCasilla(c) != true) {
		cout << "error en activado" << endl;
	}
}

void prueba_activarTodoCasilla() {
	cout << "P_activarTodoCasilla" << endl;
	Casilla c;
	iniciar(c);
	activarTodoCasilla(c);

	if (obtenerActivadoCasilla(c) != true) {
		cout << "error en activarTodoCasilla" << endl;
	}
}

void prueba_desactivarTodoCasilla() {
	cout << "P_desactivarTodoCasilla" << endl;
	Casilla c;
	iniciar(c);
	desactivarTodoCasilla(c);

	if (obtenerActivadoCasilla(c) != false) {
		cout << "error en desactivarTodoCasilla" << endl;
	}
}

void prueba_bloqueo() {
	cout << "P_bloqueo" << endl;
	Casilla c;
	iniciar(c);
	bloqueo(c);

	if (obtenerBloqueoCasilla(c) != 1) {
		cout << "error en bloqueo" << endl;
	}
}

void prueba_obtenerValorCasilla() {
	cout << "P_obtenerValorCasilla" << endl;
	Casilla c;
	iniciar(c);
	ponerValor(c, 15);

	if (obtenerValorCasilla(c) != 15) {
		cout << "error en ponerValor" << endl;
	}
}

void prueba_obtenerActivadoCasilla() {
	cout << "P_obtenerActivadoCasilla" << endl;
	Casilla c;
	iniciar(c);
	activado(c);

	if (obtenerActivadoCasilla(c) != true) {
		cout << "error en obtenerActivadoCasilla" << endl;
	}
}

void prueba_obtenerBloqueoCasilla() {
	cout << "P_obtenerBloqueoCasilla" << endl;
	Casilla c;
	iniciar(c);
	bloqueo(c);

	if (obtenerBloqueoCasilla(c) != true) {
		cout << "error en obtenerBloqueoCasilla" << endl;
	}
}

void pruebas_casillas() {
	cout << "Inicio de Pruebas Casillas" << endl;
	prueba_iniciar();
	prueba_ponerValor();
	prueba_activado();
	prueba_activarTodoCasilla();
	prueba_desactivarTodoCasilla();
	prueba_bloqueo();
	prueba_obtenerValorCasilla();
	prueba_obtenerActivadoCasilla();
	prueba_obtenerBloqueoCasilla();
	cout << "Fin de Pruebas Casillas" << endl;
}

