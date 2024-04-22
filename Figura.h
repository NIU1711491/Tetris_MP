#ifndef FIGURA_H
#define FIGURA_H

const int MAX_ALCADA = 4;
const int MAX_AMPLADA = 4;

typedef enum
{
    COLOR_NEGRE = 0,
    COLOR_GROC,
    COLOR_BLAUCEL,
    COLOR_MAGENTA,
    COLOR_TARONJA,
    COLOR_BLAUFOSC,
    COLOR_VERMELL,
    COLOR_VERD,
    NO_COLOR
} ColorFigura;


typedef enum
{
    NO_FIGURA = 0,
    FIGURA_O,
    FIGURA_I,
    FIGURA_T,
    FIGURA_L,
    FIGURA_J,
    FIGURA_Z,
    FIGURA_S,
} TipusFigura;



typedef enum
{
    GIR_HORARI = 0,
    GIR_ANTI_HORARI
} DireccioGir;

typedef enum
{
    NORD = 0,
    EST,
    SUD,
    OEST,
    NO_GIR,
} Gir;

class Figura
{
public:
    //constructors:
    Figura();
    Figura(TipusFigura tipus, Gir gir, int fila, int columna);
    void inicialitzarF(TipusFigura tipus, Gir gir, int fila, int col);


    //seters i geters:
    void setTipus(TipusFigura tipus) { F_TipusFigura = tipus; }
    void setGir(Gir gir) { F_Gir = gir; }
    void setFigura(ColorFigura color, int i, int j) { F_Figura[i][j] = color; }
    void setFila(int fila) { F_Fila = fila; }
    void setColumna(int columna) { F_Columna = columna; }

    TipusFigura getTipus() { return F_TipusFigura; }
    Gir getGir() { return F_Gir; }
    ColorFigura getFigura(int i, int j) { return F_Figura[i][j]; }
    int getFila() { return F_Fila; }
    int getColumna() { return F_Columna; }


    void girHorari();
    void girAntiHorari();
private:
    TipusFigura F_TipusFigura;
    Gir F_Gir;
    ColorFigura F_Figura[MAX_ALCADA][MAX_AMPLADA];
    int F_Fila;
    int F_Columna;
    int F_Alcada;
    int F_Amplada;
};


#endif
