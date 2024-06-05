#include "Partida.h"
#include "GraphicManager.h"
#include "InfoJoc.h"

Partida::Partida()
{
    m_nivellActual = 0;
    m_puntuacio = 0;
    m_tempsActual = 0;
    m_acabar = false;
    m_velocitatJoc = 1;
    m_movimentNodes = nullptr;
    m_figureNodes = nullptr;
    m_nMoviment = m_movimentNodes;
    m_nFigures = m_figureNodes;
}

void Partida::inicialitza(int mode, const string& fitxerInicial, const string& fitxerFigures, const string& fitxerMoviments)
{
}

void Partida::actualitza(int mode, double deltaTime)
{

    GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
    GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false);

    m_tempsActual += deltaTime;
    if (mode == 0)
    {
        bool finalitzatFigura = false;
        int filesFetes = 0;
        int key = -1;
        if (Keyboard_GetKeyTrg(KEYBOARD_RIGHT))
            key = KEYBOARD_RIGHT;
        else if (Keyboard_GetKeyTrg(KEYBOARD_LEFT))
            key = KEYBOARD_LEFT;
        else if (Keyboard_GetKeyTrg(KEYBOARD_DOWN))
            key = KEYBOARD_DOWN;
        else if (Keyboard_GetKeyTrg(KEYBOARD_UP))
            key = KEYBOARD_UP;
        else if (Keyboard_GetKeyTrg(KEYBOARD_SPACE))
            key = KEYBOARD_SPACE;

        switch (key)
        {
        case KEYBOARD_RIGHT:
            m_joc.mouFigura(1);
            break;
        case KEYBOARD_LEFT:
            m_joc.mouFigura(0);
            break;
        case KEYBOARD_DOWN:
            m_joc.giraFigura(GIR_ANTI_HORARI);
            break;
        case KEYBOARD_UP:
            m_joc.giraFigura(GIR_HORARI);
            break;
        case KEYBOARD_SPACE:
            while (filesFetes!=-1)
                filesFetes = m_joc.baixaFigura();
            break;
        default:
            break;
        }

        if (m_tempsActual > m_velocitatJoc)
        {
            m_tempsActual = 0;
            filesFetes = m_joc.baixaFigura();
        }

        if (finalitzatFigura)
        {
            if (m_joc.jocAcabat())
                m_acabar = true;
            else
            {
                canviarPunts(filesFetes);
                m_joc.generarFigura();
                m_joc.dibuixarJoc();
            }
        }
    }
    else
    {
        if (m_tempsActual > m_velocitatJoc)
        {
            m_tempsActual = 0;
            bool acabat = false;
            int filesFetes = 0;
            if (m_nMoviment != nullptr)
            {
                TipusMoviment moviment = m_nMoviment->getValor();
                m_nMoviment->setNext(m_nMoviment->getNext());
                acabat = m_joc.moviment(moviment, filesFetes);
                if (acabat)
                {
                    m_joc.setFigura(m_nFigures->getValor());
                    m_nFigures->setNext(m_nFigures->getNext());
                }
                canviarPunts(filesFetes);
                m_joc.dibuixarJoc();
            }
        }
    }
}

void Partida::iniNMoviment(const string& fitxerMoviments)
{
    ifstream fitxer;
    fitxer.open(fitxerMoviments);
    if (fitxer.is_open())
    {
        int moviment;
        TipusMoviment tipusMoviment;
        fitxer >> moviment;
        while (!fitxer.eof())
        {
            switch (moviment)
            {
            case 0:
                tipusMoviment = MOVIMENT_ESQUERRA;
                break;
            case 1:
                tipusMoviment = MOVIMENT_DRETA;
                break;
            case 2:
                tipusMoviment = MOVIMENT_GIR_HORARI;
                break;
            case 3:
                tipusMoviment = MOVIMENT_GIR_ANTI_HORARI;
                break;
            case 4:
                tipusMoviment = MOVIMENT_BAIXA;
                break;
            case 5:
                tipusMoviment = MOVIMENT_BAIXA_TOTAL;
                break;
            }

            TipusMoviment* movimentNode = new TipusMoviment;
            movimentNode->setValor(tipusMoviment);
            movimentNode->setNext(nullptr);
            if (m_movimentNodes == nullptr)
                m_movimentNodes = movimentNode;
            else
            {
                bool trobat = false;
                TipusMoviment* seguent = m_movimentNodes;
                while (!trobat)
                {
                    if (seguent->getNext() == nullptr)
                    {
                        seguent->setNext(movimentNode);
                        trobat = true;
                    }
                    else
                        seguent = seguent->getNext();
                }
            }
            fitxer >> moviment;
        }
    }
}

void Partida::iniNFigura(const string& fitxerFigures)
{
    ifstream fitxer;
    fitxer.open(fitxerFigures);
    if (fitxer.is_open())
    {
        int tipus, fila, columna, codiGir;
        fitxer >> tipus;
        while (!fitxer.eof())
        {
            fitxer >> fila >> columna >> codiGir;
            Figura figura;
            TipusFigura* figuraNode = new NodeFigura;
            figura.inicialitza(tipus, fila, columna, codiGir);
            figuraNode->setValor(figura);
            figuraNode->setNext(nullptr);
            if (m_figureNodes == nullptr)
                m_figureNodes = figuraNode;
            else
            {
                bool trobat = false;
                TipusFigura* seguent = m_figureNodes;
                while (!trobat)
                {
                    if (seguent->getNext() == nullptr)
                    {
                        seguent->setNext(figuraNode);
                        trobat = true;
                    }
                    else
                        seguent = seguent->getNext();
                }
            }
            fitxer >> tipus;
        }
    }
    fitxer.close();
}

void Partida::canviarPunts(int filesFetes)
{
    switch (filesFetes)
    {
    case 0:
        m_puntuacio += 10;
        break;
    case 1:
        m_puntuacio += 100;
        break;
    case 2:
        m_puntuacio += 150;
        break;
    case 3:
        m_puntuacio += 175;
        break;
    case 4:
        m_puntuacio += 200;
        break;
    }

    if (m_puntuacio - 1000 * m_nivellActual > 1000)
    {
        m_velocitatJoc -= 0.1;
        m_nivellActual++;
    }
}
