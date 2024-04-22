#ifndef TAULER_H
#define TAULER_H
#include "Figura.h"

const int MAX_FILA = 8;
const int MAX_COL = 8;

class Tauler
{
public:
    //constructors
    Tauler();
    Tauler(ColorFigura taulerInicial[][MAX_COL]);
    
    //geters i seters
    void setTauler(ColorFigura color, int i, int j) {T_tauler[i][j]=color;}
    ColorFigura getTauler(int i, int j) {return T_tauler[i][j];}
    void inicialitzarT(ColorFigura color[MAX_FILA][MAX_COL]);
    
private:
    ColorFigura T_tauler[MAX_FILA][MAX_COL];
};
#endif
