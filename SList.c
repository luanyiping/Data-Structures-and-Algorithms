#include"SList.h"
// ��̬����һ�����
SListNode* CreateSListNode(SListDataType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		printf("������ʧ��\n");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}
// �������ӡ
void SListPrint(SListNode* pList)
{
	SListNode* cur = pList;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
// ������β��
void SListPushBack(SListNode** ppList, SListDataType x)
{
	SListNode* newNode = CreateSListNode(x);
	if (*ppList == NULL)
	{
		*ppList = newNode;
	}
	else
	{
		SListNode* tail = *ppList;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}
}
// ������βɾ
void SListPopBack(SListNode** ppList)
{
	// 1.�ս��
	// 2.һ�����
	// 3.���������Ͻ��
	if (*ppList == NULL)
	{
		return;
	}
	else if ((*ppList)->next == NULL)
	{
		free(*ppList);
		*ppList = NULL;
	}
	else
	{
		SListNode* prev = NULL;
		SListNode* tail = *ppList;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;
	}
}
// ������ͷ��
void SListPushFront(SListNode** ppList, SListDataType x) 
{
	// ����Ϊ�պͲ�Ϊ�ղ���һ��
	SListNode* newNode = CreateSListNode(x);
	newNode->next = *ppList;
	*ppList = newNode;
}
// ������ͷɾ
void SListPopFront(SListNode** ppList)
{
	// 1. ����Ϊ��
	if (*ppList == NULL)
	{
		return;
	}
	// 2. ������һ�������Ͻ��
	else
	{
		SListNode* head = *ppList;
		*ppList =(*ppList)->next;
		free(head);
	}
}
// ���������
SListNode* SListFind(SListNode* pList, SListDataType x)
{
	SListNode* cur = pList;
	while (cur != NULL)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
// ��������posλ�ú���� x 
void SListInsertAfter(SListNode* pos, SListDataType x)
{
	assert(pos);
	SListNode* newNode = CreateSListNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
}
// ��������posλ�ú�ɾ�� x
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	if (pos->next != NULL)
	{
		SListNode* next = pos->next;
		SListNode* nextnext = next->next;
		pos->next = nextnext;
		free(next);
	}
}
