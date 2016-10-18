#ifndef NODO_H
#define NODO_H

#include <iostream>

template <typename T> class Nodo
{
    public:
        Nodo(T x);
        T Dato;
        Nodo<T> *Siguiente;
        Nodo<T> *Anterior;

    protected:
    private:
};

#endif // NODO_H