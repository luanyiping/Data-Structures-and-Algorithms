#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLDataType;
typedef struct SeqList
{
    SLDataType* array; // ָ��̬���ٵ�����
    size_t size; // ��Ч���ݸ���
    size_t capicity; // �����ռ�Ĵ�С
}SeqList;
// ������ɾ��Ľӿ�
// ˳����ʼ��
void SeqListInit(SeqList* ps, size_t capacity);
// ˳����ӡ
void SeqListPrint(SeqList* ps);
// ���ռ䣬������ˣ���������
void CheckCapacity(SeqList* ps);
// ˳���β��
void SeqListPushBack(SeqList* ps, SLDataType x);
// ˳���βɾ
void SeqListPopBack(SeqList* ps);
// ˳���ͷ��
void SeqListPushFront(SeqList* ps, SLDataType x);
// ˳���ͷɾ
void SeqListPopFront(SeqList* ps);
// ˳������
int SeqListFind(SeqList* ps, SLDataType x);
// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, size_t pos, SLDataType x);
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, size_t pos);