
#include "Pila.h"

using namespace std;

template <typename T>
Pila<T>::Pila()
{
    Primero = NULL;
    Ultimo = NULL;
}

template <typename T>
void Pila<T>::Push(T Dato)
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
void Pila<T>::Pop()
{
	Nodo<T> *temp = Primero;
	while (temp->Siguiente != Ultimo)
		temp = temp->Siguiente;

	Ultimo = temp;
}

template <typename T>
void Pila<T>::Print()
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
            cout << "   ->" << x->Dato << endl;
            x=x->Anterior;
        }
    }
}

template class Pila<int>;
template class Pila<double>;