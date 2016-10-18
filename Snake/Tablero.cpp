
#include "Tablero.h"
#include <iostream>
#include <string>
#include <ncurses.h>

Tablero::Tablero(int _x, int _y)
{
	x = _x;
	y = _y;

	Map = new int* [y];

	for (int i = 0; i < y; i++)
	{
		Map[i] = new int[x];
	}

	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if ((i == 0) or (j == 0) or (j == x-1) or (i == y-1))
			{
				Map[i][j] = 1;
			}

			else
				Map[i][j] = 0;
		}
	}
}

Tablero::~Tablero()
{

}

void Tablero::Print(ControlJuego control)
{
	wclear(control.getPantJuego());
	for (int i = 0; i < x; i++)
	{ 
		for (int j = 0; j < y; j++)
		{
			if (Map[i][j] == 0) //Espacio
				mvwprintw(control.getPantJuego(),i, 2*j, "  ");
			
			else if (Map[i][j] == 1) //Parede
				mvwprintw(control.getPantJuego(),i, 2*j , "[]");

			else if (Map[i][j] == 2) //Bolita
				mvwprintw(control.getPantJuego(),i, 2*j , "<>");

			else if (Map[i][j] >= 3)
				mvwprintw(control.getPantJuego(),i, 2*j, "()");
		}
	}
	wrefresh(control.getPantJuego());
}

void Tablero::Restablecer()
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (Map[i][j] > 1)
				Map[i][j] = 0;
		}
	}	
}
