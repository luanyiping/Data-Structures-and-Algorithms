#include<stdio.h>
#define N 100
#include<memory.h>
struct Stack
{
	int data[N];
	int top;
};
typedef struct Stack stack;
// ��ʼ��ջ
void init(stack* p)
{
	p->top = -1;
	memset(p->data, 0, sizeof(int) * N);
}
// �ж�ջ�Ƿ�Ϊ��
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
	if (p->top == N - 1)
	{
		return 1;
	}
	return 0;
}
// ��ջ
void push(stack* p, int data)
{
	if (isfull(p)==1)
	{
		return;
	}
	else
	{
		p->top++;
		p->data[p->top] = data;
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
// ��ȡջ��Ԫ��
int top(stack* p)
{
	return p->data[p->top];
}

void show(stack* p)
{
	if (isempty(p) == 1)
	{
		return;
	}
	else
	{
		for (int i = 0; i <= p->top; i++)
		{
			printf("%d ", p->data[i]);
		}
	}
}
int main()
{
	int num;
	scanf_s("%d", &num);
	stack s;
	init(&s);
	while (num)
	{
		push(&s, num % 2);
		num /= 2;
	}
	while (!isempty(&s))
	{
		printf("%d ", top(&s));
		pop(&s);
	}
}