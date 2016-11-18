
#include "fun.h"

void SelectSort(int *Array, int Tam, bool (*compare) (int, int))
{
    int Min;

    for (int j = 0; j < Tam-1; j++)
    {
        Min = j;
        for (int i = j+1; i < Tam; i++)
        {
            if (compare(*(Array + Min), *(Array + i)))
                Min = i;
        }

        if(Min != j)
        {
            swap((Array + j), (Array + Min));
        }
    }
}

int main()
{
    int Tam = 8;
    int A[Tam] = {1, 12, 5, 26, 7, 14, 3, 2};
    
    Print(A, Tam);
    
    SelectSort(A, Tam, compare_des);
    
    Print(A, Tam);

    SelectSort(A, Tam, compare_ase);

    Print(A, Tam);

    return 0;
}