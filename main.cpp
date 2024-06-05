//
//  main.cpp
//
//  Copyright � 2018 Compiled Creations Limited. All rights reserved.
//

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined  (_WIN64)

#include <iostream>
//Definicio necesaria per poder incloure la llibreria i que trobi el main
#define SDL_MAIN_HANDLED
#include <windows.h>
//Llibreria grafica
#include "../Graphic Lib/libreria.h"
#include "../Graphic Lib/NFont/NFont.h"
#include <conio.h>      /* getch */ 

#elif __APPLE__
//Llibreria grafica
#include "../Graphic Lib/libreria.h"
#include "../Graphic Lib/NFont/NFont.h"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"
#include <SDL2/SDL.h>
#pragma clang diagnostic pop

#endif

#include "./Partida.h"
#include "./InfoJoc.h"
#include "../../2. Platforms/0. Windows Desktop/Tetris.h"


int main(int argc, const char* argv[])
{
    SDL_SetMainReady();
    SDL_Init(SDL_INIT_VIDEO);
    Screen pantalla(SCREEN_SIZE_X, SCREEN_SIZE_Y);
    pantalla.show();

    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;

    double deltaTime = 0;
    Tetris tetris;
    int i = 0;
    int opcio, mode;
    string fitxerInicial = "", fitxerFigures = "", fitxerMoviments = "", fitxerPuntuacions = "./data/Games/puntuacions.txt";
    opcio = tetris.mostraMenu();
    if (opcio == 1 || opcio == 2)
    {
        tetris.inicialitzaJoc(mode, fitxerInicial, fitxerFigures, fitxerMoviments);
    }
    do
    {
        if (opcio == 1)
        {
            mode = 0;
        }
        else if (opcio == 2)
        {
            mode = 1;
        }
        LAST = NOW;
        NOW = SDL_GetPerformanceCounter();
        deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());
        pantalla.processEvents();
        bool acabat = tetris.juga(mode, deltaTime);
        pantalla.update();
        if (acabat)
        {
            if (i > 10)
            {
                if (mode == 0)
                {
                    tetris.mostraPuntuacions();
                }
                opcio = tetris.mostraMenu();
                i = 0;
                acabat = false;
                if (opcio == 1 || opcio == 2)
                {
                    tetris.inicialitzaJoc(mode, fitxerInicial, fitxerFigures, fitxerMoviments);
                }
            }
            i++;
        }

    } while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE) && opcio != 4);
    SDL_Quit();
    return 0;
}
