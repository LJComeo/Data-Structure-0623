#include "SeqList.h"
#include "slist.h"


void listtest()
{
	SList test;
	SListInit(&test);
	SListPushFront(&test, 1);
	SListPushFront(&test, 2);
	SListPushFront(&test, 4);
	SListPushFront(&test, 5);
	SListPushFront(&test, 6);
	SListPushFront(&test, 9);
	SListPrint(&test);
	SListPopFront(&test);
	SListPrint(&test);

	
	//SListDestory(&test);
}
/*int main()
{
	SeqList test;
	SeqListInit(&test, 10);
	SeqListPushBack(&test, 1);
	SeqListPushBack(&test, 2);
	SeqListPushBack(&test, 3);
	SeqListPushBack(&test, 4);
	SeqListPushBack(&test, 5);
	SeqListPushBack(&test, 6);
	SeqListPushBack(&test, 7);
	SeqListPushBack(&test, 8);
	SeqListPushBack(&test, 9);

	SeqListInsert(&test, 1, 16);
	SeqListErase(&test, 2);
	SeqListRemove(&test, 16);
	SeqListModify(&test, 3, 10);

	SeqListBubbleSort(&test);
	printf("%d\n",SeqListBinaryFind(&test, 6));

	SeqListPrint(&test);





	SeqListDestory(&test);
	system("pause");
	return 0;
}*/

int main()
{
	listtest();
	system("pause");
	return 0;
}