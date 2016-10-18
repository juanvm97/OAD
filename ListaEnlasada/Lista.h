#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"

class Lista
{
    public:
        Lista();
        void Insert(int a);
        void Print();
        Nodo *Primero;
        Nodo *Ultimo;
        void Invertir();
        void Eliminar();
        virtual ~Lista();
};

#endif // LISTA_H
