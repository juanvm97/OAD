#ifndef COLA_H
#define COLA_H

#include <iostream>
#include "Nodo.h"

template <typename T> class Cola
{
    public:
        Cola();
        void Push(T Dato);
        void Pop();
        void Print();

    protected:
    private:
    	Nodo<T> *Primero;
        Nodo<T> *Ultimo;
};

#endif // COLA_H