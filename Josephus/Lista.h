#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"

template <typename T> class Lista
{
    public:
        Lista();
        void Push(T Dato);
        int Size();
        void Remove(const int pos);
        void Print();
        void Josephus(int Num);
        ~Lista();
        
        Nodo<T> *Primero;
        Nodo<T> *Ultimo;
};

#endif // LISTA_H