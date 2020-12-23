#include<iostream>
using namespace std;
typedef struct
{
	int size;
	int* data;
	int top;
	int mindata;
}MinStack;
MinStack* minStackCreate()
{
	MinStack* p = (MinStack*)malloc(sizeof(MinStack));
	p->size = 4;
	p->top = -1;
	p->data = (MinStack*)malloc(sizeof(MinStack));
	p->mindata = INT_MAX;
}
void minStackPush(MinStack* obj, int x)
{
	obj->mindata = (obj->mindata < x) ? obj->mindata : x;
	if (obj->top < obj->size - 1)
	{
		obj->data[++(obj->top)] = x;
	}
	else
	{
		obj->size *= 1.5;
		obj->data = realloc(obj->data, sizeof(obj->size));
		obj->data[++(obj->top)] = x;
	}
}
void minStackPop(MinStack* obj)
{
	if (obj->top == -1)
		return;
	if (obj->data[obj->top] == obj->mindata)
	{
		--(obj->top);
		if (obj->top != -1)
		{
			obj->mindata = obj->data[obj->top];
			for (int i = 0; i < obj->top; i++)
			{
				obj->mindata = (obj->mindata < obj->data[i]) ? obj->mindata : obj->data[i];
			}
		}
		else
		{
			obj->mindata = INT_MAX;
		}

	}
	else
	{
		--(obj->top);
	}
}
int minStackTop(MinStack* obj)
{
	return obj->data[obj->top];
}
int minStackGetmin(MinStack* obj)
{
	return obj->mindata;
}
void minStackFree(MinStack* obj)
{
	free(obj->data);
	free(obj);
}
