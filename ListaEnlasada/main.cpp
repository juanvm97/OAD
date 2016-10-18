
#include <iostream>
#include "Lista.h"

using namespace std;

void Menu()
{
    cout << " 1.-Insertar" << endl;
    cout << " 2.-Imprimir" << endl;
    cout << " 3.-Invertir" << endl;
    cout << " 4.-Eliminar" << endl;
    cout << " 0.-Salir" << endl;
}

int main()
{
    Menu();

    int hacer=0;

    Lista L;

    do
    {
        cout << " Hacer: ";
        cin >> hacer;
        if (hacer == 1)
        {
            int da;
            cout << "  Numero: ";
            cin >> da;
            L.Insert(da);
        }

        else if (hacer == 2)
        {
            L.Print();
        }

        else if (hacer == 3)
        {
            L.Invertir();
        }

        else if (hacer == 4)
        {
            L.Eliminar();
        }

    } while(hacer != 0);

    return 0;
}
