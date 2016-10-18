
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Tablero.h"
#include "Jugador.h"

using namespace std;

int main()
{
	int Numero_Jugadores;
	bool Fin_Juego = false;

	cout << " -Ingresa el numero de jugadores: ";
	cin >> Numero_Jugadores;

	Tablero Ta;
	Jugador Ju[Numero_Jugadores];

	for (int i = 0; i < Numero_Jugadores; i++)
	{
		Ju[i].Inicio(Ta.GetTablero());
		while (getchar() != 10){}	
	}
	system("/usr/bin/clear");

	while (!Fin_Juego)
	{
		for (int i = 0; i < Numero_Jugadores; i++)
		{
			Ta.Print(Ju, Numero_Jugadores);
			Ju[i].Mover(Ta.GetTablero());
			Ta.Print(Ju, Numero_Jugadores);
			if (Ju[i].GetGanar())
			{
				Fin_Juego = true;
				cout << "  ---Gano el jugador " << Ju[i].GetImg() << "!!" << endl;
			}
			while (getchar() != 10){}
			system("/usr/bin/clear");
		}
	}	

	return 0;
}