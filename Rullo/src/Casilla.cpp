/*
 * Casilla.cpp
 *
 * Created on: 30 nov. 2018
 * Author: Rubén Costa Barriga
 */
 //Guardamos en cada casilla: Valor,Activo y bloqueado.

#include "Casilla.h"



void iniciar(Casilla &c){
	c.ocupada = 0;
	c.bloqueada = false;
	c.activada = false;
	c.valor=0;
}

void ponerValor(Casilla &c, int valor){
	c.valor = valor;
	c.ocupada = 1;
}

void activado(Casilla &c){
	if(c.activada ==false){
		c.activada = true;
	}else{
		c.activada = false;
}
}
void activarTodoCasilla(Casilla &c){
	c.activada=true;
}
void desactivarTodoCasilla(Casilla &c){
	c.activada = false;
}

void bloqueo(Casilla &c){
	if(c.bloqueada == false){
	c.bloqueada = true;
	}else{
	c.bloqueada = true;
}
}


int obtenerValorCasilla(Casilla &c){

	if(c.ocupada!=0)
		return c.valor;

	return 0;

}

bool obtenerActivadoCasilla(Casilla &c){
	bool act = false;
	if(c.activada == true){
		act =true;
	}
	return act;
}


bool obtenerBloqueoCasilla(Casilla &c){
	bool bloq = false;
	if(c.bloqueada==true){
		bloq= true;
	}
	return bloq;
}
