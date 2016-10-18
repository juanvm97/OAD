
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

void CocktailSort(int *Array, int Tam)
{
	int x, i = 0;

	while(x != 0)
	{
		x = 0;

		for (int j = i; j < Tam-1-i; j++)
		{
			if (*(Array + j) > *(Array + j+1))
			{
				swap((Array + j), (Array + j+1));
				x++;
			}
		}

		for (int j = Tam-1-i; j > i; j--)
		{
			if (*(Array + j) < *(Array + j-1))
			{
				swap((Array + j), (Array + j-1));
				x++;
			}
		}

		i++;
	}
}

int main(){

    int Tam = 8;
    int A[Tam] = {1, 12, 5, 26, 7, 14, 3, 2};
    
    Print(A, Tam);
    
    CocktailSort(A, Tam);
    
    Print(A, Tam);

    return 0;
}