
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

void SelectSort(int *Array, int Tam)
{
    int Min;

    for (int j = 0; j < Tam-1; j++)
    {
        Min = j;
        for (int i = j+1; i < Tam; i++)
        {
            if (*(Array + i) <= *(Array + Min))
                Min = i;
        }

        if(Min != j)
        {
            swap((Array + j), (Array + Min));
        }
    }
}

int main(){

    int Tam = 8;
    int A[Tam] = {1, 12, 5, 26, 7, 14, 3, 2};
    
    Print(A, Tam);
    
    SelectSort(A, Tam);
    
    Print(A, Tam);

    return 0;
}