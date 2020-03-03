/*
 * Pruebas_Tablero.cpp
 *
 *  Created on: 10 ene. 2019
 *      Author: Rubén Costa Barriga
 */

#include <iostream>
using namespace std;
const int MAX2= 8;
typedef int TipoVector [MAX2];
typedef int TipoMatriz [MAX2][MAX2];

#include"Pruebas_Tablero.h"


void P_iniciarAleatorio(){
	cout<<"P_iniciarAleatorio"<<endl;

	Tablero t;
	iniciarAleatorio(t, 7,4);

	for (int i = 0; i < obtenerTam(t); i++) {
		for (int j = 0; j < obtenerTam(t); j++) {
			if(t.dimReal!= 7 || obtenerActivado(t, i, j)!= true){
				cout<< "Error en iniciar aleatorio" << endl;
			}
		}
	}
}

void P_iniciarConfg(){
	cout<<"P_iniciarConfg"<<endl;
	TipoMatriz m;
	TipoVector vSumaFilas,vSumaCol;
	Tablero t;
	iniciarConfg(t, 4, m, vSumaFilas, vSumaCol);

	for (int i = 0; i < obtenerTam(t); i++) {
		for (int j = 0; j < obtenerTam(t); j++) {
			if(t.dimReal!= 4 || obtenerActivado(t, i, j)!= true){
				cout<< "Error en iniciarConfg" << endl;
			}
		}
	}

}

void P_obtenerTam(){
	cout<<"P_obtenerTam"<<endl;

	Tablero t;
	iniciarAleatorio(t, 4,4);

			if(obtenerTam(t)!=4){
				cout<< "Error en obtenerTam" << endl;
			}
		}

void P_cambiarValor(){
	cout<<"P_cambiarValor"<<endl;

	Tablero t;
	iniciarAleatorio(t, 4,4);
	cambiarValor(t, 0, 0, 5);

			if(obtenerValor(t, 0, 0)!=5){
				cout<< "Error en cambiarValor" << endl;
			}
		}



void P_cambiarActivado(){
	cout<<"P_cambiarActivado"<<endl;

	Tablero t;
	iniciarAleatorio(t, 7,4);
	cambiarActivado(t, 0, 0);

			if(obtenerActivado(t, 0, 0)!=0){
				cout<< "Error en cambiarActivado" << endl;
			}
		}



void P_activarTodo(){
	cout<<"P_activarTodo"<<endl;

	Tablero t;
	iniciarAleatorio(t, 5,4);
	activarTodo(t, 2, 2);


			if(obtenerActivado(t, 2, 2)!=1){
				cout<< "Error en activarTodo" << endl;
			}
		}



void P_cambiarBloqueado(){
	cout<<"P_cambiarBloqueado"<<endl;

	Tablero t;
	iniciarAleatorio(t, 5,4);
	cambiarBloqueado(t, 2, 1);


			if(obtenerBloqueado(t, 2, 1)!=1){
				cout<< "Error en cambiarBloqueado" << endl;
			}
}

void P_obtenerValor(){
	cout<<"P_obtenerValor"<<endl;

	Tablero t;
	iniciarAleatorio(t, 4,4);
	cambiarValor(t, 0, 0, 5);

			if(obtenerValor(t, 0, 0)!=5){
				cout<< "Error en obtenerValor" << endl;
			}

}

void P_desactivarTodo(){
	cout<<"P_desactivarTodo"<<endl;

	Tablero t;
	iniciarAleatorio(t, 6,4);
	desactivarTodo(t, 4, 3);


			if(obtenerActivado(t, 4, 3)!=0){
				cout<< "Error en desactivarTodo" << endl;
			}

}

void P_obtenerActivado(){
	cout<<"P_obtenerActivado"<<endl;

	Tablero t;
	iniciarAleatorio(t, 6,4);
	activarTodo(t, 3, 4);


			if(obtenerActivado(t, 3, 4)!=1){
				cout<< "Error en obtenerActivado" << endl;
			}

}

void P_obtenerBloqueado(){
	cout<<"P_obtenerBloqueado"<<endl;

	Tablero t;
	iniciarAleatorio(t, 5,4);


			if(obtenerBloqueado(t, 2, 1)!=0){
				cout<< "Error en obtenerBloqueado" << endl;
			}

}

void P_obtenerSumaFila(){ //Para poder probarlo bien es necesario configurar tambien el archivo rullo con la informacion deseada(tam=4)
	cout<<"P_obtenerSumaFila"<<endl;
	TipoVector vSumaFilas,vSumaCol;
	TipoMatriz m;
	Tablero t;
	int tamano,cargarDeFichero,numMvtos,nivel;
	entornoCargarConfiguracion(tamano, cargarDeFichero, numMvtos, nivel, m, vSumaFilas, vSumaCol);
	iniciarConfg(t, 4, m, vSumaFilas, vSumaCol);



			if(obtenerSumaFila(t, 0)!=16){
				cout<< "Error en obenerSumaFila" << endl;
			}

}

void P_obtenerSumaCol(){ //Para poder probarlo bien es necesario configurar tambien el archivo rullo con la informacion deseada(tam=4)
	cout<<"P_obtenerSumaCol"<<endl;
	TipoVector vSumaFilas,vSumaCol;
	TipoMatriz m;
	Tablero t;

	int tamano,cargarDeFichero,numMvtos,nivel;
	entornoCargarConfiguracion(tamano, cargarDeFichero, numMvtos, nivel, m, vSumaFilas, vSumaCol);
	iniciarConfg(t, 4, m, vSumaFilas, vSumaCol);



			if(obtenerSumaCol(t, 0)!=11){
				cout<< "Error en obtenerSumaCol" << endl;
			}

}

void P_resuelto(){ //Para poder probarlo bien es necesario configurar tambien el archivo rullo con la informacion deseada(tam=4)
	cout<<"P_resuelto"<<endl;
	TipoVector vSumaFilas,vSumaCol;
	TipoMatriz m;
	Tablero t;

	int tamano,cargarDeFichero,numMvtos,nivel;
	entornoCargarConfiguracion(tamano, cargarDeFichero, numMvtos, nivel, m, vSumaFilas, vSumaCol);
	iniciarConfg(t, 4, m, vSumaFilas, vSumaCol);
	desactivarTodo(t,2, 0);
	desactivarTodo(t, 3, 1);
	desactivarTodo(t, 2, 3);
	desactivarTodo(t, 1, 2);

	for (int i = 0; i < t.dimReal; i++) {
		if (obtenerSumaCol(t, i) != t.sumaFila[i]) {
			cout <<"Error en pruebas resuelto"<<endl;
		}

	}
	for (int j = 0; j < t.dimReal ; j++) {
		if (obtenerSumaFila(t, j) != t.sumaCol[j]) {
			cout <<"Error en pruebas resuelto"<<endl;
		}

	}

}

void pruebas_tablero(){
	cout << "Inicio de pruebas tablero" <<endl;
	P_iniciarAleatorio();
	P_iniciarConfg();
	P_obtenerTam();
	P_cambiarValor();
	P_cambiarActivado();
	P_activarTodo();
	P_cambiarBloqueado();
	P_obtenerValor();
	P_desactivarTodo();
	P_obtenerActivado();
	P_obtenerBloqueado();
	P_obtenerSumaFila();
	P_obtenerSumaCol();
	P_resuelto();
	cout << "Fin de pruebas tablero" << endl;


}


