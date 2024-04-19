#include "Figura.h"

Figura::Figura()  //constructor per inicialitzar tot a 0 literal
{
    F_TipusFigura = NO_FIGURA;
    F_Gir = NO_GIR;
    F_Figura[MAX_ALCADA][MAX_AMPLADA] = { NO_COLOR };
    F_Fila = 0;
    F_Columna = 0;
}

Figura::Figura(TipusFigura tipus, Gir gir, int fila, int columna)
//constructor per inicialitzar amb el que es pasa per parametres
{
    F_TipusFigura = tipus;
    F_Gir = gir;
    F_Fila = fila;
    F_Columna = columna;

    switch (F_TipusFigura)   //AIXO ESTA MALAMENT PQ NO PUC RESTAR A UNA VARIABLE CONST: MAX_ALCADA, MAX_AMPLADA
    {
    case FIGURA_O: F_Figura[MAX_ALCADA][MAX_AMPLADA] = { COLOR_GROC }; ; break;
    case FIGURA_I: F_Figura[MAX_ALCADA][MAX_AMPLADA] = { {NO_COLOR, NO_COLOR, NO_COLOR, NO_COLOR},{COLOR_BLAUCEL, COLOR_BLAUCEL, COLOR_BLAUCEL, COLOR_BLAUCEL},{NO_COLOR, NO_COLOR, NO_COLOR, NO_COLOR},{NO_COLOR, NO_COLOR, NO_COLOR, NO_COLOR} }; break;
    case FIGURA_T: F_Figura[MAX_ALCADA - 1][MAX_AMPLADA - 1] = { {NO_COLOR, COLOR_MAGENTA, NO_COLOR},{COLOR_MAGENTA, COLOR_MAGENTA, COLOR_MAGENTA},{NO_COLOR, NO_COLOR, NO_COLOR} }; break;
    case FIGURA_L: F_Figura[MAX_ALCADA - 1][MAX_AMPLADA - 1] = { {NO_COLOR, NO_COLOR, COLOR_TARONJA},{COLOR_TARONJA, COLOR_TARONJA, COLOR_TARONJA},{NO_COLOR, NO_COLOR, NO_COLOR} }; break;
    case FIGURA_J: F_Figura[MAX_ALCADA - 1][MAX_AMPLADA - 1] = { {COLOR_BLAUFOSC, NO_COLOR, NO_COLOR},{COLOR_BLAUFOSC, COLOR_BLAUFOSC, COLOR_BLAUFOSC},{NO_COLOR, NO_COLOR, NO_COLOR} }; break;
    case FIGURA_Z: F_Figura[MAX_ALCADA - 1][MAX_AMPLADA - 1] = { {COLOR_VERMELL, COLOR_VERMELL, NO_COLOR},{NO_COLOR, COLOR_VERMELL, COLOR_VERMELL},{NO_COLOR, NO_COLOR, NO_COLOR} }; break;
    case FIGURA_S: F_Figura[MAX_ALCADA - 1][MAX_AMPLADA - 1] = { {NO_COLOR, COLOR_VERD, COLOR_VERD},{COLOR_VERD, COLOR_VERD, NO_COLOR},{NO_COLOR, NO_COLOR, NO_COLOR} }; break;
    }

    for (int i = 0; i < F_Gir; i++)
    {
        girHorari();
    }
}

void Figura::inicialitzarF(TipusFigura tipus, Gir gir, int fila, int col)
{
    Figura(tipus, gir, fila, col);
}

void Figura::girHorari()
{
    ColorFigura temporal[MAX_ALCADA][MAX_AMPLADA]{};

    int l = 0;
    for (int i = 0; i < MAX_ALCADA; i++)
    {
        int k = MAX_ALCADA - 1;
        for (int j = 0; j < MAX_AMPLADA; j++)
        {
            temporal[i][j] = F_Figura[k][l];
            k--;
        }
        l++;
    }

    for (int i = 0; i < MAX_ALCADA; i++)
    {
        for (int j = 0; j < MAX_AMPLADA; j++)
        {
            F_Figura[i][j] = temporal[i][j];
        }
    }
}

void Figura::girAntiHorari()
{
    ColorFigura temporal[MAX_ALCADA][MAX_AMPLADA];

    int l = MAX_AMPLADA - 1;
    for (int i = 0; i < MAX_ALCADA; i++)
    {
        int k = 0;
        for (int j = 0; j < MAX_AMPLADA; j++)
        {
            temporal[i][j] = F_Figura[k][l];
            k++;
        }
        l--;
    }

    for (int i = 0; i < MAX_ALCADA; i++)
    {
        for (int j = 0; j < MAX_AMPLADA; j++)
        {
            F_Figura[i][j] = temporal[i][j];
        }
    }
}
