#include"SList.h"
// 动态申请一个结点
SListNode* CreateSListNode(SListDataType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		printf("申请结点失败\n");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}
// 单链表打印
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
// 单链表尾插
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
// 单链表尾删
void SListPopBack(SListNode** ppList)
{
	// 1.空结点
	// 2.一个结点
	// 3.两个及以上结点
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
// 单链表头插
void SListPushFront(SListNode** ppList, SListDataType x) 
{
	// 链表为空和不为空操作一样
	SListNode* newNode = CreateSListNode(x);
	newNode->next = *ppList;
	*ppList = newNode;
}
// 单链表头删
void SListPopFront(SListNode** ppList)
{
	// 1. 链表为空
	if (*ppList == NULL)
	{
		return;
	}
	// 2. 链表有一个及以上结点
	else
	{
		SListNode* head = *ppList;
		*ppList =(*ppList)->next;
		free(head);
	}
}
// 单链表查找
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
// 单链表在pos位置后插入 x 
void SListInsertAfter(SListNode* pos, SListDataType x)
{
	assert(pos);
	SListNode* newNode = CreateSListNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
}
// 单链表在pos位置后删除 x
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
