//---------------------------------------------------------------------------------
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
//---------------------------------------------------------------------------------

#include <stdio.h>
#include <time.h>

#include "ourTypes.h"
//#include "game02.h"


int main(int argc, char * str[]) {
  int jarraitu = 0;
  int menuAukera = -1, zailtasuna = -1;
  int orden[128];
  int denbora;
  EGOERA egoera;
 
  if (sgHasieratu() == -1) 
  {
    fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
    return 1;
  }
  textuaGaitu(); 

  jokoaAurkeztu();

  menu:
  menuAukera = menuaBistaratu();
  clock_t start = clock();

  if (menuAukera == NORMAL)
  {
	  do
	  {
		  egoera = jokatu(orden);
		  clock_t stop = clock();

		  if (egoera == MENU)
		  {
			  goto menu;
		  }

		  denbora = stop - start;
		  jarraitu = jokoAmaierakoa(egoera, orden, denbora, NORMAL);
		  
	  } while (jarraitu);
  }
 
  if (menuAukera == HARD)
  {
	  do
	  {
		  egoera = HARD_jokatu(orden);
		  clock_t stop = clock();

		  if (egoera == MENU)
		  {
			  goto menu;
		  }

		  denbora = stop - start;
		  jarraitu = jokoAmaierakoa(egoera, orden, denbora, HARD);

	  } while (jarraitu);
  }

  if (menuAukera == LEADERBOARD)
  {
	  clock_t stop = clock();

	  leaderboardBistaratu(); 
  }
  
  goto menu;

  sgItxi();
  return 0;
}