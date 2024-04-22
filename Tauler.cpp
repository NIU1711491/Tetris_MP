#include "Tauler.h"

Tauler::Tauler()
{
    for (int i = 0; i < MAX_FILA; i++)
    {
        for (int j = 0; j <MAX_COL; j++)
        {
            T_tauler[i][j]=NO_COLOR;
        }
    }
}
Tauler::Tauler(ColorFigura taulerInicial[][MAX_COL])
{
    for (int i = 0; i < MAX_FILA; i++)
    {
        for(int j = 0 ; j < MAX_COL; j++)
        {
            T_tauler[i][j]=taulerInicial[i][j];
        }
    }
}

void Tauler::inicialitzarT(ColorFigura color[MAX_FILA][MAX_COL])
{
    Tauler(color[MAX_FILA][MAX_COL]);
}
