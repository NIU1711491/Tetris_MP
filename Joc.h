v#ifndef JOC_H
#define JOC_H
#include "Tauler.h"
#include "Figura.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Joc
{
public:
	Joc();
	Joc(ColorFigura J_tauler);
	void inicialitza(const string& nomFitxer);
	bool giraFigura(DireccioGir direccio);
	bool mouFigura(int dirX);
	int baixaFigura();
	void escriuTauler(const string& nomFitxer);
	//fins aqui els que ens demanen a la primera entrega

	int eliminarLinia();
	void figuraTauler();
private:
	Tauler J_tauler;
	Figura J_figura;
};

#endif
