#include<stdio.h>
int main()
{
	int i, j, temp;
	int a[10] = { 9,66,54,33,-5,78,123,0,8,7 };
	for (i = 1; i < 10; i++)
	{
		temp = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > temp)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
}
