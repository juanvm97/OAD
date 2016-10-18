
#include "Jugador.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

Jugador::Jugador()
{
	puntero = NULL;
	img = 'x';
	turnosPerdidos = 0;
	ganar = false;
}

void Jugador::Inicio(int *tab)
{
	puntero = tab; 
	cout << "  -Ingrese una letra: ";
	cin >> img;
}

void Jugador::Mover(int *tab)
{
	srand (time(NULL));

	if (turnosPerdidos == 0)
	{
		cout << " -Es el turno del jugador " << img << " Precione enter para tirar el dado";

		while (getchar() != 10){}

		int num = rand()%6+1;
		cout << "   -Te toco un " << num << endl;
		
		if (*puntero+num == 63)
		{
			ganar = true;
			puntero = (puntero + num);
			return;
		}

		if (*puntero+num > 63)
			puntero = tab+62-(*(puntero)+num-63);
		

		else
			puntero = (puntero + num);

		if (*puntero+num < 63)
		{
			puntero = (puntero + num);

			if (*puntero == 5) //Oca
			{
				cout << "   -Estas en la Oca, vuelve a tirar" << endl;
				puntero = tab+8;	
				Jugador::Mover(tab);
			}
		
			else if (*puntero == 9) //Oca
			{
				cout << "   -Estas en la Oca, vuelve a tirar" << endl;
				puntero = tab+4;	
				Jugador::Mover(tab);
			}

			else if (*puntero == 6) //Puente
			{
				cout << "   -Estas en un puente, vuelve a tirar" << endl;
				puntero = tab+11;	
				Jugador::Mover(tab);
			}
		
			else if (*puntero == 12) //Puente
			{
				cout << "   -Estas en un puente, vuelve a tirar" << endl;
				puntero = tab+5;	
				Jugador::Mover(tab);
			}

			else if (*puntero == 19) //Posada
			{
				cout << "   -Caiste en la posada, pierdes 2 turnos";
				turnosPerdidos = 2;
			}

			else if (*puntero == 31) //Pozo
			{
				cout << "   -Caiste en el pozo, pierdes 2 turnos";
				turnosPerdidos = 2;
			}

			else if ((*puntero ==  26) or (*puntero == 53)) //Dados
			{
				cout << "   -Estas en los dados, vuelve a tirar" << endl;
				Jugador::Mover(tab);
			}

			else if (*puntero ==  42) //Laberinto
			{
				cout << "   -Caiste en el laberinto retrocedes hasta la casilla 30" << endl;
				puntero = tab+29;
			}

			else if (*puntero == 52) //Carcel
			{
				cout << "   -Caiste en la carcel, pierdes 3 turnos";
				turnosPerdidos = 3;
			}

			else if (*puntero == 58) //Muerte
			{
				cout << "   -Regresa al comiezo :(" << endl;
				puntero = tab;
			}
		}
	}

	else
	{
		cout << "  -El jugador " << img << " No juega por: " << turnosPerdidos << endl;
		turnosPerdidos--;
	}
}

Jugador::~Jugador()
{

}