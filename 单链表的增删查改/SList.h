#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SListDataType;
typedef struct SListNode
{
	SListDataType data;
	struct SListNode* next;
}SListNode;
// 动态申请一个结点
SListNode* CreateSListNode(SListDataType x);
// 单链表打印
void SListPrint(SListNode* pList);
// 单链表尾插
void SListPushBack(SListNode** ppList, SListDataType x);
// 单链表尾删
void SListPopBack(SListNode** ppList);
// 单链表头插
void SListPushFront(SListNode** ppList, SListDataType x); 
// 单链表头删
void SListPopFront(SListNode** ppList);
// 单链表查找
SListNode* SListFind(SListNode* pList,SListDataType x);
// 单链表在pos位置后插入 x 
void SListInsertAfter(SListNode* pos, SListDataType x);
// 单链表在pos位置后删除 x
void SListEraseAfter(SListNode* pos);
