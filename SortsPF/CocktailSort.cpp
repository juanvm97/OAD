
#include "fun.h"

void CocktailSort(int *Array, int Tam, bool (*compare) (int, int))
{
	int x, i = 0;

	do
	{
		x = 0;
		
		for (int j = i; j < Tam-1-i; j++)
		{
			if (compare(*(Array + j), *(Array + j+1)))
			{
				swap((Array + j), (Array + j+1));
				x++;
			}
		}

		for (int j = Tam-1-i; j > i; j--)
		{
			if (!compare(*(Array + j), *(Array + j-1)))
			{
				swap((Array + j), (Array + j-1));
				x++;
			}
		}

		i++;		
	}while(x != 0);
}

int main()
{
    int Tam = 8;
    int A[Tam] = {1, 12, 5, 26, 7, 14, 3, 2};
    
    Print(A, Tam);
    
    CocktailSort(A, Tam, compare_des);
    
    Print(A, Tam);

	CocktailSort(A, Tam, compare_ase);

	Print(A, Tam);

    return 0;
}