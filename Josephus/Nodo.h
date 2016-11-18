#ifndef NODO_H
#define NODO_H

template <typename T> class Nodo
{
    public:
        Nodo(T x);
        T Dato;
        Nodo<T> *Siguiente;
        Nodo<T> *Anterior;
};

#endif // NODO_H