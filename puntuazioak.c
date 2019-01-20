#include "OurTypes.h"
#include "puntuazioak.h"

void leaderboardBistaratu()
{
	int jokalariKop, ebentu;
	int i = 0, j = 0;
	JOKALARIA jokalari[128];

	fondoaKargatu(LEADERBOARD_WINDOW);
	irudiakMarraztu();

	textuaGaitu();

	jokalariKop = NORMAL_irakurriFitxategitik(jokalari);
	scoreOrdenatu(jokalari, jokalariKop);
	NORMAL_puntuazioaBistaratu(jokalari);

	jokalariKop = HARD_irakurriFitxategitik(jokalari);
	scoreOrdenatu(jokalari, jokalariKop);
	HARD_puntuazioaBistaratu(jokalari);

	do
	{
		ebentu = ebentuaJasoGertatuBada();

	} while (ebentu == 0 || ebentu == SAGU_MUGIMENDUA);

}

int puntuazioaKalkulatu(int turnoKop, int denbora)
{
	int puntuazioa;

	puntuazioa = (pow(2.9, turnoKop) / (denbora * 0.001)) * 10;

	if (turnoKop == 1 || puntuazioa < 0)
	{
		puntuazioa = 0;
	}
	
	return puntuazioa;
}

void puntuazioaSartu(int zailtasuna, int puntuak)
{
	JOKALARIA jokalaria[128];
	FILE *fp;
	char linea[128];
	char izena[128];
	char puntuakC[128];
	int i = 0, ebentu;

	if (zailtasuna == NORMAL)
	{
		fp = fopen("puntuazioak_N.txt", "a");
	}
	if (zailtasuna == HARD)
	{
		fp = fopen("puntuazioak_H.txt", "a");
	}

	do
	{
		i++;
	}
	while (fgets(linea, 128, fp)); //Avanza hasta la última línea


	int nameID = irudiaKargatu(NAME_WINDOW);
	irudiaMugitu(nameID, -25, 90);
	irudiakMarraztu();


	i = 0;
	int j = 0;
	textuaGaitu();

	do
	{
		ebentu = ebentuaJasoGertatuBada();

		switch (ebentu)
		{
		case TECLA_a:
			textuaIdatzi(275 + i, 285, "A");
			i += LETRA_TARTEA_TXIKIA;
			izena[j] = 'A';
			j++;
			break;
		case TECLA_b:
			textuaIdatzi(275 + i, 285, "B");
			i += LETRA_TARTEA_TXIKIA;
			izena[j] = 'B';
			j++;
			break;
		case TECLA_c:
			textuaIdatzi(275 + i, 285, "C");
			i += LETRA_TARTEA_TXIKIA;
			izena[j] = 'C';
			j++;
			break;
		case TECLA_d:
			textuaIdatzi(275 + i, 285, "D");
			i += LETRA_TARTEA_TXIKIA;
			izena[j] = 'D';
			j++;
			break;
		case TECLA_e:
			textuaIdatzi(275 + i, 285, "E");
			i += LETRA_TARTEA_TXIKIA;
			izena[j] = 'E';
			j++;
			break;
		case TECLA_f:
			textuaIdatzi(275 + i, 285, "F");
			i += LETRA_TARTEA_TXIKIA;
			izena[j] = 'F';
			j++;
			break;
		case TECLA_g:
			textuaIdatzi(275 + i, 285, "G");
			i += LETRA_TARTEA_HANDIA;
			izena[j] = 'G';
			j++;
			break;
		case TECLA_h:
			textuaIdatzi(275 + i, 285, "H");
			i += LETRA_TARTEA_HANDIA;
			izena[j] = 'H';
			j++;
			break;
		case TECLA_i:
			textuaIdatzi(275 + i, 285, "I");
			i += LETRA_TARTEA_TXIKIA;
			izena[j] = 'I';
			j++;
			break;
		case TECLA_j:
			textuaIdatzi(275 + i, 285, "J");
			i += LETRA_TARTEA_TXIKIA;
			izena[j] = 'J';
			j++;
			break;
		case TECLA_k:
			textuaIdatzi(275 + i, 285, "K");
			i += LETRA_TARTEA_HANDIA;
			izena[j] = 'K';
			j++;
			break;
		case TECLA_l:
			textuaIdatzi(275 + i, 285, "L");
			i += LETRA_TARTEA_TXIKIA;
			izena[j] = 'L';
			j++;
			break;
		case TECLA_m:
			textuaIdatzi(275 + i, 285, "M");
			i += LETRA_TARTEA_HANDIA;
			izena[j] = 'M';
			j++;
			break;
		case TECLA_n:
			textuaIdatzi(275 + i, 285, "N");
			i += LETRA_TARTEA_HANDIA;
			izena[j] = 'N';
			j++;
			break;
		case TECLA_o:
			textuaIdatzi(275 + i, 285, "O");
			i += LETRA_TARTEA_HANDIA;
			izena[j] = 'O';
			j++;
			break;
		case TECLA_p:
			textuaIdatzi(275 + i, 285, "P");
			i += LETRA_TARTEA_TXIKIA;
			izena[j] = 'P';
			j++;
			break;
		case TECLA_q:
			textuaIdatzi(275 + i, 285, "Q");
			i += LETRA_TARTEA_HANDIA;
			izena[j] = 'Q';
			j++;
			break;
		case TECLA_r:
			textuaIdatzi(275 + i, 285, "R");
			i += LETRA_TARTEA_TXIKIA;
			izena[j] = 'R';
			j++;
			break;
		case TECLA_s:
			textuaIdatzi(275 + i, 285, "S");
			i += LETRA_TARTEA_TXIKIA;
			izena[j] = 'S';
			j++;
			break;
		case TECLA_t:
			textuaIdatzi(275 + i, 285, "T");
			i += LETRA_TARTEA_TXIKIA;
			izena[j] = 'T';
			j++;
			break;
		case TECLA_u:
			textuaIdatzi(275 + i, 285, "U");
			i += LETRA_TARTEA_HANDIA;
			izena[j] = 'U';
			j++;
			break;
		case TECLA_v:
			textuaIdatzi(275 + i, 285, "V");
			i += LETRA_TARTEA_TXIKIA;
			izena[j] = 'V';
			j++;
			break;
		case TECLA_w:
			textuaIdatzi(275 + i, 285, "W");
			i += LETRA_TARTEA_HANDIA;
			izena[j] = 'W';
			j++;
			break;
		case TECLA_x:
			textuaIdatzi(275 + i, 285, "X");
			i += LETRA_TARTEA_TXIKIA;
			izena[j] = 'X';
			j++;
			break;
		case TECLA_y:
			textuaIdatzi(275 + i, 285, "Y");
			i += LETRA_TARTEA_TXIKIA;
			izena[j] = 'Y';
			j++;
			break;
		case TECLA_z:
			textuaIdatzi(275 + i, 285, "Z");
			i += LETRA_TARTEA_HANDIA;
			izena[j] = 'Z';
			j++;
			break;
		}
		
		pantailaBerriztu();

	} while (ebentu != TECLA_RETURN && j <= 7);

	izena[j] = '\0';
	sprintf(puntuakC, "%d", puntuak);
	strcpy(jokalaria->puntuazioaChar, puntuakC);

	fprintf(fp, "%s\t%d\t\%s\n", izena, puntuak, puntuakC);
	fclose(fp);

	irudiaKendu(nameID);
}

int NORMAL_irakurriFitxategitik(JOKALARIA jokalariak[])
{
	FILE *fp;
	int egoera = 1;
	int kont = 0;
	char linea[128];

	fp = fopen("puntuazioak_N.txt", "r");

	if (fp != NULL)
	{
		while (fgets(linea, 128, fp) != NULL)
		{
			sscanf(linea, "%s\t%d\t\%s\n", jokalariak[kont].izena, &jokalariak[kont].puntuazioa, jokalariak[kont].puntuazioaChar);
			kont++;
		}
	}

	fclose(fp);
	strcpy(jokalariak[kont].izena, "/END/");
	
	return kont;
}

int HARD_irakurriFitxategitik(JOKALARIA jokalariak[])
{
	FILE *fp;
	int egoera = 1;
	int kont = 0;
	char linea[128];

	fp = fopen("puntuazioak_H.txt", "r");

	if (fp != NULL)
	{
		while (fgets(linea, 128, fp) != NULL)
		{
			sscanf(linea, "%s\t%d\t\%s\n", jokalariak[kont].izena, &jokalariak[kont].puntuazioa, jokalariak[kont].puntuazioaChar);
			kont++;
		}
	}

	fclose(fp);
	strcpy(jokalariak[kont].izena, "/END/");

	return kont;
}

void scoreOrdenatu(JOKALARIA jokalariak[], int jokalariKop)
{
	int i, j;
	JOKALARIA aux;

	for (i = 0; i < jokalariKop; i++)
	{
		for (j = 0; j < jokalariKop - 1; j++)
		{
			if (jokalariak[j].puntuazioa < jokalariak[j + 1].puntuazioa)
			{
				aux = jokalariak[j + 1];
				jokalariak[j + 1] = jokalariak[j];
				jokalariak[j] = aux;
			}
		}
	}
}

void NORMAL_puntuazioaBistaratu(JOKALARIA jokalari[])
{
	int jokalariKop;
	int i = 0, j = 0;

	jokalariKop = NORMAL_irakurriFitxategitik(jokalari);
	scoreOrdenatu(jokalari, jokalariKop);

	textuaGaitu();
	while (strcmp(jokalari[i].izena, "/END/") != 0 && i <= 9)
	{
		textuaIdatzi(160, (170 + j), jokalari[i].izena);
		textuaIdatzi(270, (170 + j), jokalari[i].puntuazioaChar);
		pantailaBerriztu();

		i++;
		j += 20;
	}
}

void HARD_puntuazioaBistaratu(JOKALARIA jokalari[])
{
	int jokalariKop;
	int i = 0, j = 0;

	jokalariKop = HARD_irakurriFitxategitik(jokalari);
	scoreOrdenatu(jokalari, jokalariKop);

	while (strcmp(jokalari[i].izena, "/END/") != 0 && i <= 9)
	{
		textuaIdatzi(340, (170 + j), jokalari[i].izena);
		textuaIdatzi(450, (170 + j), jokalari[i].puntuazioaChar);
		pantailaBerriztu();

		i++;
		j += 20;
	}
}