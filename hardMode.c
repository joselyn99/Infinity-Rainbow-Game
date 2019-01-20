#include "OurTypes.h"
#include "hardMode.h"


EGOERA HARD_jokatu(int orden[])
{
	EGOERA egoera = JOLASTEN;
	int i = 0, ebentu = 0;
	int extraTime = 0;		 //El tiempo límite va aumentando a medida que avanzan los turnos por 500ms (medio segundo)
	int numeroDeColores = 8; //Para cambiar el rango de números en randomNum() (del 1 al 4 num=4, del 1-6 num=6, etc)
	int turnos = 1;			 //Número de turnos transcurridos
	int ordenNUM = 0;

	JOKO_ELEMENTUA bGorriaPULS, bBerdeaPULS, bUrdinaPULS, bHoriaPULS, bZianPULS, bLaranjaPULS, bArrosaPULS, bMoreaPULS;
	JOKO_ELEMENTUA pultsadorea;
	JOKO_ELEMENTUA wait, repeat;

	SDL_Event evento[128];

	//Elegir la seed del random
	int num = 0;
	srand(time(NULL));

	//Apartado de música
	audioInit();
	loadTheMusic(GAME_MUSIC_HARD);
	playMusic();

	fondoaKargatu(HARD_JOLASTEN_FONDOA); //Cargar fondo

	pultsadorea.id = -1; //Cargar pulsador
	pultsadorea.id = irudiaKargatu(HARD_PULTSADOREA);
	irudiaMugitu(pultsadorea.id, 170, 90);

	//Cargar sprites de botones pulsado fuera de la pantalla para que no estorben
	bGorriaPULS.id = irudiaKargatu(HARD_BOTOI_GORRIA_PULS);
	irudiaMugitu(bGorriaPULS.id, OUT_OF_BOUNDS, OUT_OF_BOUNDS);
	bBerdeaPULS.id = irudiaKargatu(HARD_BOTOI_BERDEA_PULS);
	irudiaMugitu(bBerdeaPULS.id, OUT_OF_BOUNDS, OUT_OF_BOUNDS);
	bUrdinaPULS.id = irudiaKargatu(HARD_BOTOI_URDINA_PULS);
	irudiaMugitu(bUrdinaPULS.id, OUT_OF_BOUNDS, OUT_OF_BOUNDS);
	bHoriaPULS.id = irudiaKargatu(HARD_BOTOI_HORIA_PULS);
	irudiaMugitu(bHoriaPULS.id, OUT_OF_BOUNDS, OUT_OF_BOUNDS);
	bZianPULS.id = irudiaKargatu(HARD_BOTOI_ZIAN_PULS);
	irudiaMugitu(bZianPULS.id, OUT_OF_BOUNDS, OUT_OF_BOUNDS);
	bArrosaPULS.id = irudiaKargatu(HARD_BOTOI_ARROSA_PULS);
	irudiaMugitu(bArrosaPULS.id, OUT_OF_BOUNDS, OUT_OF_BOUNDS);
	bLaranjaPULS.id = irudiaKargatu(HARD_BOTOI_LARANJA_PULS);
	irudiaMugitu(bLaranjaPULS.id, OUT_OF_BOUNDS, OUT_OF_BOUNDS);
	bMoreaPULS.id = irudiaKargatu(HARD_BOTOI_MOREA_PULS);
	irudiaMugitu(bMoreaPULS.id, OUT_OF_BOUNDS, OUT_OF_BOUNDS);

	irudiakMarraztu();
	pantailaBerriztu();

	do {	//BUCLE PRINCIPAL

		pantailaGarbitu();
		ordenNUM = 0;

		while (i < turnos)
		{
			num = randomNum(numeroDeColores);
			orden[ordenNUM] = num;

			if (i == 0) //Visualizar mensaje de esperar (solo cuando i == 0 para no estar cargando la imagentodo el rato)
			{
				wait.id = MEZUA_waitBistaratu();
			}

			switch (num)
			{
			case 1:	//PLAN: MOVER LAS IMAGENES PULSADA FUERA DE LA PANTALLA Y MOVERLAS DENTRO CUANDO SE NECESITEN [DONE]
				JOKOA_botoiPultsatuaMarraztu(bGorriaPULS, 500);
				break;

			case 2:
				JOKOA_botoiPultsatuaMarraztu(bBerdeaPULS, 500);
				break;

			case 3:
				JOKOA_botoiPultsatuaMarraztu(bUrdinaPULS, 500);
				break;

			case 4:
				JOKOA_botoiPultsatuaMarraztu(bHoriaPULS, 500);
				break;

			case 5:
				JOKOA_botoiPultsatuaMarraztu(bZianPULS, 500);
				break;

			case 6:
				JOKOA_botoiPultsatuaMarraztu(bArrosaPULS, 500);
				break;

			case 7:
				JOKOA_botoiPultsatuaMarraztu(bLaranjaPULS, 500);
				break;

			case 8:
				JOKOA_botoiPultsatuaMarraztu(bMoreaPULS, 500);
				break;
			}

			irudiaMugitu(pultsadorea.id, 170, 90);
			irudiakMarraztu();
			pantailaBerriztu();
			Sleep(200);

			i++;
			ordenNUM++;
		}

		i = 0;
		turnos++;

		//Quitar mensaje de esperar
		irudiaKendu(wait.id);
		irudiakMarraztu();
		pantailaBerriztu();

		repeat.id = MEZUA_repeatBistaratu(); //Visualizar mensaje de repetir
		//El jugador pulsa los botones
		SDL_PeepEvents(evento, 128, SDL_GETEVENT, SDL_FIRSTEVENT, SDL_LASTEVENT);
		egoera = JOKOA_HARD_egoera(bGorriaPULS, bBerdeaPULS, bUrdinaPULS, bHoriaPULS, bZianPULS, bArrosaPULS, bLaranjaPULS, bMoreaPULS, pultsadorea, turnos, orden);
		irudiaKendu(repeat.id);//Quitar mensaje de repetir

		if (egoera == JOLASTEN)
		{
			MEZUA_jokalariaZoriondu(); //Visualizar N I C E si el jugador ha repetido bien los colores
		}


	} while (egoera == JOLASTEN);

	orden[0] = turnos - 1; //Para en la puntuación saber cuántos turnos han pasado

	toggleMusic();
	audioTerminate();
	pantailaGarbitu();
	pantailaBerriztu();
	return egoera;
}

EGOERA JOKOA_HARD_egoera(JOKO_ELEMENTUA bGorriaPULS,
	JOKO_ELEMENTUA bBerdeaPULS,
	JOKO_ELEMENTUA bUrdinaPULS,
	JOKO_ELEMENTUA bHoriaPULS,
	JOKO_ELEMENTUA bZianPULS,
	JOKO_ELEMENTUA bArrosaPULS,
	JOKO_ELEMENTUA bLaranjaPULS,
	JOKO_ELEMENTUA bMoreaPULS,
	JOKO_ELEMENTUA pultsadorea,
	int limitea,
	int ordena[]) //Con esta función sabemos si el juego sigue o ya ha acabado
{
	int ret = JOLASTEN;
	POSIZIOA saguPos;
	int ebentu = 0, exit = 0, i = 0;
	int inCircle;
	int extraTime = 0;		 //El tiempo límite va aumentando a medida que avanzan los turnos por 500ms (medio segundo)

	clock_t start = clock();

	while (exit < limitea - 1 && ret == JOLASTEN)
	{
		saguPos = saguarenPosizioa();
		ebentu = ebentuaJasoGertatuBada();
		inCircle = pow(saguPos.x - 320, 2) + pow(saguPos.y - 240, 2); //Área circular teniendo como centro el punto P(320, 240)

		if (ebentu == SAGU_BOTOIA_EZKERRA && inCircle < PULTSADORE_ZIRKULUA) //Si esto se cumple significa que se está pulsando DENTRO del pulsador (17500 = área circular del pulsador)
		{
			if (saguPos.x >= 330 && (saguPos.x + saguPos.y <= 550)) //JUGADOR PULSA VERDE
			{
				JOKOA_botoiPultsatuaMarraztu(bBerdeaPULS, 250);

				if (ordena[i] != BERDEA)
				{
					ret = GALDU;
				}

				exit++;
				i++;
			}

			if (saguPos.x >= 330 && saguPos.y <= 230 && (saguPos.x + saguPos.y >= 570)) //JUGADOR PULSA AMARILLO
			{
				JOKOA_botoiPultsatuaMarraztu(bHoriaPULS, 250);

				if (ordena[i] != HORIA)
				{
					ret = GALDU;
				}

				exit++;
				i++;
			}

			if (saguPos.x >= 330 && saguPos.y >= 250 && (saguPos.x - saguPos.y >= 90)) //JUGADOR PULSA NARANJA
			{
				JOKOA_botoiPultsatuaMarraztu(bLaranjaPULS, 250);

				if (ordena[i] != LARANJA)
				{
					ret = GALDU;
				}

				exit++;
				i++;
			}

			if (saguPos.x >= 330 && (saguPos.x - saguPos.y <= 70)) //JUGADOR PULSA ROJO
			{
				JOKOA_botoiPultsatuaMarraztu(bGorriaPULS, 250);

				if (ordena[i] != GORRIA)
				{
					ret = GALDU;
				}

				exit++;
				i++;
			}

			if (saguPos.x <= 310 && saguPos.y >= 250 && (saguPos.x + saguPos.y >= 570)) //JUGADOR PULSA ROSA
			{
				JOKOA_botoiPultsatuaMarraztu(bArrosaPULS, 250);

				if (ordena[i] != ARROSA)
				{
					ret = GALDU;
				}

				exit++;
				i++;
			}

			if (saguPos.x <= 310 && saguPos.y >= 250 && (saguPos.x + saguPos.y <= 550)) //JUGADOR PULSA MORADO
			{
				JOKOA_botoiPultsatuaMarraztu(bMoreaPULS, 250);

				if (ordena[i] != MOREA)
				{
					ret = GALDU;
				}

				exit++;
				i++;
			}

			if (saguPos.x <= 310 && saguPos.y <= 250 && (saguPos.x - saguPos.y <= 70)) //JUGADOR PULSA AZUL
			{
				JOKOA_botoiPultsatuaMarraztu(bUrdinaPULS, 250);

				if (ordena[i] != URDINA)
				{
					ret = GALDU;
				}

				exit++;
				i++;
			}

			if (saguPos.x <= 310 && saguPos.y <= 250 && (saguPos.x - saguPos.y >= 90)) //JUGADOR PULSA CIAN
			{
				JOKOA_botoiPultsatuaMarraztu(bZianPULS, 250);

				if (ordena[i] != ZIAN)
				{
					ret = GALDU;
				}

				exit++;
				i++;
			}

			irudiaMugitu(pultsadorea.id, 170, 90);
			irudiakMarraztu();
			pantailaBerriztu();
			Sleep(200);
		}

		clock_t stop = clock();

		if ((stop - start) > (1000 + ((limitea - 1) * 500)))
		{
			ret = GALDU_DENBORA;
		}

		if (ebentu == SAGU_BOTOIA_EZKERRA && (saguPos.x >= 610 && saguPos.x <= 640) && (saguPos.y >= 2 && saguPos.y <= 30)) //JUGADOR PULSA X
		{
			ret = MENU;
		}
	}	
	
	return ret;
}