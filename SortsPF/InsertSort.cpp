
#include "fun.h"

void InsertSort(int *Array, int Tam, bool (*compare) (int, int))
{
    int key;
    int i;
    for (int j=1; j<Tam; j++)
    {
        key = *(Array + j);
        i = j-1;
        while ((i>-1) and (compare(*(Array + i), key)))
        {
            *(Array + i+1) = *(Array + i);
            i = i-1;
        }
        *(Array + i+1) = key;
    }
}

int main()
{
    int Tam = 8;
    int A[Tam] = {1, 12, 5, 26, 7, 14, 3, 2};
    
    Print(A, Tam);
    
    InsertSort(A, Tam, compare_des);
    
    Print(A, Tam);

    InsertSort(A, Tam, compare_ase);
    
    Print(A, Tam);

    return 0;
}