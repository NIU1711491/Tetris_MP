#ifndef JOC_H
#define JOC_H
#include "Tauler.h"
#include "Figura.h"
#include <string>
#include <fstream>
#include <iostream>
#include "Partida.h"
#include "InfoJoc.h"
#include "GraphicManager.h"


using namespace std;

class Joc
{
public:
	Joc();
	void inicialitza(const string& nomFitxer);
	bool giraFigura(DireccioGir direccio);
	bool mouFigura(int dirX);
	int baixaFigura();
	void escriuTauler(const string& nomFitxer);
	//fins aqui els que ens demanen a la primera entrega

	void deleteFigura();
	bool jocAcabat();
	void generarFigura();
	void dibuixarJoc();

	bool potMoure(int dirX);
	bool potBaixar();
	bool potGirar(DireccioGir direccio);

	int eliminarLinia();
	void figuraTauler();
private:
	Tauler J_tauler;
	Figura J_figura;
};

#endif
