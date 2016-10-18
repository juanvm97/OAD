
#include "Cola.h"

using namespace std;

template <typename T>
Cola<T>::Cola()
{
    Primero = NULL;
    Ultimo = NULL;
}

template <typename T>
void Cola<T>::Push(T Dato)
{
    if (!Primero)
    {
        Primero = new Nodo<T>(Dato);
        Ultimo = Primero;
    }

    else
    {
        Ultimo->Siguiente = new Nodo<T>(Dato);
        Ultimo->Siguiente->Anterior = Ultimo;
        Ultimo = Ultimo->Siguiente;
    }
}

template <typename T>
void Cola<T>::Pop()
{
	Primero = Primero->Siguiente;
}

template <typename T>
void Cola<T>::Print()
{
    Nodo<T> *x = Ultimo;
    if(!Ultimo)
    {
        cout << " Esta vacia" << endl;
    }

    else
    {
        while(x != Primero->Anterior)
        {
            cout << "   -" << x->Dato << endl;
            x=x->Anterior;
        }
    }
}

template class Cola<int>;