/*
 * juego.cpp
 *
 *  Created on: 3 dic. 2018
 *      Author: Rubén Costa Barriga
 */
#include "juego.h"

void pintarJuego(Juego &J){
	//Pinta los vectores
	for (int i = 1;i<=obtenerTam(J.tablero);i++){
		entornoPonerResultado(0, i, obtenerValorResCol(J.tablero,i-1), false);
		entornoPonerResultado(obtenerTam(J.tablero)+1 , i,obtenerValorResCol(J.tablero,i-1),false);
		entornoPonerResultado(i, 0, obtenerValorResFila(J.tablero,i-1), false);
		entornoPonerResultado(i, obtenerTam(J.tablero)+1 ,obtenerValorResFila(J.tablero,i-1),false);

	//Pinta el tablero
	}
	for(int j = 1 ; j<=obtenerTam(J.tablero);j++){
		for (int i = 1;i<=obtenerTam(J.tablero);i++){
			entornoPonerNumero(i, j, obtenerValor(J.tablero, i-1, j-1), true); //Si es 1 nos coloca una casilla con valor aleatorio desactivada


		}
		}
}
bool iniciarJuego(Juego &J) {
	srand(time(NULL));
	bool iniciar = false; //Bandera
	int tam ; //valor entero
	int cargarDeFichero, numMvtos, nivel; //valor entero
	TipoMatriz m;
	TipoVector vSumaFilas, vSumaCol;
	iniciar = entornoCargarConfiguracion(tam, cargarDeFichero, numMvtos, nivel,
			m, vSumaFilas, vSumaCol);
	J.numMvtos=numMvtos;

	if (iniciar) { //Comprueba si se ha iniciado el entorno de configuracion
		entornoIniciar(tam); //Inicia el entorno con el tamaño dado
		if (cargarDeFichero == 0) { //Si cargarDeFichero es  0 inicia un tablero aleatorio si es 1 inicia el del fichero
			iniciarConfg(J.tablero, tam,  m,
					vSumaFilas, vSumaCol);

		} else {
			iniciarAleatorio(J.tablero, tam,cargarDeFichero);
		}

	}
	pintarJuego(J);

	return iniciar;
}

void gestionJuego(Juego &J) {
	bool salir;
	int filaent = 1;
	int colent=1;
	int cont = 0;

	if (iniciarJuego(J)) {
		entornoMarcarPosicion(filaent, colent);

	}
	TipoTecla Tecla; //Teclas para usar en el juego
	string mensaje; //Mensaje final del juego cuando es completado

	salir = false;

	while (!salir && cont!=J.numMvtos) {
		//Compara lo resultados y los actualiza

		bool comprobacion = obtenerSumaFila(J.tablero, colent-1) == obtenerValorResCol(J.tablero,colent-1);//sutituir obtenervalor
		//FILA ARRIBA
		entornoQuitarResultado(0, colent);
		entornoPonerResultado(0, colent, obtenerValorResCol(J.tablero,colent-1),comprobacion);
		//FILA ABAJO
		entornoQuitarResultado(obtenerTam(J.tablero)+1, colent);
		entornoPonerResultado(obtenerTam(J.tablero)+1, colent, obtenerValorResCol(J.tablero,colent-1),comprobacion);



		comprobacion = obtenerSumaCol(J.tablero, filaent-1) == obtenerValorResFila(J.tablero,filaent-1);
		//FILA IZQUIERDA
		entornoQuitarResultado(filaent, 0);
		entornoPonerResultado(filaent, 0, obtenerValorResFila(J.tablero,filaent-1), comprobacion);
		//FILA DERECHA
		entornoQuitarResultado(filaent, obtenerTam(J.tablero)+1 );
		entornoPonerResultado(filaent, obtenerTam(J.tablero)+1 , obtenerValorResFila(J.tablero,filaent-1), comprobacion);

		entornoPonerNumJugadas(J.numMvtos-cont);
		finalizarJuego(J);

	Tecla = entornoLeerTecla();
		switch (Tecla) {
		case TEnter:

			if (obtenerBloqueado(J.tablero, filaent-1, colent-1) != true) {    //Comprueba si esta bloqueado / no bloqueado

				if (obtenerActivado(J.tablero, filaent-1, colent-1) == true) { //si esta activada ,bloquea con un color
					entornoPonerBloqueado(filaent, colent, obtenerValor(J.tablero, filaent-1, colent-1), true);
					cambiarBloqueado(J.tablero, filaent-1, colent-1);
					entornoMarcarPosicion(filaent, colent);

				} else {                                                 //si esta desactivada , bloquea con otro color
					entornoPonerBloqueado(filaent, colent, obtenerValor(J.tablero, filaent-1, colent-1), false);
					cambiarBloqueado(J.tablero, filaent-1, colent-1);
					entornoMarcarPosicion(filaent, colent);
				}

			} else {                                                       //Como esta bloqueado aqui desbloquea si esta activado

				if (obtenerActivado(J.tablero, filaent-1, colent-1) == true) {
					entornoPonerNumero(filaent, colent, obtenerValor(J.tablero, filaent-1, colent-1), true);
					cambiarBloqueado(J.tablero, filaent-1, colent-1);
					entornoMarcarPosicion(filaent, colent);

				} else {
					entornoMarcarPosicion(filaent, colent);                     //desbloquea si desactivado
					entornoPonerNumero(filaent, colent, obtenerValor(J.tablero, filaent-1, colent-1), false);
					cambiarBloqueado(J.tablero, filaent-1, colent-1);

				}
			}
			break;
		case TDerecha:
			entornoDesmarcarPosicion(filaent, colent); //Mueve 1 posicion hacia la derecha
			if (colent <obtenerTam(J.tablero)) {
				colent++;

			} else {

				colent = 1;
			}
			entornoMarcarPosicion(filaent, colent);

			break;
		case TIzquierda:
			entornoDesmarcarPosicion(filaent, colent); //Mueve 1 posicion hacia la izquierda
			if (colent >1) {
				colent--;

			} else {

				colent = obtenerTam(J.tablero);
			}
			entornoMarcarPosicion(filaent, colent);

			break;
		case TArriba:
			entornoDesmarcarPosicion(filaent, colent); //Mueve 1 posicion hacia arriba
			if (filaent > 1) {
				filaent--;
			} else {
				filaent = obtenerTam(J.tablero);
			}
			entornoMarcarPosicion(filaent, colent);

			break;
		case TAbajo:
			entornoDesmarcarPosicion(filaent, colent); //Mueve 1 posicion hacia abajo
			if (filaent < obtenerTam(J.tablero)) {
				filaent++;
			} else {
				filaent = 1;
			}
			entornoMarcarPosicion(filaent, colent);
			break;
		case TSPACE:
			if (obtenerBloqueado(J.tablero, filaent-1, colent-1) != true) { //Comprueba si esta bloqueado,si lo está no hace nada

				if (obtenerActivado(J.tablero, filaent-1, colent-1) == true) { //Comprueba si esta activado, si lo esta lo desactiva
					entornoPonerNumero(filaent, colent, obtenerValor(J.tablero, filaent-1, colent-1), false);
					cambiarActivado(J.tablero, filaent-1, colent-1);
					entornoMarcarPosicion(filaent, colent);
					cont = cont +1;
				} else {

					entornoPonerNumero(filaent, colent, obtenerValor(J.tablero, filaent-1, colent-1), true);
					cambiarActivado(J.tablero, filaent-1, colent-1);
					entornoMarcarPosicion(filaent, colent);
					cont = cont +1;
				}
			}

			break;

		case TSalir:
			salir = true; //Termina el programa
			break;
		case TNada:
			break;
		case TY: //Pulsando la tecla y muestra unas soluciones temporales de la sumas
			entornoPonerResultado(obtenerTam(J.tablero)+2, colent, obtenerSumaFila(J.tablero,colent-1), false);
			entornoPonerResultado(filaent, obtenerTam(J.tablero)+2, obtenerSumaCol(J.tablero,filaent-1), false);
			entornoPausa(1.5);
			entornoQuitarResultado(obtenerTam(J.tablero)+2, colent);
			entornoQuitarResultado(filaent, obtenerTam(J.tablero)+2);


			break;
		case TX:
			break;

		}
	}
	if(salir || cont == J.numMvtos){
		mensaje = " Otra vez será!!";
		entornoMostrarMensajeFin(mensaje);
		entornoPausa(1.5);
		entornoTerminar();

	}


}


void finalizarJuego(Juego &J) {
	string mensaje;

	if(resuelto(J.tablero)==true){ //Comprueba si esta resuelto el talbero, si es asi , termina el juego

		mensaje = " Has ganado";
		entornoMostrarMensajeFin(mensaje);
		entornoPausa(1.5);
		entornoTerminar();
}
}


