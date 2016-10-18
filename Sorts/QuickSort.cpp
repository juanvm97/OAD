
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

void QuickSort(int *Array, int inc, int fin)
{
    if(inc < fin)
    {
        int tam = fin - inc;
        int i = inc;
        int f = fin;
        int pivote = *(Array+inc);

        while(i < f)
        {
                while (*(Array+f) > pivote)
                    f--;
                
                while ((i<f) and (*(Array+i)<=pivote))
                    i++;
                
                if (i<f)
                    swap(Array+i, Array+f);          
        }

        swap(Array+inc, Array+f);

        QuickSort(Array,inc,f-1);
        QuickSort(Array,f+1,fin);
    }
}

int main(){

	int Tam = 8;
    int A[Tam] = {1, 12, 5, 26, 7, 14, 3, 2};
    
    Print(A, Tam);
    
    QuickSort(A, 0, Tam-1);
    
    Print(A, Tam);

    return 0;
}