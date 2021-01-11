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
//初始化栈
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
//入栈
int push(struct stack *s, int e)
{
	struct stack* p;
	if (s->top - s->base == s->stacksize) //上溢
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
//出栈
int pop(struct stack *s)
{
	if (s->base == s->top)
	{
		return -1;
	}
	s->top--;
	return *(s->top);
}
//判断栈是否为空
void judgeNull(struct stack* s)
{
	if (s->top == s->base)
	{
		printf("此栈为空栈\n");
	}
	else
		printf("此栈不为空\n");
}
//判断栈是否满
void judgeFull(struct stack* s)
{
	if (s->top - s->base == s->stacksize)
	{
		printf("此栈满\n");
	}
	else
		printf("此栈不满\n");
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