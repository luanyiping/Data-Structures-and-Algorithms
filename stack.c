#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#define N 100
struct Stack
{
	int data[N];
	int top; //标识栈顶
};
typedef struct Stack stack;
// 初始化栈
void init(stack* p)
{
	p->top = -1;
	memset(p->data, 0, sizeof(int) * N); // 数据清0
}
// 判断栈是否空
int isempty(stack* p)
{
	if (p->top == -1)
	{
		return 1;
	}
	return 0;
}
// 判断栈是否溢出
int isfull(stack* p)
{
	if (p->top == N - 1)
	{
		return 1;
	}
	return 0;
}
// 获取栈顶元素
int gettop(stack* p)
{
	return p->data[p->top];
}
// 入栈
void push(stack* p, int key)
{
	if (isfull(p)==1)
	{
		return;
	}
	else
	{
		p->top++;
		p->data[p->top] = key;
	}
}
// 出栈
void pop(stack* p)
{
	if (isempty(p) == 1)
	{
		return;
	}
	else
	{
		p->top--;
	}
}
void show(stack* p)
{
	if (isempty(p) == 1)
	{
		return;
	}
	else
	{
		printf("\n栈的数据为\n");
		for (int i = 0; i <= p->top; i++)
		{
			printf("%d ", p->data[i]);
		}
	}
}
int main()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9 };
	stack mystack;
	init(&mystack);
	for (int i = 0; i < 10; i++)
	{
		push(&mystack, i);
	}
	while (!isempty(&mystack))
	{
		printf("%d ", gettop(&mystack));
		pop(&mystack);
	}
}
