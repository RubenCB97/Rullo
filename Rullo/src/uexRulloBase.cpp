
//============================================================================
// Name        : uexRulloBase.cpp
// Author      : profesores de Introducción a la programación / Fundamentos de programación
// Version     :
// Copyright   : Your copyright notice
// Description : Este proyecto será la base de partida para desarrollar el proyecto de programación uexRullo (curso 18/19)
//               Se incluyen diferentes ficheros de configuración para hacer pruebas con facilidad
//============================================================================

#include "entorno.h"
#include "juego.h"
#include "Pruebas_Casilla.h"
#include "Pruebas_Tablero.h"
#include <iostream>

using namespace std;
typedef int TipoVector [MAX_TAMANO];
typedef int TipoMatriz [MAX_TAMANO][MAX_TAMANO];
void pruebas(){
	cout << "Inicio de pruebas" <<endl;
	pruebas_casillas();
	pruebas_tablero();
	cout << "Fin de pruebas" <<endl;

}
void pruebaEntorno(){
	 //estas variables se necesitan para almacenar la información que se carga desde el fichero de configuración
		int tam;
		int cargarDeFichero, numMvtos, nivel;
		TipoMatriz m;
		TipoVector vSumaFilas, vSumaCol;

		int i,j; //índices para recorrer las posiciones del tablero

		if (entornoCargarConfiguracion (tam, cargarDeFichero, numMvtos, nivel, m, vSumaFilas, vSumaCol)){
			//si los datos del fichero de configuración se han cargado sin problemas, se ejecutan las siguientes instrucciones
			//se inicia el entorno con un tablero del tamaño incluido en la primera línea del fichero de configuración
			entornoIniciar(tam);
			// el siguiente mensaje solo aparece unos segundos en la pantalla
			entornoMostrarMensaje("Tablero lleno de ceros");
			// se colocan ceros en el tablero interior
			for (i=1; i<=tam; i++)
				for (j=1; j<=tam; j++)
					if(m[i-1][j-1]%2==0){
						entornoPonerNumero(i,j,m[i-1][j-1],true);
					}else{
						entornoPonerNumero(i,j,m[i-1][j-1],false);

					}

			entornoPausa (0.5);

			//se coloca el número 99 en la fila 0 y en la columna 0
			//con el formato de los objetivos que el jugador debe alcanzar
			for (i=1; i<=tam; i++){
				entornoPonerResultado(0,i,vSumaCol[i-1],true);
				entornoPonerResultado(i,0,vSumaFilas[i-1],false);
				entornoPonerResultado(tam+1, i,vSumaCol[i-1], true);
				entornoPonerResultado(i, tam+1,vSumaFilas[i-1] , false);
				entornoPausa (0.2);
			}

			entornoMostrarMensajeFin("      Adios      ");
			entornoPausa (1);
			entornoTerminar();
		}
		else cout << "Error al intenar cargar el fichero de configuración";


}

int main() {
	//pruebaEntorno();
	//pruebas();
	Juego partidanueva;
	gestionJuego(partidanueva);

	return 0;
}
