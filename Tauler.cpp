#include "Tauler.h"

Tauler::Tauler()
{
    for (int i = 0; i < MAX_FILA ; i++)
    {
        for (int j = 1; j < MAX_COL+1; j++)
        {
            T_tauler[i][j] = COLOR_NEGRE;
        }
    }

    for (int j = 0; j < MAX_COL+2; j++)
    {
        T_tauler[8][j] = NO_COLOR;
    }

    for (int i = 0; i < MAX_FILA; i++)
    {
        T_tauler[i][0] = NO_COLOR;
    }

    for (int i = 0; i < MAX_FILA; i++)
    {
        T_tauler[i][9] = NO_COLOR;
    }
}
void Tauler::inicialitzarT()
{
    Tauler();
}

Tauler::Tauler(ColorFigura taulerInicial[][MAX_COL])
{
    for (int i = 0; i < MAX_FILA; i++)
    {
        for (int j = 0; j < MAX_COL; j++)
        {
            T_tauler[i][j] = taulerInicial[i][j];
        }
    }
}

void Tauler::inicialitzarT(int color[MAX_FILA][MAX_COL])
{
    for (int i = 0; i < MAX_FILA; i++)
    {
        for (int j = 1; j < MAX_COL+1; j++)
        {
            switch (color[i][j-1])
            {
            case 0: T_tauler[i][j] = COLOR_NEGRE; break;
            case 1: T_tauler[i][j] = COLOR_GROC; break;
            case 2: T_tauler[i][j] = COLOR_BLAUCEL; break;
            case 3: T_tauler[i][j] = COLOR_MAGENTA; break;
            case 4: T_tauler[i][j] = COLOR_TARONJA; break;
            case 5: T_tauler[i][j] = COLOR_BLAUFOSC; break;
            case 6: T_tauler[i][j] = COLOR_VERMELL; break;
            case 7: T_tauler[i][j] = COLOR_VERD; break;
            default: T_tauler[i][j] = NO_COLOR; break;
            }
        }
    }
}
