#ifndef PUNTUAZIOAK_H
#define PUNTUAZIOAK_H

int puntuazioaKalkulatu(int turnoKop, int denbora);

void puntuazioaSartu(int zailtasuna, int puntuak);

int irakurriFitxategitik(JOKALARIA jokalariak[]);

void scoreOrdenatu(JOKALARIA jokalariak[], int jokalariKop);

void leaderboardBistaratu();

void puntuakCharBihurtu(char puntuakChar[], int puntuakInt);

void NORMAL_puntuazioaBistaratu(JOKALARIA jokalari[]);

void HARD_puntuazioaBistaratu(JOKALARIA jokalari[]);

#endif // !PUNTUZAIOAK_H
