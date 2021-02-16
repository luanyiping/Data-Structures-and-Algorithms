#include"SeqList.h"
#include<stdio.h>
// ≤‚ ‘Õ∑Œ≤≤Â»Î…æ≥˝
void TestSeqList()
{
	SeqList s;
	SeqListInit(&s, 3);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPrint(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);
	SeqListPushFront(&s, -1);
	SeqListPrint(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);
	SeqListInsert(&s, 2, 5);
	SeqListPrint(&s);
	SeqListErase(&s, 2);
	SeqListPrint(&s);

}
int main()
{
	TestSeqList();

}