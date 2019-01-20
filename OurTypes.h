#ifndef OURTYPES_H
#define OURTYPES_H

#define _CRT_SECURE_NO_WARNINGS

#include "menu.h"
#include "funtzioKomunak.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <SDL.h>
#include <SDL_thread.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <math.h>

typedef enum { JOLASTEN, GALDU, GALDU_DENBORA, LEADERBOARD, MENU } EGOERA;
typedef enum { ZURIA, GORRIA, BERDEA, URDINA, HORIA, ZIAN, ARROSA, LARANJA, MOREA } KOLOREA;
typedef enum { NORMAL, HARD } ZAILTASUNA;

typedef struct
{
  int id;
}JOKO_ELEMENTUA;

typedef struct
{
	char izena[10];
	int puntuazioa;
	char puntuazioaChar[10];

}JOKALARIA;

//SONIDOS Y MÚSICA
#define GAME_MUSIC_NORMAL ".\\sound\\Gourmet Race.wav"
#define GAME_MUSIC_HARD ".\\sound\\Gourmet Race (Brawl Remix).wav"
#define GAME_MUSIC_MENU ".\\sound\\Gourmet Race (Menu).wav"
#define BUKAERA_SOUND_1 ".\\sound\\DEATH_SOUND.wav"

//MENÚ
#define AURKEZPEN_FONDOA ".\\img\\INICIATE_SCREEN_TWO.bmp"
#define	MENU_FONDOA ".\\img\\LIBRO_HACIENDO.bmp"
#define NORMAL_RULES ".\\img\\NORMAL_RULES.bmp"
#define HARD_RULES ".\\img\\HARD_RULES.bmp"
#define NORMAL_BUTTON ".\\img\\NORMAL_BUTTON.bmp"
#define NORMAL_BUTTON_PULS ".\\img\\NORMAL_BUTTON_PULS.bmp"
#define HARD_BUTTON ".\\img\\HARD_BUTTON.bmp"
#define HARD_BUTTON_PULS ".\\img\\HARD_BUTTON_PULS.bmp"
#define PLAY_BUTTON ".\\img\\PLAY.bmp"
#define PLAY_BUTTON_PULS ".\\img\\PLAY_PULS.bmp"
#define LEADERBOARD_BUTTON ".\\img\\LEADERBOARD_BUTTON.bmp"
#define EXIT_BUTTON ".\\img\\EXIT_BUTTON.bmp"
#define PAUSE_BUTTON ".\\img\\PAUSE_BUTTON.bmp"

//GAME
#define NICE ".\\img\\NICE.bmp"
#define PAY_ATTENTION ".\\img\\PAY_ATTENTION.bmp"
#define REPEAT ".\\img\\REPEAT.bmp"
#define BUKAERA_IMAGE ".\\img\\GAME_OVER.bmp"
#define BUKAERA_IMAGE_DENBORA ".\\img\\GAME_OVER_TIME.bmp"

//NORMAL MODE
#define BOTOI_GORRIA_PULS ".\\img\\B_ROJO_PULSADO.bmp"
#define BOTOI_BERDEA_PULS ".\\img\\B_VERDE_PULSADO.bmp"
#define BOTOI_URDINA_PULS ".\\img\\B_AZUL_PULSADO.bmp"
#define BOTOI_HORIA_PULS ".\\img\\B_AMARILLO_PULSADO.bmp"
#define PULTSADOREA ".\\img\\RUEDA.bmp"
#define JOLASTEN_FONDOA ".\\img\\PANTALLA_JUEGO_NORMAL.bmp"

//HARD MODE
#define HARD_BOTOI_GORRIA_PULS ".\\img\\HARD_B_ROJO_PULSADO.bmp"
#define HARD_BOTOI_BERDEA_PULS ".\\img\\HARD_B_VERDE_PULSADO.bmp"
#define HARD_BOTOI_URDINA_PULS ".\\img\\HARD_B_AZUL_PULSADO.bmp"
#define HARD_BOTOI_HORIA_PULS ".\\img\\HARD_B_AMARILLO_PULSADO.bmp"
#define HARD_BOTOI_ARROSA_PULS ".\\img\\HARD_B_ROSA_PULSADO.bmp"
#define HARD_BOTOI_MOREA_PULS ".\\img\\HARD_B_MORADO_PULSADO.bmp"
#define HARD_BOTOI_LARANJA_PULS ".\\img\\HARD_B_NARANJA_PULSADO.bmp"
#define HARD_BOTOI_ZIAN_PULS ".\\img\\HARD_B_CIAN_PULSADO.bmp"
#define HARD_PULTSADOREA ".\\img\\RUEDA_HARD.bmp"
#define HARD_JOLASTEN_FONDOA ".\\img\\PANTALLA_JUEGO_DIFICIL.bmp"

//PUNTUACIÓN
#define NAME_WINDOW ".\\img\\YOUR_NAME.bmp"
#define LEADERBOARD_WINDOW ".\\img\\PANTALLA_JUEGO_LEADERBOARD.bmp"

//DATOS NECESARIOS
#define OUT_OF_BOUNDS -800
#define PULTSADORE_ZIRKULUA 17500
#define GO_ZIRKULUA 36
#define LETRA_TARTEA_HANDIA 18
#define LETRA_TARTEA_TXIKIA 14

#endif