#include<stdio.h>
// ��n�����Ӵ�x����y��z
void move(int n, char x, char y, char z)
{
	if (n == 1)
	{
		printf("%c-->%c\n", x, z);
	}
	else
	{
		move(n - 1, x, z, y);
		printf("%c-->%c\n", x, z);
		move(n - 1, y, x, z);
	}
}
int main()
{
	int n;
	printf("�����뺺ŵ������:");
	scanf("%d", &n);
	printf("�ƶ��Ĳ�������:\n");
	move(n, 'x', 'y', 'z');
}