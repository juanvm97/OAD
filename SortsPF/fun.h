
#include <iostream>

using namespace std;

bool compare_des(int a, int b)
{
	if (a<b)
		return true;
	return false;
}

bool compare_ase(int a, int b)
{
	if (a>b)
		return true;
	return false;
}

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