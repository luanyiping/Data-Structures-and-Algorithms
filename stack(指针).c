#include<stdio.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef char elemtype;
typedef struct
{
	elemtype* base;
	elemtype* top;
	int stacksize;
}sqstack;
// 初始化
void init(sqstack* s)
{
	s->base = (elemtype*)malloc(sizeof(sqstack));
	if (!s->base)
	{
		exit(0);
	}
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;

}
// 入栈
void push(sqstack* s, elemtype e)
{
	if (s->top - s->base == s->stacksize)
	{
		s->base = (elemtype*)realloc(s->base, sizeof(elemtype) * (STACK_INIT_SIZE + STACKINCREMENT));
		if (!s->base)
			exit(0);
		s->top = s->base + s->stacksize;
		s->stacksize += STACKINCREMENT;
	}
	*(s->top) = e;
	s->top++;
}
// 出栈
elemtype pop(sqstack* s)
{
	if (s->base == s->top)
		return;
	return *(--s->top);
}
// 清空栈
void clearstack(sqstack* s)
{
	s->top = s->base;
}
// 销毁栈
void destorystack(sqstack* s)
{
	for (int i = 0; i < s->stacksize; i++)
	{
		free(s->base);
		s->base++;
	}
	s->base = s->top = NULL;
	s->stacksize = 0;
}
// 计算栈的当前容量
int stacklen(sqstack* s)
{
	return(s->top - s->base);
}

int main()
{
	sqstack s;
	init(&s);
	char c = 0;
	int sum = 0, i = 0;
	scanf("%c", &c);
	while (c != "#")
	{
		push(&s, c);
	}
	while (s.base != s.top)
	{
		sum += (pop(&s)-48) * pow(2, i);
		i++;
	}
	printf("%d", sum);
}