
#ifndef Snake_H
#define Snake_H

#include "Tablero.h"

class Snake
{
private:
	int Tamano;
	int CaX;
	int CaY;
	int CoX;
	int CoY;
	bool Vivo;
	int Direccion;

public:
	Snake(Tablero Ta);
	bool GetVivo() { return Vivo; }
	void Comer(Tablero Ta);
	void RevPared(Tablero Ta, int  _X, int _Y);
	void ModificarT(Tablero Ta, int _X, int _Y);
	void Mov(Tablero Ta, int Tecla);
	void Restablecer(Tablero Ta);
	~Snake();

};

#endif // Snake_H