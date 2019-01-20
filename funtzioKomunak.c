#include "OurTypes.h"
#include "puntuazioak.h"
#include "funtzioKomunak.h"

void JOKOA_botoiPultsatuaMarraztu(JOKO_ELEMENTUA bKolorea, int delay)
{
	irudiaMugitu(bKolorea.id, 170, 90);

	irudiakMarraztu();
	pantailaBerriztu();
	Sleep(delay);

	irudiaMugitu(bKolorea.id, -300, 0);
}

int jokoAmaierakoa(EGOERA egoera, int orden[], int denbora, int zailtasuna)
{
	int ebentu = 0, id;
	int idAudioGame;
	int puntuazioa;

	idAudioGame = loadSound(BUKAERA_SOUND_1);
	playSound(idAudioGame);

	if (egoera == GALDU_DENBORA)
	{
		id = BUKAERA_irudiaBistaratu(BUKAERA_IMAGE_DENBORA);
	}
	else
	{
		id = BUKAERA_irudiaBistaratu(BUKAERA_IMAGE);
	}

	Sleep(4000);

	puntuazioa = puntuazioaKalkulatu(orden[0], denbora);
	puntuazioaSartu(zailtasuna, puntuazioa);
	printf("PUNTOS: %d", puntuazioa);


	do
	{
		ebentu = ebentuaJasoGertatuBada();
	} while ((ebentu != TECLA_RETURN) && (ebentu != SAGU_BOTOIA_ESKUMA));
	audioTerminate();
	irudiaKendu(id);
	return (ebentu != TECLA_RETURN) ? 1 : 0;
}

int randomNum(int numeroDeColores)
{
	int num = (rand() % numeroDeColores) + 1;

	return num;
}

int MEZUA_repeatBistaratu()
{
	int repeatID;

	repeatID = irudiaKargatu(REPEAT);
	irudiaMugitu(repeatID, 240, 410);
	irudiakMarraztu();
	pantailaBerriztu();

	return repeatID;
}

int MEZUA_waitBistaratu()
{
	int waitID;

	waitID = irudiaKargatu(PAY_ATTENTION);
	irudiaMugitu(waitID, 200, 400);
	irudiakMarraztu();
	pantailaBerriztu();
	Sleep(1000);

	return waitID;
}

void MEZUA_jokalariaZoriondu()
{
	JOKO_ELEMENTUA mezua;

	pantailaGarbitu();
	mezua.id = -1;
	mezua.id = irudiaKargatu(NICE);
	irudiaMugitu(mezua.id, 252, 415);
	irudiakMarraztu();
	pantailaBerriztu();

	Sleep(1200);
	irudiaKendu(mezua.id);
	irudiakMarraztu();
	pantailaBerriztu();
	Sleep(800);

}

void jokoaPausatu(int pauseID)
{
	int ebentu;

	toggleMusic();
	irudiaMugitu(pauseID, 136, 175);
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentu = ebentuaJasoGertatuBada();
	} while (ebentu != TECLA_p);
	toggleMusic();
	irudiaMugitu(pauseID, OUT_OF_BOUNDS, OUT_OF_BOUNDS);
	irudiakMarraztu();
	pantailaBerriztu();
}

int BUKAERA_irudiaBistaratu(int irudia) {
	int id = -1;
	id = irudiaKargatu(irudia);
	irudiaMugitu(id, 165, 130);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return id;
}

void fondoaKargatu(int fondoa)
{
	int fondoaID;

	fondoaID = irudiaKargatu(fondoa);
	irudiaMugitu(fondoaID, 0, 0);
}