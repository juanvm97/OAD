
#include <iostream>
#include "Nodo.h"
#include "Pila.h"
#include "Cola.h"

using namespace std;

int main()
{

    Pila<int> P;
    P.Push(1);
    P.Push(2);
    P.Push(3);

    P.Print();
    cout << endl;
    P.Pop();

    P.Print();
    
    cout << endl;

    Cola<int> C;
    C.Push(1);
    C.Push(2);
    C.Push(3);

    C.Print();
    cout << endl;
    C.Pop();

    C.Print();
    return 0;
}
