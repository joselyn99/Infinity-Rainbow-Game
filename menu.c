#include "OurTypes.h"
#include "menu.h"


void jokoaAurkeztu()
{
	int ebentu = 0;

	fondoaKargatu(AURKEZPEN_FONDOA);
	irudiakMarraztu();
	pantailaBerriztu();

	do
	{
		ebentu = ebentuaJasoGertatuBada();

	} while (ebentu == 0 || ebentu == SAGU_MUGIMENDUA);
}

int menuaBistaratu()
{
	int ebentu = 0, egoera = -1, i = 0;
	int aukera = NORMAL;
	int inCircle;
	JOKO_ELEMENTUA bNormal, bNormalPULS, bHard, bHardPULS, bPlay, bPlayPULS, bLeaderboard, bExit, normalRules, hardRules;

	audioInit();
	loadTheMusic(GAME_MUSIC_MENU);
	playMusic();
	
	fondoaKargatu(MENU_FONDOA);

	normalRules.id = irudiaKargatu(NORMAL_RULES);					//Se programa más fácil si las reglas son una imagen normal y no
	irudiaMugitu(normalRules.id, 0, 0);		//un fondo, comentarlo con Martín
	hardRules.id = irudiaKargatu(HARD_RULES);
	irudiaMugitu(hardRules.id, OUT_OF_BOUNDS, OUT_OF_BOUNDS);

	bNormal.id = irudiaKargatu(NORMAL_BUTTON);
	irudiaMugitu(bNormal.id, 365, 105);
	bNormalPULS.id = irudiaKargatu(NORMAL_BUTTON_PULS);
	irudiaMugitu(bNormalPULS.id, OUT_OF_BOUNDS, OUT_OF_BOUNDS);
	bHard.id = irudiaKargatu(HARD_BUTTON);
	irudiaMugitu(bHard.id, 372, 155);
	bHardPULS.id = irudiaKargatu(HARD_BUTTON_PULS);
	irudiaMugitu(bHardPULS.id, OUT_OF_BOUNDS, OUT_OF_BOUNDS);
	bPlay.id = irudiaKargatu(PLAY_BUTTON);
	irudiaMugitu(bPlay.id, 500, 110);
	bPlayPULS.id = irudiaKargatu(PLAY_BUTTON_PULS);
	irudiaMugitu(bPlayPULS.id, OUT_OF_BOUNDS, OUT_OF_BOUNDS);
	bLeaderboard.id = irudiaKargatu(LEADERBOARD_BUTTON);
	irudiaMugitu(bLeaderboard.id, 365, 265);
	bExit.id = irudiaKargatu(EXIT_BUTTON);
	irudiaMugitu(bExit.id, 425, 335);

	irudiakMarraztu();
	pantailaBerriztu();

	POSIZIOA saguPos;

	do
	{
		saguPos = saguarenPosizioa();
		inCircle = sqrt(pow(saguPos.x - 536, 2) + pow(saguPos.y - 145, 2));

		ebentu = ebentuaJasoGertatuBada();
		
		if (ebentu == SAGU_BOTOIA_EZKERRA)
		{
			if ((saguPos.x >= 365 && saguPos.x <= 475) && (saguPos.y >= 105 && saguPos.y <= 135)) //Jugador pulsa NORMAL
			{
				irudiaMugitu(bHardPULS.id, OUT_OF_BOUNDS, OUT_OF_BOUNDS);
				irudiaMugitu(bHard.id, 372, 155);
				irudiaMugitu(bNormal.id, OUT_OF_BOUNDS, OUT_OF_BOUNDS);
				irudiaMugitu(bNormalPULS.id, 365, 105);

				irudiaMugitu(hardRules.id, OUT_OF_BOUNDS, OUT_OF_BOUNDS);
				irudiaMugitu(normalRules.id, 0, 0);

				aukera = NORMAL;
			}

			if ((saguPos.x >= 372 && saguPos.x <= 465) && (saguPos.y >= 155 && saguPos.y <= 185)) //Jugador pulsa HARD
			{
				irudiaMugitu(bNormal.id, 365, 105);
				irudiaMugitu(bNormalPULS.id, OUT_OF_BOUNDS, OUT_OF_BOUNDS);
				irudiaMugitu(bHardPULS.id, 372, 155);
				irudiaMugitu(bHard.id, OUT_OF_BOUNDS, OUT_OF_BOUNDS);

				irudiaMugitu(normalRules.id, OUT_OF_BOUNDS, OUT_OF_BOUNDS);
				irudiaMugitu(hardRules.id, 0, 0);

				aukera = HARD;
			}

			if (inCircle <= 36)
			{
				egoera = JOLASTEN;
			}

			if ((saguPos.x >= 365 && saguPos.x <= 560) && (saguPos.y >= 265 && saguPos.y <= 305)) //AQUÍ VA LA CONDICIÓN DEL LEADERBOARD
			{
				aukera = LEADERBOARD;
			}

			if ((saguPos.x >= 425 && saguPos.x <= 515) && (saguPos.y >= 335 && saguPos.y <= 375)) //AQUÍ VA LA CONDICIÓN DEL EXIT
			{
				sgItxi();
			}
			
		}

		if (inCircle <= GO_ZIRKULUA)
		{
			irudiaMugitu(bPlay.id, OUT_OF_BOUNDS, OUT_OF_BOUNDS);
			irudiaMugitu(bPlayPULS.id, 499, 109);
			i = 0;
		}

		else if (i == 0)
		{
			irudiaMugitu(bPlay.id, 500, 110);
			irudiaMugitu(bPlayPULS.id, OUT_OF_BOUNDS, OUT_OF_BOUNDS);
			i = 1;
		}

		irudiakMarraztu();
		pantailaBerriztu();

	} while (egoera != JOLASTEN && aukera != LEADERBOARD);

	irudiaKendu(normalRules.id);
	irudiaKendu(hardRules.id);
	irudiaKendu(bNormal.id);
	irudiaKendu(bNormalPULS.id);
	irudiaKendu(bHard.id);
	irudiaKendu(bHardPULS.id);
	irudiaKendu(bPlay.id);
	irudiaKendu(bPlayPULS.id);
	irudiaKendu(bLeaderboard.id);
	irudiaKendu(bExit.id);

	pantailaGarbitu();
	pantailaBerriztu();

	return aukera;
}

