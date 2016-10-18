#ifndef PILA_H
#define PILA_H

#include <iostream>
#include "Nodo.h"

template <typename T> class Pila
{
    public:
        Pila();
        void Push(T Dato);
        void Pop();
        void Print();

    protected:
    private:
    	Nodo<T> *Primero;
        Nodo<T> *Ultimo;
};

#endif // PILA_H