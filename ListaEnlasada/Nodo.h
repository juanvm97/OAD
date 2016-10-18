#ifndef NODO_H
#define NODO_H

#include <iostream>

class Nodo
{
    public:
        int m_Dato;
        Nodo* Siguiente;
        Nodo(int);
        virtual ~Nodo();
    protected:
    private:
};

#endif // NODO_H
