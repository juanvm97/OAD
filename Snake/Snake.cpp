
#include "Snake.h"
#include <iostream>

#include <ncurses.h>
#include <unistd.h>

//GetMap
Snake::Snake(Tablero Ta)
{
	Tamano = 3;
	Direccion = KEY_DOWN;
	Vivo = true;
	CaX = 3;
	CaY = 1;
	CoX = 1;
	CoY = 1;

	for (int i = 0; i < Tamano; i++)
	{
		Ta.SetMap(CoX + i, CoY, i+3);
	}

}

void Snake::Comer(Tablero Ta)
{
	Tamano+=1;

	for (int i = 0; i < Ta.GetX(); i++)
	{ 
		for (int j = 0; j < Ta.GetY(); j++)
		{
			if (Ta.GetMap(i, j) >= 3)
			{
				Ta.SetMap(i, j, Ta.GetMap(i, j)+1);
			}
		}
	}	
}

void Snake::RevPared(Tablero Ta, int  _X, int _Y)
{
	if ((Ta.GetMap(CaX + _X, CaY + _Y) == 0) or (Ta.GetMap(CaX + _X, CaY + _Y) == 2))
	{
		Vivo = true;

		ModificarT(Ta, _X, _Y);
	}
	else
	{	
		Vivo = false;
		return;
	}
}

void Snake::ModificarT(Tablero Ta, int _X, int _Y)
{
	//Ta.SetMap(CoX, CoY, 0);
/*
    for (int i=-1; i<2; i++)
    {
    	for (int j=-1; j<2; j++)
     	{
     		if (Ta.GetMap(CoX+i, CoY+j) == 4)
     		{
     			CoX += i;
     			CoY += j;
     		}
      	}
    }
*/

	for (int i = 0; i < Ta.GetX(); i++)
	{ 
		for (int j = 0; j < Ta.GetY(); j++)
		{
			if (Ta.GetMap(i, j) == 3)
			{
				Ta.SetMap(i, j, 0);
			}

			else if (Ta.GetMap(i, j) > 3)
			{
				Ta.SetMap(i, j, Ta.GetMap(i, j)-1);
			}
		}
	}

	if (Ta.GetMap(CaX + _X, CaY + _Y) == 2)
	{
		Comer(Ta);
	}

	Ta.SetMap(CaX + _X, CaY + _Y, Tamano+2);
	CaX += _X;
	CaY += _Y;
}

void Snake::Mov(Tablero Ta, int Tecla)
{
	if (Tecla == KEY_UP)
	{
		if (Direccion != KEY_DOWN)
		{
			RevPared(Ta, -1, 0);
			if (Vivo)
				Direccion = KEY_UP;	
		}
			
		else if (Direccion == KEY_DOWN)
		{
			RevPared(Ta, 1, 0);
			if (Vivo)
				Direccion = KEY_DOWN;			
		}
			
	}
	else if (Tecla == KEY_DOWN)
	{
		if (Direccion != KEY_UP)
		{
			RevPared(Ta, +1, 0);
			if (Vivo)
				Direccion = KEY_DOWN;
		}
		else if (Direccion == KEY_UP)
		{
			RevPared(Ta, -1, 0);
			if (Vivo)
				Direccion = KEY_UP;			
		}
	}

	else if (Tecla == KEY_RIGHT)
	{
		if (Direccion != KEY_LEFT)
		{
			RevPared(Ta, 0, +1);
			if (Vivo)
				Direccion = KEY_RIGHT;
		}
		
		else if (Direccion == KEY_LEFT)
		{
			RevPared(Ta, 0, -1);
			if (Vivo)
				Direccion = KEY_LEFT;			
		}
	}

	else if (Tecla == KEY_LEFT)
	{
		if (Direccion != KEY_RIGHT)
		{
			RevPared(Ta, 0, -1);
			if (Vivo)
				Direccion = KEY_LEFT;
		}
		else if (Direccion == KEY_RIGHT)
		{
			RevPared(Ta, 0, +1);
			if (Vivo)
				Direccion = KEY_RIGHT;			
		}		
	}
}

void Snake::Restablecer(Tablero Ta)
{
	Tamano = 3;
	Vivo = true;
	CaX = 3;
	CaY = 1;
	CoX = 1;
	CoY = 1;

	for (int i = 0; i < Tamano; i++)
	{
		Ta.SetMap(CoX + i, CoY, i+3);
	}
}

Snake::~Snake()
{

}