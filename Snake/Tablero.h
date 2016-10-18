
#ifndef Tablero_H
#define Tablero_H

#include "controljuego.h"

class Tablero
{
private:
	int x;
	int y;
	int** Map;

public:
	Tablero(int _x, int _y);
	~Tablero();
	int GetX() { return x; }
	int GetY() { return y; }
	int GetMap(int _x, int _y) { return Map[_x][_y]; }
	void SetMap(int _x, int _y, int v) { Map[_x][_y] = v; }
	void Print(ControlJuego control);
	void Restablecer();
};


#endif // Tablero_H