#ifndef TABLERO_H
#define TABLERO_H

#include "Jugador.h"

class Tablero
{
private: 
	int *tab;

public:
	Tablero();
	void Print(Jugador *Ju, int Tam);
	int* GetTablero() { return tab; }
	~Tablero();
};

#endif // TABLERO_H