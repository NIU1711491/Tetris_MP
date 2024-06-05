
#include "Figura.h"

Figura::Figura() //constructor per defecte de Figura pq sinó Joc.cpp peta
{
    F_TipusFigura = NO_FIGURA;

    for (int i = 0; i < MAX_ALCADA - 2; i++)
    {
        for (int j = 0; j < MAX_AMPLADA - 2; j++)
        {
            F_Figura[i][j] = COLOR_NEGRE;
        }
    }

    F_Fila = 0;
    F_Columna = 0;
}
void Figura::inicialitzarF() // per a poder cridar al constructor des de fora
{
    Figura();
}


Figura::Figura(TipusFigura tipus, Gir gir, int fila, int columna)
//constructor per inicialitzar amb el que es pasa per parametres
{
    F_TipusFigura = tipus;
    F_Fila = fila;
    F_Columna = columna;
    for (int i = 0; i < MAX_ALCADA; i++)
    {
        for (int j = 0; j < MAX_AMPLADA; j++)
        {
            F_Figura[i][j] = COLOR_NEGRE;
        }
    }
}

void Figura::inicialitzarF(int tipus, int gir, int fila, int col)
{
    for (int i = 0; i < MAX_ALCADA; i++)
    {
        for (int j = 0; j < MAX_AMPLADA; j++)
        {
            F_Figura[i][j] = COLOR_NEGRE;
        }
    }
    Figura();
    F_Fila = fila;
    F_Columna = col;
    switch (tipus)
    {
    case 1: F_TipusFigura = FIGURA_O; break;
    case 2: F_TipusFigura = FIGURA_I; break;
    case 3: F_TipusFigura = FIGURA_T; break;
    case 4: F_TipusFigura = FIGURA_L; break;
    case 5: F_TipusFigura = FIGURA_J; break;
    case 6: F_TipusFigura = FIGURA_Z; break;
    case 7: F_TipusFigura = FIGURA_S; break;
    default: F_TipusFigura = NO_FIGURA; break;
    }

    switch (F_TipusFigura)
    {
    case FIGURA_O:
        for (int i = 1; i < MAX_ALCADA - 1; i++)
        {
            for (int j = 1; j < MAX_AMPLADA - 1; j++)
            {
                F_Figura[i][j] = COLOR_GROC;
            }
        }
        break;
    case FIGURA_I:
        for (int i = 0; i < MAX_ALCADA; i++)
        {
            for (int j = 0; j < MAX_AMPLADA; j++)
            {
                if (i == 1)
                {
                    F_Figura[i][j] = COLOR_BLAUCEL;
                }
                else
                    F_Figura[i][j] = COLOR_NEGRE;
            }
        }
        break;

    case FIGURA_T:
        for (int i = 0; i < MAX_ALCADA; i++)
        {
            for (int j = 0; j < MAX_AMPLADA; j++)
            {
                if ((i == 1 && j > 0) || (i == 0 && j == 2))
                {
                    F_Figura[i][j] = COLOR_MAGENTA;
                }
                else
                    F_Figura[i][j] = COLOR_NEGRE;
            }
        }
        break;
    case FIGURA_L:
        for (int i = 0; i < MAX_ALCADA; i++)
        {
            for (int j = 0; j < MAX_AMPLADA; j++)
            {
                if ((i == 1 && j > 0) || (i == 0 && j == 3))
                {
                    F_Figura[i][j] = COLOR_TARONJA;
                }
                else
                    F_Figura[i][j] = COLOR_NEGRE;
            }
        }
        break;
    case FIGURA_J:
        for (int i = 0; i < MAX_ALCADA; i++)
        {
            for (int j = 0; j < MAX_AMPLADA; j++)
            {
                if ((i == 1 && j > 0) || (i == 0 && j == 1))
                {
                    F_Figura[i][j] = COLOR_BLAUFOSC;
                }
                else
                    F_Figura[i][j] = COLOR_NEGRE;
            }
        }
        break;
    case FIGURA_Z:
        for (int i = 0; i < MAX_ALCADA; i++)
        {
            for (int j = 0; j < MAX_AMPLADA; j++)
            {
                if ((i == 1 && j > 1) || (i == 0 && j != 3 && j != 0))
                {
                    F_Figura[i][j] = COLOR_VERMELL;
                }
                else
                    F_Figura[i][j] = COLOR_NEGRE;
            }
        }
        break;
    case FIGURA_S:
        for (int i = 0; i < MAX_ALCADA; i++)
        {
            for (int j = 0; j < MAX_AMPLADA; j++)
            {
                if ((i == 1 && j != 3 && j != 0) || (i == 0 && j > 1))
                {
                    F_Figura[i][j] = COLOR_VERD;
                }
                else
                    F_Figura[i][j] = COLOR_NEGRE;
            }
        }
        break;
    }


    for (int i = 0; i < gir; i++)
    {
        girHorari();
    }
}

void Figura::girHorari()
{
    ColorFigura temporal[MAX_ALCADA][MAX_AMPLADA]{};
    if (F_TipusFigura == FIGURA_I || F_TipusFigura == FIGURA_O)
    {
        int l = 0;
        for (int i = 0; i < MAX_ALCADA; i++)
        {
            int k = 3;
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
    else
    {
        int l = 1;
        for (int i = 0; i < MAX_ALCADA - 1; i++)
        {
            int k = 2;
            for (int j = 1; j < MAX_AMPLADA; j++)
            {
                temporal[i][j] = F_Figura[k][l];
                k--;
            }
            l++;
        }

        for (int i = 0; i < MAX_ALCADA - 1; i++)
        {
            for (int j = 1; j < MAX_AMPLADA; j++)
            {
                F_Figura[i][j] = temporal[i][j];
            }
        }


    }
}

void Figura::girAntiHorari()
{
    ColorFigura temporal[MAX_ALCADA][MAX_AMPLADA]{};
    if (F_TipusFigura == FIGURA_I || F_TipusFigura == FIGURA_O)
    {
        int l = 3;
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
    else
    {
        int l = 3;
        for (int i = 0; i < MAX_ALCADA - 1; i++)
        {
            int k = 0;
            for (int j = 1; j < MAX_AMPLADA; j++)
            {
                temporal[i][j] = F_Figura[k][l];
                k++;
            }
            l--;
        }

        for (int i = 0; i < MAX_ALCADA - 1; i++)
        {
            for (int j = 1; j < MAX_AMPLADA; j++)
            {
                F_Figura[i][j] = temporal[i][j];
            }
        }
    }

}
