#include "Joc.h"

#include <cstdlib>


Joc::Joc()
{
    J_tauler.inicialitzarT();
    J_figura.inicialitzarF();
}



void Joc::inicialitza(const string& nomFitxer)
{
    Joc m_joc;  //creem una classe joc, que conte la classe tauler i figura aswell.
    //incicialitzem a 0  amb constructors  LOCURAAAA

    ifstream fitxer(nomFitxer);

    J_tauler.inicialitzarT();
    int fila, col;        //   ·/\   /\·
    int gir;             //    #'0'-'0'#      LibelUwUlaaaa!!!
    int tipus;
    fitxer >> tipus >> fila >> col >> gir;
    if (tipus == 1 || tipus == 2)
    {
        col++;
    }
    if (tipus == 1)
    {
        fila--;
    }
    J_figura.inicialitzarF(tipus, gir, fila, col);

    int color[MAX_FILA][MAX_COL];
    for (int i = 0; i < MAX_FILA; i++)
    {
        for (int j = 0; j < MAX_COL; j++)
        {
            fitxer >> color[i][j];
        }
    }

    J_tauler.inicialitzarT(color);

    figuraTauler();

    fitxer.close();
}

void Joc::figuraTauler()
{
    int fil = (J_figura.getFila());
    int col = (J_figura.getColumna() + 1);
    int k = 0;

    for (int i = fil - 1; i <= fil + 2; i++)
    {
        int l = 0;
        for (int j = col - 2; j <= col + 1; j++)
        {
            if (J_tauler.getTauler(i, j) == COLOR_NEGRE)
            {
                J_tauler.setTauler(J_figura.getFigura(k, l), i, j);
            }
            l++;
        }
        k++;
    }

}

void Joc::deleteFigura()
{
    int fil = (J_figura.getFila());
    int col = (J_figura.getColumna() + 1);
    int k = 0;

    for (int i = fil - 1; i <= fil + 2; i++)
    {
        int l = 0;
        for (int j = col - 2; j <= col + 1; j++)
        {
            if (J_tauler.getTauler(i, j) == J_figura.getFigura(k, l))
            {
                J_tauler.setTauler(COLOR_NEGRE, i, j);
            }
            l++;
        }
        k++;
    }
}

bool Joc::potGirar(DireccioGir direccio)
{
    if (direccio == GIR_HORARI)
        J_figura.girHorari();
    else
        J_figura.girAntiHorari();

    int fil = J_figura.getFila();
    int col = (J_figura.getColumna() + 1);

    bool trobat = 1;

    int k = 0;
    int i = fil - 1;
    while (i <= fil + 2 && trobat)
    {

        int l = 0;
        int j = col - 2;
        while (j <= col + 1 && trobat)
        {
            if (J_tauler.getTauler(i, j) != COLOR_NEGRE && J_figura.getFigura(k, l) != COLOR_NEGRE)
            {
                trobat = 0;//No pot girar
            }
            j++;
            l++;
        }
        i++;
        k++;
    }
    return trobat;
}

bool Joc::giraFigura(DireccioGir direccio)
{
    bool pot;
    deleteFigura();
    pot = potGirar(direccio);
    if (!pot)
    {
        if (direccio == GIR_HORARI)
            J_figura.girAntiHorari();
        else
            J_figura.girHorari();

        figuraTauler();
        return 0;

    }
    else
    {

        figuraTauler();
        return 1;
    }

}

bool Joc::potMoure(int dirX)
{
    int fil = J_figura.getFila();
    int col = (J_figura.getColumna() + 1);

    bool trobat = 1;

    int k = 0;
    int i = fil - 1;
    while (i <= fil + 2 && trobat)
    {

        int l = 0;
        int j = col - 2;
        while (j <= col + 1 && trobat)
        {
            if (J_tauler.getTauler(i, j + dirX) != COLOR_NEGRE && J_figura.getFigura(k, l) != COLOR_NEGRE)
            {
                trobat = 0;//lo que m'ha costat fer esta conclusió.
            }
            j++;
            l++;
        }
        i++;
        k++;
    }
    return trobat;
}

bool Joc::mouFigura(int dirX)
{
    deleteFigura();
    if (!potMoure(dirX))
    {
        figuraTauler();
        return 0;
    }
    else
    {
        J_figura.setColumna(J_figura.getColumna() + dirX);
        figuraTauler();
        return 1;
    }
}

bool Joc::potBaixar()
{
    int fil = J_figura.getFila();
    int col = (J_figura.getColumna() + 1);

    bool trobat = 1;

    int k = 0;
    int i = fil - 1;
    while (i <= fil + 2 && trobat)
    {

        int l = 0;
        int j = col - 2;
        while (j <= col + 1 && trobat)
        {
            if (J_tauler.getTauler(i + 1, j) != COLOR_NEGRE && J_figura.getFigura(k, l) != COLOR_NEGRE)
            {
                trobat = 0;
            }
            j++;
            l++;
        }
        i++;
        k++;
    }
    return trobat;
}

int Joc::eliminarLinia()
{
    int liniesEliminades = 0;
    for (int i = 1; i < MAX_FILA; i++)
    {
        int j = 1;
        bool trobat = 1;
        while (trobat && j <= MAX_COL)
        {
            if (J_tauler.getTauler(i, j) == COLOR_NEGRE)
            {
                trobat = 0;
            }
                j++;
        }

        if (trobat)
        {
            for (int k = i; k > 0; k--)
            {
                for (int l = 1; l <= MAX_COL; l++)
                {
                    J_tauler.setTauler(J_tauler.getTauler(k - 1, l), k, l);
                }
            }
            
            for (int p = 1; p <= MAX_COL; p++)
            {
                J_tauler.setTauler(COLOR_NEGRE, 0, p);
            }
            liniesEliminades++;
        }
    }
    return liniesEliminades;
}

int Joc::baixaFigura()
{
    deleteFigura();
    if (!potBaixar())
    {
        figuraTauler();
        int liniesEliminades = eliminarLinia();
        return liniesEliminades;
    }
    else
    {
        J_figura.setFila(J_figura.getFila() + 1);
        figuraTauler();
        return -1;
    }
}

void Joc::escriuTauler(const string& nomFitxer)
{
    ofstream fitxer;
    fitxer.open(nomFitxer);
    for (int i = 0; i < MAX_FILA; i++)
    {
        for (int j = 1; j < MAX_COL + 1; j++)
        {
            fitxer << J_tauler.getTauler(i, j) << " ";
        }
        cout << endl;
    }
    fitxer.close();

    
}

bool Joc::jocAcabat()
{
    bool trobat = false;
    if (J_figura.getFila() - 1 <= 0)
    {
        trobat = true;
    }
    return trobat;
}

void Joc::generarFigura()
{
    int numAleatori = rand() % 7 +1;
    int girAleatori = (rand() % 4);
    J_figura.inicialitzaF(numAleatori, girAleatori, 0,5 );
}q

void Joc::dibuixarJoc()
{
    for (int i = 0; i < MAX_FILA; i++)
    {
        for (int j = 1; j < MAX_COL + 1; j++)
        {
            switch (J_tauler.getTauler(i, j))
            {
            case 1: GraphicManager::getInstance()->drawSprite(GRAFIC_QUADRAT_GROC, POS_X_TAULER + (i * MIDA_QUADRAT), POS_Y_TAULER + (j * MIDA_QUADRAT), false);
            case 2: GraphicManager::getInstance()->drawSprite(GRAFIC_QUADRAT_BLAUCEL, POS_X_TAULER + (i * MIDA_QUADRAT), POS_Y_TAULER + (j * MIDA_QUADRAT), false);
            case 3: GraphicManager::getInstance()->drawSprite(GRAFIC_QUADRAT_MAGENTA, POS_X_TAULER + (i * MIDA_QUADRAT), POS_Y_TAULER + (j * MIDA_QUADRAT), false);
            case 4: GraphicManager::getInstance()->drawSprite(GRAFIC_QUADRAT_TARRONGA, POS_X_TAULER + (i * MIDA_QUADRAT), POS_Y_TAULER + (j * MIDA_QUADRAT), false);
            case 5: GraphicManager::getInstance()->drawSprite(GRAFIC_QUADRAT_BLAUFOSC, POS_X_TAULER + (i * MIDA_QUADRAT), POS_Y_TAULER + (j * MIDA_QUADRAT), false);
            case 6: GraphicManager::getInstance()->drawSprite(GRAFIC_QUADRAT_VERMELL, POS_X_TAULER + (i * MIDA_QUADRAT), POS_Y_TAULER + (j * MIDA_QUADRAT), false);
            case 7: GraphicManager::getInstance()->drawSprite(GRAFIC_QUADRAT_VERD, POS_X_TAULER + (i * MIDA_QUADRAT), POS_Y_TAULER + (j * MIDA_QUADRAT), false
            }
        }
        cout << endl;
    }
    fitxer.close();
}
