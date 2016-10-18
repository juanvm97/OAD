
#include <iostream>

using namespace std;

void swap(int *x, int *y)
{
    int tem = *x;
    *x = *y;
    *y = tem;
}

void Print(int *Array, int Tam)
{
    for (int i = 0; i < Tam; i++)
    {
        cout << *(Array+i) << " ";
    }
    cout << endl;
}

void InsertSort(int *Array, int Tam)
{
    int key;
    int i;
    for (int j=1;j<Tam;j++)
    {
        key = *(Array + j);
        i = j-1;
        while ((i>-1) and (*(Array + i) > key))
        {
            *(Array + i+1) = *(Array + i);
            i = i-1;
        }
        *(Array + i+1) = key;
    }
}

int main(){

    int Tam = 8;
    int A[Tam] = {1, 12, 5, 26, 7, 14, 3, 2};
    
    Print(A, Tam);
    
    InsertSort(A, Tam);
    
    Print(A, Tam);

    return 0;
}