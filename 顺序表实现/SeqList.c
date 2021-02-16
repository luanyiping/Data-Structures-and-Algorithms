#include"SeqList.h"
#include<stdio.h>
// ˳����ʼ��
void SeqListInit(SeqList* ps, size_t capicity)
{
	assert(ps);
	ps->array = (SLDataType*)malloc(sizeof(SLDataType) * capicity);
	if (ps->array == NULL)
	{
		printf("��ʼ��ʧ��\n");
		exit(-1);
	}
	ps->size = 0;
	ps->capicity = capicity;
}
// ˳����ӡ
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
// ���ռ䣬������ˣ���������
void CheckCapacity(SeqList* ps)
{
	assert(ps);
	if (ps->size >= ps->capicity)
	{
		ps->capicity *= 2;
		ps->array = (SLDataType*)realloc(ps->array, sizeof(SLDataType) * ps->capicity);
		if (ps->array == NULL)
		{
			printf("����ʧ��\n");
			exit(-1);
		}
	}
}
// ˳���β��
void SeqListPushBack(SeqList* ps, SLDataType x)
{
	CheckCapacity(ps);
	ps->array[ps->size] = x;
	ps->size++;
}
// ˳���βɾ
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	ps->size--;
}
// ˳���ͷ��
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
// ˳���ͷɾ
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
// ˳������
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
// ˳�����posλ�ò���x
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
// ˳���ɾ��posλ�õ�ֵ
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

