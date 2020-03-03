/**

	INTRODUCCIÓN A LA PROGRAMACIÓN / FUNDAMENTOS DE PROGRAMACIÓN
	Curso 2018/2019

	Nombre: entorno.h
	Descripción: Especificación del TAD Entorno para el proyecto Rullo
	     	 	 Encargado del manejo de la interfaz del juego.
	     	 	 versión allegro 5
	Autor:	Profesores de las asignaturas
    Fecha:	25/11/2012
    Fecha última modificación: 25/11/2018

*/

#ifndef ENTORNO_H_
#define ENTORNO_H_

#include <string>
using namespace std;
// -------------------------------------------------------------
// Definicion de constantes públicas
// -------------------------------------------------------------

// Dimensiones máximas del tablero
/* La contante MAX_TAMANO define el tamaño máximo (número de filas y columas) del tablero interior,
 * es decir, el que muestra los datos de juego.
 * En el entorno gráfico, a este tablero interior se le añaden dos filas y columnas que lo encierran y
 * que permiten visualizar los objetivos del juego.
 * Además, hay que añadir una última fila y/o columna en la que se pueden visualizar ciertas ayudas (solo en ampliación "Ayuda")
 * Esto hace que el número máximo de filas y columnas del entorno gráfico sea 11, numeradas de 0 a 10.
 */
const int MAX_TAMANO = 8;
// -------------------------------------------------------------
// Definicion de tipos
// -------------------------------------------------------------

/**
 *   Este es el tipo devuelto por la operacion LeerTecla que indica la tecla
 *   de los cursores o teclas válidas que se ha pulsado
 */
enum TipoTecla {TNada, TEnter, TIzquierda, TDerecha, TArriba, TAbajo, TSalir, TSPACE, TY, TX};




// -------------------------------------------------------------
// Declaración de interfaz (módulos) PÚBLICA
// -------------------------------------------------------------


 /*
  *	PRE:  4 <= tam <= 8, (es el número de filas y columnas de la matriz interior)
  *	POST: Inicia la pantalla gráfica de juego,
  *	      es necesario conocer el valor de "tam" para poder centrar la matriz en la ventana gráfica
  */
void entornoIniciar (int tam);


 /*
  *	POST: Libera los recursos usados por el entorno gráfico
  */
void entornoTerminar ();


/*
  *	PRE: Archivo rullo.cnf correcto y en la carpeta raíz del proyecto
  *	     (NO SE COMPRUEBAN ERRORES EN LOS DATOS)
  *	POST: Devuelve:
  *	         TRUE:  si se carga correctamente la configuración del juego,
  *		     FALSE: en caso contrario.
  *   PARÁMETROS:
  *		Si la configuración se lee de forma correcta se devolverá:
  *		   tamano:		     número de filas y columnas del tablero del juego
  *		   cargarDeFichero:  si vale 0 el tablero se lee desde el fichero de configuración
  *		   					 si es positivo (>0) el tablero se generará aleatoriamente
  *		   					 teniendo en cuenta que ese número indica cuántas celdas habrá que desactivar
  *		   					 para conseguir los objetivos
  *		   numMvtos:		 número máximo de jugadas. Solo para la ampliación "Máximo de jugadas"
  *		   nivel:			 tendrá el valor 1, 2 o 3 que indica el grado de dificultad del tablero. Solo para la ampliación "Inicio"
  *		   m:				 matriz que contiene los valores numéricos del tablero del juego. Solo si cargarDeFichero es 0.
  *		   vSumaFilas:		 contiene la suma de las filas del tablero de juego. Solo si cargarDeFichero es 0.
  *		   vSumaCol:		 contiene la suma de las columnas del tablero de juego. Solo si cargarDeFichero es 0.
  *
  *		Por omisión, el archivo rullo.cnf se encuentra en el directorio  del proyecto
  */
bool entornoCargarConfiguracion ( int &tamano, int &cargarDeFichero, int &numMvtos, int &nivel, int m[MAX_TAMANO][MAX_TAMANO],
		int vSumaFilas[MAX_TAMANO], int vSumaCol[MAX_TAMANO]);


/*
  * PRE: { 0 <= fila <= 10 }
  *      { 0 <= columna <= 10 }
  *      { 1 <=  num <= 9 }
  * POST: Coloca en la posición (fila,columna) del tablero el valor "num" encerrado en un círculo.
  *       El color de fondo depende del valor de "activado"
  *       Si activado es true, el color del fondo es rojo indicando que la celda está activada.
  *       En caso contrario, el color del fondo es gris oscuro indicando que la celda está desactivada.
  */
void entornoPonerNumero    (int fila, int columna, int num, bool activado);


/*
 * PRE: { 0 <= fila <= 10 }
 *      { 0 <= columna <= 10 }
 *      { 0 <=  num <= 99 }
 * POST: Coloca en la posición (fila,columna) el valor "num" (objetivo del juego) encerrado en un cuadrado
 *       El color de fondo depende del valor de "activado"
 *       Si activado es true, el color del marco es rojo indicando que el objetivo se ha conseguido.
 *       En caso contrario, el color del marco es gris indicando que el objetivo no se ha conseguido.
 */
void entornoPonerResultado      (int fila, int columna, int num, bool activado);


/*
 * PRE: { 0 <= fila <= 10 }
 *      { 0 <= columna <= 10 }
 *      { 1 <=  num <= 9 }
 *      { activo = true el fondo es ......}
 * POST: Coloca en la posición (fila,columna) el valor "num" encerrado en un circulo
 *       El color de fondo depende del valor de "activado"
 *       Si activado es true, el color del fondo es naranja claro indicando que la celda está activada y bloqueada.
 *       En caso contrario, el color del fondo es gris claro indicando que la celda está desactivada y bloqueada.
 */
void entornoPonerBloqueado(int fila, int columna, int num, bool activado);


/*
 * PRE: { 0 <= fila <= 10 }
 *      { 0 <= columna <= 10 }
 * POST: Borra el resultado (objetivo del juego) que aparece en la posición (fila,columna)
 */
void entornoQuitarResultado      (int fila, int columna);


/*
 * PRE:
 * POST: Muestra la puntuación actual, en el marcador situado
 *       encima del tablero
 */
void entornoPonerPuntuacion( int valor);


/*
 * PRE:
 * POST: Muestra el número de jugadas que faltan para terminar la partida,
 * en el marcador situado encima del tablero
 */
void entornoPonerNumJugadas (int valor);


/*
 * PRE: { 0 <= fila <= 10 }
 *      { 0 <= columna <= 10 }
 * POST: Enmarca la casilla que ocupa la posición (fila, columna) en un circulo blanco.
 *       Se utiliza para simular el movimiento por el tablero
 */
void entornoMarcarPosicion(int fila, int columna);


/*
* PRE:  0 <= fila < MAXTAMANIO,
* PRE:  0 <= columna < MAXTAMANIO,
* POST: Elimina el marco blanco de la casilla que ocupa la posición (fila, columna).
*       Se utiliza para simular el movimiento por el tablero
*/
void entornoDesmarcarPosicion(int fila, int columna);


/*
 * POST:Devuelve un valor enumerado de TipoTecla que depende de la tecla que se haya pulsado
 */
TipoTecla entornoLeerTecla();



/*
 * POST: Muestra un mensaje, indicado por "msg", en el centro de la rejilla para indicar que ha finalizado el juego
 */

void entornoMostrarMensajeFin (string msg);


/*
 * POST:	Escribe un mensaje, indicado por el parámetro "msg", durante un instante
 */
void entornoMostrarMensaje (string msg);


/*
 * POST: convierte "numero" a cadena de caracteres
 *       se puede utilizar para crear mensajes que contengan un número
 */
string toString(int numero);



/*
* PRE: 0 < pausa  (es el tiempo en segundos que dura la pausa)
* POST: lleva a cabo una pausa en la ejecución del juego,
*       se puede utilizar para ralentizar algún movimiento sobre el tablero
*/
void entornoPausa(float pausa);
#endif
