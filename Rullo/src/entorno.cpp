/**

 INTRODUCCIÓN A LA PROGRAMACIÓN / FUNDAMENTOS DE PROGRAMACIÓN
 Curso 2018/2019

 Nombre: entorno.cpp
 Descripción: Implementación del TAD Entorno para el proyecto Rullo
 Encargado del manejo de la interfaz del juego.
 Autor:	Profesores de las asignaturas
 Fecha:	25/11/2012
 Fecha última modificación: 25/11/2018 Allegro5

 */

#include "entorno.h"
#include <stdlib.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro5.h>


#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;

// -------------------------------------------------------------
// Definicion de constantes privadas
// -------------------------------------------------------------
// Definición de colores que usa el entorno

const int COLOR_AZUL      = 1;
const int COLOR_BLANCO    = 2;
const int COLOR_ROJO      = 3;
const int COLOR_NEGRO     = 4;
const int COLOR_GRIS      = 5;
const int COLOR_AMARILLO  = 6;
const int COLOR_AMARILLO_CLARO  = 7;
const int COLOR_VERDE     = 8;
const int COLOR_GRIS_CLARO = 9;



const int COLOR_LINEAS = COLOR_BLANCO;
const float GROSOR_LINEAS = 2.0;


const int ANCHO_VENTANA = 600;
const int ALTO_VENTANA  = 650;

// Definicón de constantes para posicionar los números en el tablero
const int DISTANCIA_COLS  = 45;  // Distancia entre columnas
const int DISTANCIA_FILAS = 45;  // Distancia entre filas

int ORIGEN_X        = 80 ;  // Origen de las x
const int ORIGEN_Y     = 60 ;  // Origen de las y

// definicion de las constantes para posicionar los marcadores
const int FILA_MARCADOR = 110;
const int COL_MARCADOR  = 14;

const int RADIO = 16;

ALLEGRO_DISPLAY     *display;
ALLEGRO_FONT        *font;
ALLEGRO_EVENT_QUEUE *colaEventos = NULL;






// -------------------------------------------------------------
// Declaración de módulos PRIVADOS
// -------------------------------------------------------------

// convierte el número dado como parámetro de entrada a string (cadena)
string toString(int numero);

// define el color en función de los valores makecol - allegro library
ALLEGRO_COLOR makecolor2 (int color);



// -------------------------------------------------------------
// Definición de módulos PRIVADOS
// -------------------------------------------------------------

ALLEGRO_COLOR makecolor2(int color) {

	ALLEGRO_COLOR alColor;

	switch (color) {
	case COLOR_BLANCO:
		alColor = al_map_rgb (255, 255, 255);
		break;
	case COLOR_ROJO:
		alColor = al_map_rgb (255,   69,  0);
		break;
	case COLOR_NEGRO:
		alColor = al_map_rgb (0,    0,   0);
		break;
	case COLOR_AZUL:
		alColor = al_map_rgb (70,   150, 255);
		break;
	case COLOR_GRIS:
		alColor = al_map_rgb ( 47, 79, 79);
		break;
	case COLOR_AMARILLO:
		alColor = al_map_rgb ( 255, 255, 000);
		break;
	case COLOR_AMARILLO_CLARO:
		alColor = al_map_rgb ( 255,160,122);
		break;
	case COLOR_VERDE:
		alColor = al_map_rgb ( 036,231,017);
		break;
	case COLOR_GRIS_CLARO:
		alColor = al_map_rgb ( 192,192,192);
		break;
	default:
		alColor = al_map_rgb (255, 255, 255);
		break; //color blanco
	}

	return alColor;
}
void invertirFC(int &fila, int &columna) {
	int aux = columna;
	columna = fila;
	fila = aux;
}

// -------------------------------------------------------------
// Definición de la interfaz PÚBLICA
// -------------------------------------------------------------

void entornoIniciar(int tam) {

	// Iniciar el entorno

	if (al_init()){
	al_install_keyboard();

	al_set_new_display_option(ALLEGRO_SINGLE_BUFFER, 1, ALLEGRO_REQUIRE);
	al_set_new_display_flags (ALLEGRO_WINDOWED);


	display = al_create_display(ANCHO_VENTANA,ALTO_VENTANA);
	al_init_primitives_addon(); //

	al_init_font_addon();
	al_init_ttf_addon();


	// carga las fuentes con tamaño 18
	font = al_load_ttf_font("DroidSerif-Regular.ttf", 18, 0);

    // borra la ventana con el color blanco
    al_clear_to_color(makecolor2(COLOR_NEGRO));
    al_set_window_title(display, "UexRullo");

    // se refresca la pantalla
    colaEventos = al_create_event_queue();
    al_register_event_source(colaEventos, al_get_keyboard_event_source());
    ORIGEN_X = (ANCHO_VENTANA -((tam+2)*DISTANCIA_COLS))/2;


    al_draw_text(font, makecolor2(COLOR_BLANCO), ORIGEN_X,550,  ALLEGRO_ALIGN_LEFT,"Teclas: izqda, dcha, arriba, abajo, espacio, Esc");
    al_draw_text(font, makecolor2(COLOR_BLANCO), ORIGEN_X,570,  ALLEGRO_ALIGN_LEFT,"Ampliaciones, pistas:");
    al_draw_text(font, makecolor2(COLOR_BLANCO), ORIGEN_X+30,590,  ALLEGRO_ALIGN_LEFT,"Y: suma fila/columna");
    al_draw_text(font, makecolor2(COLOR_BLANCO), ORIGEN_X+30,610,  ALLEGRO_ALIGN_LEFT,"X: resolver ");

    al_flip_display();

	}
}

void entornoTerminar(){

	al_destroy_display          (display);
	al_destroy_event_queue      (colaEventos);
	al_destroy_font				(font);
	al_shutdown_primitives_addon();
	al_shutdown_font_addon      ();
}

bool entornoCargarConfiguracion ( int &tamano, int &cargarDeFichero,  int& numMvtos, int &nivel,  int m[MAX_TAMANO][MAX_TAMANO],
		int vSumaFilas[MAX_TAMANO], int vSumaCol[MAX_TAMANO]){

	bool leido;
	int i, j;
	ifstream fEntrada;
	string cadena, cad;
	fEntrada.open("rullo.cnf");
	if (fEntrada.is_open()) {
		getline(fEntrada, cadena);
		tamano = atoi(cadena.c_str());

		getline(fEntrada, cadena);
		cargarDeFichero = atoi(cadena.c_str());

		getline(fEntrada, cadena);
		numMvtos = atoi(cadena.c_str());

		getline(fEntrada, cadena);
		nivel = atoi(cadena.c_str());

		leido = true;
		for (i = 0; i<tamano; i++){
			for (j = 0; j< tamano; j++){
				getline (fEntrada,cad,' ');
				m[i][j]= atoi(cad.c_str());
			}
			// resultado filas
			getline (fEntrada,cad);
			vSumaFilas[i]= atoi(cad.c_str());
		}
		// leer resultados de las col
		for (j = 0; j< tamano; j++){
				getline (fEntrada,cad,' ');
				vSumaCol[j]= atoi(cad.c_str());
		}


		fEntrada.close();
	} else {
		cout
				<< "Fichero de configuración no encontrado (<proyecto>/rullo.cnf)."
				<< endl;
		cout << "Formato:" << endl;
		cout << "\t[Tamaño del tablero ]" << endl;

		leido = false;
	}

	return leido;
}




void entornoPonerNumero(int fila, int columna, int num, bool activado) {
	invertirFC(fila, columna);
	int colorFondo;
	if (activado)
		colorFondo = COLOR_ROJO;
	else
		colorFondo = COLOR_GRIS;
	al_draw_filled_circle( (ORIGEN_X + fila * DISTANCIA_COLS + 3)+ RADIO,
			(ORIGEN_Y + columna * DISTANCIA_FILAS + 3) + RADIO ,
			RADIO +2,
			makecolor2(colorFondo));

	al_draw_circle( (ORIGEN_X + fila * DISTANCIA_COLS + 3)+ RADIO,
					(ORIGEN_Y + columna * DISTANCIA_FILAS + 3) + RADIO,
					RADIO +1,
					makecolor2(COLOR_ROJO),3);

	al_draw_text(font, makecolor2(COLOR_BLANCO), (ORIGEN_X + fila * DISTANCIA_COLS )-2+ RADIO, (ORIGEN_Y + columna * DISTANCIA_FILAS)-1 + RADIO/2 , ALLEGRO_ALIGN_LEFT, toString(num).c_str());

	al_flip_display();
}

void entornoPonerBloqueado(int fila, int columna, int num, bool activo){
	invertirFC(fila, columna);
	int color;
	if (activo )
		color = COLOR_AMARILLO_CLARO;
	else
		color = COLOR_GRIS_CLARO;
	al_draw_filled_circle( (ORIGEN_X + fila * DISTANCIA_COLS + 3)+ RADIO,
				(ORIGEN_Y + columna * DISTANCIA_FILAS + 3) + RADIO,
				RADIO+2,
				makecolor2(color));

	al_draw_circle( (ORIGEN_X + fila * DISTANCIA_COLS + 3)+ RADIO,
						(ORIGEN_Y + columna * DISTANCIA_FILAS + 3) + RADIO,
						RADIO +1,
						makecolor2(COLOR_ROJO),3);

	al_draw_text(font, makecolor2(COLOR_ROJO), (ORIGEN_X + fila * DISTANCIA_COLS )-2+ RADIO, (ORIGEN_Y + columna * DISTANCIA_FILAS)-1 + RADIO/2 , ALLEGRO_ALIGN_LEFT, toString(num).c_str());


	al_flip_display();
}
void entornoPonerResultado(int fila, int columna, int num, bool activo){
	invertirFC(fila, columna);
	int color;
	if (activo)
		color = COLOR_ROJO;
	else
		color = COLOR_GRIS;
	al_draw_rectangle( ORIGEN_X + fila * DISTANCIA_COLS + 3,
					ORIGEN_Y + columna * DISTANCIA_FILAS + 3,
					ORIGEN_X + fila * DISTANCIA_COLS + DISTANCIA_COLS - 5,
					ORIGEN_Y + columna * DISTANCIA_FILAS + DISTANCIA_FILAS - 5,
					makecolor2(color), 2);

	al_draw_text(font, makecolor2(COLOR_BLANCO), (ORIGEN_X + fila * DISTANCIA_COLS )+ RADIO+4, (ORIGEN_Y + columna * DISTANCIA_FILAS) + RADIO/2 , ALLEGRO_ALIGN_CENTER, toString(num).c_str());

	al_flip_display();
}


void entornoQuitarResultado      (int fila, int columna){

	invertirFC(fila, columna);
	al_draw_filled_rectangle( ORIGEN_X + fila * DISTANCIA_COLS + 2,
						ORIGEN_Y + columna * DISTANCIA_FILAS + 2,
						ORIGEN_X + fila * DISTANCIA_COLS + DISTANCIA_COLS - 4,
						ORIGEN_Y + columna * DISTANCIA_FILAS + DISTANCIA_FILAS - 4,
						makecolor2(COLOR_NEGRO));

	al_flip_display();
}



void entornoMarcarPosicion(int fila, int columna) {

	invertirFC(fila, columna);
	al_draw_circle((ORIGEN_X + fila * DISTANCIA_COLS + 3) + RADIO,
			(ORIGEN_Y + columna * DISTANCIA_FILAS + 3) + RADIO, RADIO +1,
			makecolor2(COLOR_BLANCO), 3);

	al_flip_display();
}

void entornoDesmarcarPosicion(int fila, int columna) {

	invertirFC(fila, columna);
	al_draw_circle( (ORIGEN_X + fila * DISTANCIA_COLS + 3)+ RADIO,
				(ORIGEN_Y + columna * DISTANCIA_FILAS + 3) + RADIO,
				RADIO +1,
				makecolor2(COLOR_ROJO),3);

	al_flip_display();
}


void entornoPonerPuntuacion(int valor) {
	string msg;
	msg = "Puntuación: "+toString(valor);
	al_draw_filled_rectangle(FILA_MARCADOR , COL_MARCADOR, FILA_MARCADOR+ 200, COL_MARCADOR+30, makecolor2(COLOR_NEGRO));
	al_draw_text(font, makecolor2(COLOR_BLANCO),FILA_MARCADOR + 20, COL_MARCADOR + 4  , ALLEGRO_ALIGN_LEFT, msg.c_str());
	al_flip_display();
}

void entornoPonerNumJugadas (int valor){
	string msg;
	int color;
	if (valor <=2)
		color = COLOR_ROJO;
	else
		color = COLOR_BLANCO;
	msg = "Jugadas restantes: "+toString(valor);
	al_draw_filled_rectangle(FILA_MARCADOR+200 , COL_MARCADOR, (FILA_MARCADOR+200)+ 300, (COL_MARCADOR )+30, makecolor2(COLOR_NEGRO));
	al_draw_text(font, makecolor2(color),(FILA_MARCADOR+200) + 20, COL_MARCADOR + 4  , ALLEGRO_ALIGN_LEFT, msg.c_str());
	al_flip_display();
}

void entornoMostrarMensajeFin(string msg) {
	int i, j;
		for (i = 0, j = 0; i < 40 && j < 40; i += 4, j += 4) {

			al_draw_filled_rectangle(i + ORIGEN_X,     j + ORIGEN_Y   + 200,  ORIGEN_X   +350 - i, ORIGEN_Y+   320 -j,  makecolor2(COLOR_BLANCO));
			al_draw_filled_rectangle(i + ORIGEN_X + 2 ,j + ORIGEN_Y +2+ 200, (ORIGEN_X-2)+350 - i, ORIGEN_Y -2 +320 -j,  makecolor2(COLOR_NEGRO));

			usleep(25000); // 25 milisegundos
			al_flip_display();
		}

	al_draw_text(font, makecolor2(COLOR_ROJO),ORIGEN_X+100,ORIGEN_Y+250, ALLEGRO_ALIGN_LEFT, msg.c_str());
	al_flip_display();
}


void entornoMostrarMensaje( string msg) {
	int col = 350;
	int fila = 600;
	int alto = 25;
	int ancho = 600;

	al_draw_filled_rectangle(col-2 , fila,  col + ancho, fila + alto,  makecolor2(COLOR_NEGRO));
	al_draw_text(font, makecolor2(COLOR_ROJO),col,fila, ALLEGRO_ALIGN_LEFT, msg.c_str());
	al_flip_display();
	entornoPausa(1.5);
	al_draw_filled_rectangle(col-2 , fila,  col + ancho,fila + alto,  makecolor2(COLOR_NEGRO));
	al_flip_display();

}



TipoTecla entornoLeerTecla() {

	TipoTecla tecla = TNada;
	ALLEGRO_EVENT evento;

	al_wait_for_event(colaEventos, &evento);

	if (evento.type == ALLEGRO_EVENT_KEY_DOWN) {
		switch (evento.keyboard.keycode) {
		case ALLEGRO_KEY_UP:
			tecla = TArriba;
			break;
		case ALLEGRO_KEY_DOWN:
			tecla = TAbajo;
			break;
		case ALLEGRO_KEY_LEFT:
			tecla = TIzquierda;
			break;
		case ALLEGRO_KEY_RIGHT:
			tecla = TDerecha;
			break;
		case ALLEGRO_KEY_ESCAPE:
			tecla = TSalir;
			break;
		case ALLEGRO_KEY_ENTER:
			tecla = TEnter;
			break;
		case ALLEGRO_KEY_SPACE:
			tecla = TSPACE;
			break;

		case ALLEGRO_KEY_Y:
			tecla = TY;
			break;
		case ALLEGRO_KEY_X:
			tecla = TX;
			break;

		default:
			tecla = TNada;
			break;
		}
	};

	return tecla;

}


void entornoPausa(float pausa) {
	al_rest(pausa);
}


string toString(int numero) {
	stringstream flujo;
	string cadena;
	flujo << numero;
	flujo >> cadena;
	return cadena;
}

