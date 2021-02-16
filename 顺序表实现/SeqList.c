#include"SeqList.h"
#include<stdio.h>
// 顺序表初始化
void SeqListInit(SeqList* ps, size_t capicity)
{
	assert(ps);
	ps->array = (SLDataType*)malloc(sizeof(SLDataType) * capicity);
	if (ps->array == NULL)
	{
		printf("初始化失败\n");
		exit(-1);
	}
	ps->size = 0;
	ps->capicity = capicity;
}
// 顺序表打印
void SeqListPrint(SeqList* ps)
{
	assert(ps);
	size_t i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->array[i]);
	}
	printf("\n");
}
// 检查空间，如果满了，进行增容
void CheckCapacity(SeqList* ps)
{
	assert(ps);
	if (ps->size >= ps->capicity)
	{
		ps->capicity *= 2;
		ps->array = (SLDataType*)realloc(ps->array, sizeof(SLDataType) * ps->capicity);
		if (ps->array == NULL)
		{
			printf("扩容失败\n");
			exit(-1);
		}
	}
}
// 顺序表尾插
void SeqListPushBack(SeqList* ps, SLDataType x)
{
	CheckCapacity(ps);
	ps->array[ps->size] = x;
	ps->size++;
}
// 顺序表尾删
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	ps->size--;
}
// 顺序表头插
void SeqListPushFront(SeqList* ps, SLDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	int  i = ps->size - 1;
	for (i = ps->size - 1; i >= 0; i--)
	{
		ps->array[i + 1] = ps->array[i];
	}
	ps->array[0] = x;
	ps->size++;
}
// 顺序表头删
void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->size - 1; i++)
	{
		ps->array[i] = ps->array[i + 1];
	}
	ps->size--;
}
// 顺序表查找
int SeqListFind(SeqList* ps, SLDataType x)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->array[i] == x)
		{
			return i;
		}
	}
}
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, size_t pos, SLDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	int i = ps->size - 1;
	for (i = ps->size - 1; i >= pos - 1; i--)
	{
		ps->array[i + 1] = ps->array[i];
	}
	ps->array[i + 1] = x;
	ps->size++;
}
// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps);
	int i = pos - 1;
	for (i = pos - 1; i < ps->size - 1; i++)
	{
		ps->array[i] = ps->array[i + 1];
	}
	ps->size--;
}

