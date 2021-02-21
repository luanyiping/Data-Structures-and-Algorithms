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
// ��̬����һ�����
SListNode* CreateSListNode(SListDataType x);
// �������ӡ
void SListPrint(SListNode* pList);
// ������β��
void SListPushBack(SListNode** ppList, SListDataType x);
// ������βɾ
void SListPopBack(SListNode** ppList);
// ������ͷ��
void SListPushFront(SListNode** ppList, SListDataType x); 
// ������ͷɾ
void SListPopFront(SListNode** ppList);
// ���������
SListNode* SListFind(SListNode* pList,SListDataType x);
// ��������posλ�ú���� x 
void SListInsertAfter(SListNode* pos, SListDataType x);
// ��������posλ�ú�ɾ�� x
void SListEraseAfter(SListNode* pos);
