
#include "Tablero.h"
#include <iostream>

using namespace std;

Tablero::Tablero()
{
	tab = new int[63];
	for (int i = 0; i < 63; i++)
		*(tab+i) = i+1;	
}

void Tablero::Print(Jugador *Ju, int Tam)
{
	int cont = 0;
	bool espacio = true;
	cout << endl;
	for (int i = 0; i < 63; i++)
	{	
		if (cont%9 == 0)
			cout << endl << "           | "; 

		for (int j = 0; j < Tam; j++)
		{
			if ((Ju+j)->GetPos() == *(tab+i))
			{
				cout << (Ju+j)->GetImg() <<" ";
				espacio = false;
			}
		}

		if ((i == 4) or (i == 8))
		{
			cout << "Oca";
			espacio = false;
		}

		if ((i == 5) or (i == 11))
		{
			cout << "Puente";
			espacio = false;
		}

		else if (i ==  18)
		{
			cout << "Posada";
			espacio = false;
		}

		else if (i ==  30)
		{
			cout << "Pozo";
			espacio = false;
		}

		else if ((i ==  25) or (i == 52))
		{
			cout << "Dados";
			espacio = false;
		}

		else if (i ==  41)
		{
			cout << "Laberinto";
			espacio = false;
		}

		else if (i == 51)
		{
			cout << "Carcel";
			espacio = false;
		}
		
		else if (i == 57)
		{
			cout << "Muerte :X";
			espacio = false;
		}

		if (espacio)
			cout << *(tab+i);

		cout << " | ";

		espacio = true;
		cont++;
	}
	cout << endl << endl;
}

Tablero::~Tablero()
{

}