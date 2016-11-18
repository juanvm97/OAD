
#include "fun.h"

void BubbleSort(int *Array, int Tam, bool (*compare) (int, int))
{
    int x;

    do
    {
        x = 0;
        for(int j=0; j<Tam-1; j++)
        {
            if(compare(Array[j], Array[j+1]))
            {
                swap((Array+j), (Array+j+1));   
                x++;
            }
        }
    }while (x != 0);
}

int main()
{
    int Tam = 8;
    int A[Tam] = {1, 12, 5, 26, 7, 14, 3, 2};
    
    Print(A, Tam);
    
    BubbleSort(A, Tam, compare_des);
    
    Print(A, Tam);

    BubbleSort(A, Tam, compare_ase);

    Print(A, Tam);

    return 0;
}