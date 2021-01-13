#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#define N 100
struct Stack
{
	int data[N];
	int top; //��ʶջ��
};
typedef struct Stack stack;
// ��ʼ��ջ
void init(stack* p)
{
	p->top = -1;
	memset(p->data, 0, sizeof(int) * N); // ������0
}
// �ж�ջ�Ƿ��
int isempty(stack* p)
{
	if (p->top == -1)
	{
		return 1;
	}
	return 0;
}
// �ж�ջ�Ƿ����
int isfull(stack* p)
{
	if (p == N - 1)
	{
		return 1;
	}
	return 0;
}
// ��ȡջ��Ԫ��
int gettop(stack* p)
{
	return p->data[p->top];
}
// ��ջ
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
// ��ջ
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
		printf("\nջ������Ϊ\n");
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