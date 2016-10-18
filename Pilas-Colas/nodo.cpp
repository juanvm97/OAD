
#include "nodo.h"

template <typename T>
nodo<T>::nodo(T x)
{
    Dato = x;
    Siguiente = NULL;
    Anterior = NULL;
}

template class nodo<int>;