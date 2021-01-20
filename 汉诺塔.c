#include<stdio.h>
// 将n个盘子从x借助y到z
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
	printf("请输入汉诺塔层数:");
	scanf("%d", &n);
	printf("移动的步骤如下:\n");
	move(n, 'x', 'y', 'z');
}