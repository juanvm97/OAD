
#ifndef Bolita_H
#define Bolita_H

#include "Tablero.h"

#include <stdlib.h>
#include <time.h>

class Bolita
{
private:
	int x;
	int y;
public:
	Bolita(Tablero Ta)
	{
		srand (time(NULL));	
		do
		{
			x=rand()%Ta.GetX();
			y=rand()%Ta.GetY();
		}
		while (Ta.GetMap(x, y) != 0);
		Ta.SetMap(x, y, 2);	
	}

	void CrearBolita(Tablero Ta)
	{
		srand (time(NULL));	
		do
		{
			x=rand()%Ta.GetX();
			y=rand()%Ta.GetY();
		}
		while (Ta.GetMap(x, y) != 0);
		Ta.SetMap(x, y, 2);	
	}

	void RevisarT(Tablero Ta)
	{
		if (Ta.GetMap(x, y) != 2)
		{
			CrearBolita(Ta);
		}
	}
};

#endif // Bolita_H 