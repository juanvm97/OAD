
#include "Lista.h"
#include <iostream>

using namespace std;

template <typename T>
Lista<T>::Lista()
{
    Primero = NULL;
    Ultimo = NULL;
}

template <typename T>
void Lista<T>::Push(T Dato)
{
    if (!Primero)
    {
        Primero = new Nodo<T>(Dato);
        Ultimo = Primero;
    }

    else
    {
        Ultimo->Siguiente = new Nodo<T>(Dato);
        Ultimo->Siguiente->Siguiente = Primero;
        Ultimo->Siguiente->Anterior = Ultimo;
        Ultimo = Ultimo->Siguiente;
        Primero->Anterior = Ultimo;
    }
}

template <typename T>
int Lista<T>::Size()
{
    Nodo<T> *Temp = Primero;
    
    if(!Primero)
    {
        return 0;
    }

    else
    {
        int S = 0;
        do
        {
            S++;
            Temp = Temp->Siguiente;
        }while(Temp != Ultimo->Siguiente);
    
        return S;
    }
}

template <typename T>
void Lista<T>::Remove(const int pos)
{
    Nodo<T> *Temp = Primero;

    if (Size() <= 1)
    {
        Primero = NULL;
        Ultimo = NULL;
        return;
    }

    for (int i=1; i<pos; i++)
        Temp = Temp->Siguiente;

    if (Temp == Primero)
    {
        Primero = Primero->Siguiente;
    }

    else if (Temp == Ultimo)
    {
        Ultimo = Ultimo->Anterior;
    }

    Temp->Anterior->Siguiente = Temp->Siguiente;
    Temp->Siguiente->Anterior = Temp->Anterior;
}


template <typename T>
void Lista<T>::Print()
{
    Nodo<T> *Temp = Primero;
    
    if(!Primero)
    {
        cout << " Esta vacia" << endl;
    }

    else
    {
        do
        {
            cout << "   ->" << Temp->Dato << endl;
            Temp = Temp->Siguiente;
        }while(Temp != Ultimo->Siguiente);
    }
}

template <typename T>
void Lista<T>::Josephus(int Num)
{
    int tam = Size() - 2;
    Nodo<T> *Temp = Primero->Anterior;

    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < Num; j++)
        {
            Temp = Temp->Siguiente;
        }
        
        if (Temp == Primero)
            Primero = Primero->Siguiente;
        

        else if (Temp == Ultimo)
            Ultimo = Ultimo->Anterior;

        Temp->Anterior->Siguiente = Temp->Siguiente;
        Temp->Siguiente->Anterior = Temp->Anterior;
    }  
}

template <typename T>
Lista<T>::~Lista()
{}

template class Lista<int>;