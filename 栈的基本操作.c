#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 100
#define STACKINCEEMENT 10
struct stack
{
	int* base;
	int* top;
	int stacksize;
};
//��ʼ��ջ
int initstack(struct stack* s)
{
	s->base = (int*)malloc(sizeof(struct stack));
	if (!s->base)
	{
		return -1;
	}
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
}
//��ջ
int push(struct stack *s, int e)
{
	struct stack* p;
	if (s->top - s->base == s->stacksize) //����
	{
		p= (struct stack*)realloc(s->base, (STACK_INIT_SIZE + STACKINCEEMENT) * sizeof(int)); 
		if (!p)
		{
			return -1;
		}
		s->base = p;
		s->top = s->base + s->stacksize;
		s->stacksize += STACKINCEEMENT;
	}
	*(s->top) = e;
	s->top++;
	return 0;
}
//��ջ
int pop(struct stack *s)
{
	if (s->base == s->top)
	{
		return -1;
	}
	s->top--;
	return *(s->top);
}
//�ж�ջ�Ƿ�Ϊ��
void judgeNull(struct stack* s)
{
	if (s->top == s->base)
	{
		printf("��ջΪ��ջ\n");
	}
	else
		printf("��ջ��Ϊ��\n");
}
//�ж�ջ�Ƿ���
void judgeFull(struct stack* s)
{
	if (s->top - s->base == s->stacksize)
	{
		printf("��ջ��\n");
	}
	else
		printf("��ջ����\n");
}
int main()
{
	struct stack s ;
	initstack(&s);
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		push(&s, i);
	}
	for (i = 0; i < 5; i++)
	{
		int ret = pop(&s);
		printf("%d ", ret);
	}
}