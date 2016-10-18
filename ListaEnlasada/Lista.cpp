#include "Lista.h"

using namespace std;

Lista::Lista()
{
    Primero = NULL;
    Ultimo = NULL;
}

void Lista::Insert(int a)
{
    if (!Primero)
    {
        Primero = new Nodo(a);
        Ultimo = Primero;
    }

    else
    {
        Ultimo->Siguiente = new Nodo(a);
        Ultimo = Ultimo->Siguiente;
    }
}

void Lista::Print()
{
    Nodo *x = Primero;
    if(!Primero)
    {
        cout << " Esta vacia" << endl;
    }

    else
    {
        while(x != Ultimo->Siguiente)
        {
            cout << "   ->" << x->m_Dato << endl;
            x=x->Siguiente;
        }
    }
}

void Lista::Invertir()
{
    if(Primero -> Siguiente == NULL)
        return;

    Nodo *temp1= Primero;
    Nodo *temp2= Primero->Siguiente;
    Nodo *temp3= Primero->Siguiente->Siguiente;
    Primero->Siguiente=NULL;
    Ultimo=Primero;

    while (temp2->Siguiente != NULL)
    {
        temp2->Siguiente=temp1;
        temp1=temp2;
        temp2=temp3;
        temp3=temp3->Siguiente;
    }
    temp2->Siguiente=temp1;
    Primero = temp2;
}

void Lista::Eliminar()
{
    Nodo *t1 = Primero;
    int i=1;
    while(t1 != Ultimo->Siguiente)
    {
        cout << "   " << i << ".-" << t1->m_Dato << endl;
        t1=t1->Siguiente;
        i++;
    }

    cout << "   Numero del elemento para eliminar: ";
    cin >> i;

    if(i == 1)
    {
        Primero = Primero->Siguiente;
        return;
    }

    t1=Primero;
    for (; i>2; i--)
        t1=t1->Siguiente;

    if (t1->Siguiente == Ultimo)
    {
        Ultimo = t1;
        t1->Siguiente=t1->Siguiente->Siguiente;
    }

    else
        t1->Siguiente=t1->Siguiente->Siguiente;

}

Lista::~Lista()
{

}


