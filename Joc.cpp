#include "Joc.h"

Joc::Joc()//constructor JOC
{
    J_tauler = Tauler();  //constructor Tractor
    J_figura = Figura();  //constructor 
}

void Joc::inicialitza(const string& nomFitxer)
{
    Joc m_joc;  //creem una classe joc, que conte la classe tauler i figura aswell.
    //incicialitzem a 0  amb constructors  LOCURAAAA

    ifstream fitxer;
    fitxer.open(nomFitxer);  //obrim fitxer 

    int fila, col;        //   ·/\   /\·
    Gir gir;             //    #'0'-'0'#      LibelUwUlaaaa!!!
    TipusFigura tipus;
    fitxer >> tipus >> fila >> col >> gir;

    J_figura.inicialitzarF(tipus, gir, fila, col);

    ColorFigura color[MAX_FILA][MAX_COL];
    for (int i = 0; i < MAX_FILA; i++)
    {
        for (int j = 0; j < MAX_COL; j++)
        {
            fitxer >> color[i][j];
        }
    }
    J_tauler.inicialitzarT(color[MAX_FILA][MAX_COL]);

    figuraTauler();

    fitxer.close();
}

void Joc::figuraTauler()
{
    int fil = J_figura.getFila();
    int col = J_figura.getColumna();

    int k = 0;
    for (int i = fil - 1; i < fil + 2; i++)   //aixo esta fet nomes per DIM=3
    {
        int l = 0;
        for (int j = col - 1; j < col + 2; j++)   //aixo esta fet nomes per DIM=3
        {
            //J_tauler.tauler[i][j] = J_figura.figura[k][l]; La guardo per si...
            J_tauler.setTauler(J_figura.getFigura(k, l), i, j);
            l++;
        }
        k++;
    }
}


bool Joc::giraFigura(DireccioGir direccio)
{

    if (direccio == GIR_HORARI)
        J_figura.girHorari();
    else
        J_figura.girAntiHorari();

    bool trobat = 0;
    int fila = J_figura.getFila();
    int columna = J_figura.getColumna();
    int i = fila - 1;
    while (i < i + MAX_ALCADA && !trobat)  //aixo esta fet nomes per DIM=3
    {
        int j = columna - 1;
        while (j < j + MAX_AMPLADA && !trobat)  //aixo esta fet nomes per DIM=3
        {
            if (J_tauler.getTauler(i, j) != NO_COLOR && J_figura.getFigura(i, j) != NO_COLOR)
            {
                trobat = 1;//lo que m'ha costat fer esta conclusió.
            }
            j++;
        }
        i++;
    }
    if (trobat)
    {
        if (direccio == GIR_HORARI)
            J_figura.girAntiHorari();
        else
            J_figura.girHorari();

        return 0;
    }
    else
    {
        figuraTauler();
        return 1;
    }
}
bool Joc::mouFigura(int dirX)
{
    int canvi;
    if (dirX == 1)
        canvi = 1;
    else
        canvi = -1;

    int fila = J_figura.getFila();
    int columna = J_figura.getColumna();
    bool trobat = 0;
    int i = fila - 1;
    while (i < i + MAX_ALCADA && !trobat)  //aixo esta fet nomes per DIM=3
    {

        int j = columna - 1 + canvi;
        while (j < j + MAX_AMPLADA && !trobat)  //aixo esta fet nomes per DIM=3
        {
            if (J_tauler.getTauler(i, j) != NO_COLOR && J_figura.getFigura(i, j) != NO_COLOR)
            {
                trobat = 1;  //lo que m'ha costat fer esta conclusió.
            }
            j++;
        }
        i++;
    }
    if (trobat)
        return 0;
    else
    {
        int canviarColumna;
        canviarColumna = J_figura.getColumna();
        canviarColumna = canviarColumna + canvi;
        J_figura.setColumna(canviarColumna);

        figuraTauler();
        return 1;
    }
}

int Joc::eliminarLinia()
{
    int liniesEliminades = 0;
    for (int i = 0; i < MAX_ALCADA; i++)
    {
        int j = 0;
        bool trobat = 0;
        while (!trobat && j < MAX_AMPLADA)
        {
            if (J_tauler.getTauler(i, j) == NO_COLOR)
            {
                trobat = 1;
            }
            else
                j++;
        }
        if (!trobat)
        {
            for (int k = i; k > 0; k++)
            {
                for (int l = 0; l < MAX_AMPLADA; l++)
                {
                    J_tauler.setTauler(J_tauler.getTauler(k - 1, l), k, l);
                }
            }
            liniesEliminades++;
            for (int p = 0; p < MAX_AMPLADA; p++)
            {
                J_tauler.setTauler(NO_COLOR, 0, p);
            }
        }
    }
    return liniesEliminades++;
}

int Joc::baixaFigura()
{
    bool trobat = 0;
    int i = J_figura.getFila();
    int columna = J_figura.getColumna();
    while (i < i + MAX_ALCADA && !trobat)  //aixo esta fet nomes per DIM=3
    {
        int j = columna - 1;
        while (j < j + MAX_AMPLADA && !trobat)  //aixo esta fet nomes per DIM=3
        {
            if (J_tauler.getTauler(i, j) != NO_COLOR && J_figura.getFigura(i, j) != NO_COLOR)
            {
                trobat = 1;//lo que m'ha costat fer esta conclusió.
            }
            j++;
        }
        i++;
    }
    if (trobat)
    {
        figuraTauler();
        int liniesEliminades = eliminarLinia();
        return liniesEliminades;
    }
    else
    {
        int canviarFila;
        canviarFila = J_figura.getFila();
        canviarFila = canviarFila + 1;
        J_figura.setFila(canviarFila);
        return 0;
    }
}

void Joc::escriuTauler(const string& nomFitxer)
{
    figuraTauler();
    ofstream fitxer;
    fitxer.open(nomFitxer);
    for (int i = 0; i < MAX_ALCADA; i++)
    {
        for (int j = 0; j < MAX_AMPLADA; j++)
        {
            fitxer << J_tauler.getTauler(i, j) << " ";
        }
        cout << endl;
    }
    fitxer.close();
}
