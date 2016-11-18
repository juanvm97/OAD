
#include "Nodo.h"
#include "Lista.h"
#include <iostream>

using namespace std;

int main()
{
	Lista<int> MyList;

	int Num, el;

	cout << " -Numero de soldados: ";
	cin >> Num;

	for (int i = 0; i < Num; i++)
	{
		MyList.Push(i+1);
	}

	cout << " -Eleminar cada: ";
	cin >> el;

	MyList.Josephus(el);

	MyList.Print();

	return 0;
}