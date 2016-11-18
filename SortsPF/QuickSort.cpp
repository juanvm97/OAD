
#include "fun.h"

void QuickSort(int *Array, int inc, int fin, bool (*compare) (int, int))
{
    if(inc < fin)
    {
        int tam = fin - inc;
        int i = inc;
        int f = fin;
        int pivote = *(Array+inc);

        while(i < f)
        {
                while (compare(*(Array+f), pivote))
                    f--;
                
                while ((i<f) and (!compare(*(Array+i), pivote)))
                    i++;
                
                if (i<f)
                    swap(Array+i, Array+f);          
        }

        swap(Array+inc, Array+f);

        QuickSort(Array, inc, f-1, compare);
        QuickSort(Array, f+1, fin, compare);
    }
}

int main()
{
	int Tam = 8;
    int A[Tam] = {1, 12, 5, 26, 7, 14, 3, 2};
    
    Print(A, Tam);
    
    QuickSort(A, 0, Tam-1, compare_des);
    
    Print(A, Tam);

    QuickSort(A, 0, Tam-1, compare_ase);
    
    Print(A, Tam);

    return 0;
}