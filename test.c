#include"SList.h"
void TestSList()
{
	SListNode* pList = NULL;
	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);

	SListPrint(pList);

	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);

	SListPrint(pList);

	SListPushFront(&pList, 5);
	SListPushFront(&pList, 4);
	SListPushFront(&pList, 3);
	SListPushFront(&pList, 2);
	SListPushFront(&pList, 1);

	SListPrint(pList);

	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);

	SListPrint(pList);
}
int main()
{
	TestSList();
}
