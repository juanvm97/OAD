
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

void BubbleSort(int *Array, int Tam)
{
    int x;

    do
    {
        x = 0;
        for(int j=0; j<Tam-1; j++)
        {
            if(Array[j]>Array[j+1])
            {
                swap((Array+j), (Array+j+1));   
                x++;
            }
        }
    }
    while (x != 0);
}

int main(){

    int Tam = 8;
    int A[Tam] = {1, 12, 5, 26, 7, 14, 3, 2};
    
    Print(A, Tam);
    
    BubbleSort(A, Tam);
    
    Print(A, Tam);

    return 0;
}