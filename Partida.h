#ifndef PARTIDA_H
#define PARTIDA_H

#define PARTIDA_H
#include <stdio.h>
#include "InfoJoc.h"
#include "Joc.h"
#include <string>
using namespace std;

typedef enum
{
	MOVIMENT_ESQUERRA = 0,
	MOVIMENT_DRETA,
	MOVIMENT_GIR_HORARI,
	MOVIMENT_GIR_ANTI_HORARI,
	MOVIMENT_BAIXA,
	MOVIMENT_BAIXA_TOTAL
} TipusMoviment;

class Partida
{
public:
	Partida();
	void inicialitza(int mode, const string& fitxerInicial, const string& fitxerFigures, const
		string& fitxerMoviments);
	void actualitza(int mode, double deltaTime);
	void iniNMoviment(const string& fitxerMoviments);
	void iniNFigura(const string& fitxerFigures);
	void canviarPunts(int filesFetes);
	bool acaba() const { return m_acabar; }
	int getNivellActual() const { return m_nivellActual; }
	int getPuntuacio() const { return m_puntuacio; }
	bool getPartidaAcabada() const { return m_acabar; }
private:
	double m_tempsActual;
	double m_velocitatJoc;
	int m_nivellActual;
	int m_puntuacio;
	bool m_acabar;
	Joc m_joc;
	TipusMoviment* m_movimentNodes;
	TipusMoviment* m_nMoviment;
	TipusFigura* m_figureNodes;
	TipusFigura* m_nFigures;
};

#endif