
#include "Nodo.h"
#include <iostream>

template <typename T>
Nodo<T>::Nodo(T x)
{
    Dato = x;
    Siguiente = NULL;
    Anterior = NULL;
}

template class Nodo<int>;