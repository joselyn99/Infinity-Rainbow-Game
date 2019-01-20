#include "OurTypes.h"
#include "normalMode.h"


EGOERA jokatu(int orden[])
{
	EGOERA egoera = JOLASTEN;
	int i = 0, ebentu = 0;
	int numeroDeColores = 4; //Para cambiar el rango de números en randomNum() (del 1 al 4 num=4, del 1-6 num=6, etc)
	int turnos = 1;			 //Número de turnos transcurridos
	int ordenNUM = 0;
	
	JOKO_ELEMENTUA bGorriaPULS, bBerdeaPULS, bUrdinaPULS, bHoriaPULS;
	JOKO_ELEMENTUA pultsadorea;
	JOKO_ELEMENTUA wait, repeat;

	SDL_Event evento[128];

	//Elegir la seed del random
	int num = 0;
	srand(time(NULL));

	//Apartado de música
	audioInit();
	loadTheMusic(GAME_MUSIC_NORMAL);
	playMusic();
	
	fondoaKargatu(JOLASTEN_FONDOA); //Cagar fondo

	pultsadorea.id = -1; //Cargar pulsador
	pultsadorea.id = irudiaKargatu(PULTSADOREA);
	irudiaMugitu(pultsadorea.id, 170, 90);

	//Cargar sprites de botones pulsado fuera de la pantalla para que no estorben
	bGorriaPULS.id = irudiaKargatu(BOTOI_GORRIA_PULS);
	irudiaMugitu(bGorriaPULS.id, -300, 0);
	bBerdeaPULS.id = irudiaKargatu(BOTOI_BERDEA_PULS);
	irudiaMugitu(bBerdeaPULS.id, -300, 0);
	bUrdinaPULS.id = irudiaKargatu(BOTOI_URDINA_PULS);
	irudiaMugitu(bUrdinaPULS.id, -300, 0);
	bHoriaPULS.id = irudiaKargatu(BOTOI_HORIA_PULS);
	irudiaMugitu(bHoriaPULS.id, -300, 0);

	irudiakMarraztu();
	pantailaBerriztu();
	Sleep(1000);

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
			}

			irudiaMugitu(pultsadorea.id, 170, 90);
			irudiakMarraztu();
			pantailaBerriztu();
			Sleep(200);

			i++;
			ordenNUM++;
		}

		ebentuaJasoGertatuBada();

		i = 0;
		turnos++;

		//Quitar mensaje de esperar
		irudiaKendu(wait.id);
		irudiakMarraztu();
		pantailaBerriztu();

		repeat.id = MEZUA_repeatBistaratu(); //Visualizar mensaje de repetir
		//El jugador pulsa los botones
		SDL_PeepEvents(evento, 128, SDL_GETEVENT, SDL_FIRSTEVENT, SDL_LASTEVENT);
		egoera = JOKOA_egoera(bGorriaPULS, bBerdeaPULS, bUrdinaPULS, bHoriaPULS, pultsadorea, turnos, orden);
		
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

EGOERA JOKOA_egoera(JOKO_ELEMENTUA bGorriaPULS, 
					JOKO_ELEMENTUA bBerdeaPULS, 
					JOKO_ELEMENTUA bUrdinaPULS, 
					JOKO_ELEMENTUA bHoriaPULS, 
					JOKO_ELEMENTUA pultsadorea, 
					int limitea, 
					int ordena[]) //Con esta función sabemos si el juego sigue o ya ha acabado
{ 
	int ret = JOLASTEN;
	POSIZIOA saguPos;
	int ebentu = 0, exit = 0, i = 0;
	int inCircle, pauseID;

	pauseID = irudiaKargatu(PAUSE_BUTTON);
	irudiaMugitu(pauseID, OUT_OF_BOUNDS, OUT_OF_BOUNDS);

	while (exit < limitea-1 && ret != GALDU && ret != MENU)
	{
		saguPos = saguarenPosizioa();
		ebentu = ebentuaJasoGertatuBada();
		inCircle = pow(saguPos.x - 320, 2) + pow(saguPos.y - 240, 2); //Área circular teniendo como centro el punto P(320, 240)

		if (ebentu == SAGU_BOTOIA_EZKERRA && inCircle < PULTSADORE_ZIRKULUA) //Si esto se cumple significa que se está pulsando DENTRO del pulsador (17500 = área circular del pulsador)
		{
			if ((saguPos.x >= 190 && saguPos.x <= 310) && (saguPos.y >= 110 && saguPos.y <= 230))	//JUGADOR PULSA ROJO
			{
				JOKOA_botoiPultsatuaMarraztu(bGorriaPULS, 250);

				if (ordena[i] != GORRIA)
				{
					ret = GALDU;
				}

				exit++;
				i++;
			}

			if ((saguPos.x >= 330 && saguPos.x <= 450) && (saguPos.y >= 110 && saguPos.y <= 230)) //JUGADOR PULSA VERDE
			{
				JOKOA_botoiPultsatuaMarraztu(bBerdeaPULS, 250);

				if (ordena[i] != BERDEA)
				{
					ret = GALDU;
				}

				exit++;
				i++;
			}

			if ((saguPos.x >= 330 && saguPos.x <= 450) && (saguPos.y >= 250 && saguPos.y <= 370)) //JUGADOR PULSA AZUL
			{
				JOKOA_botoiPultsatuaMarraztu(bUrdinaPULS, 250);

				if (ordena[i] != URDINA)
				{
					ret = GALDU;
				}

				exit++;
				i++;
			}

			if ((saguPos.x >= 190 && saguPos.x <= 310) && (saguPos.y >= 250 && saguPos.y <= 370)) //JUGADOR PULSA AMARILLO
			{
				JOKOA_botoiPultsatuaMarraztu(bHoriaPULS, 250);
				
				if (ordena[i] != HORIA)
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

		if (ebentu == TECLA_p)
		{
			jokoaPausatu(pauseID);
		}

		if (ebentu == SAGU_BOTOIA_EZKERRA && (saguPos.x >= 610 && saguPos.x <= 640) && (saguPos.y >= 2 && saguPos.y <= 30)) //JUGADOR PULSA X
		{
			ret = MENU;
		}
	}
	
	return ret;
}