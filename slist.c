#include "slist.h"

void SListInit(SList* plist)//初始化一个头结点
{
	plist->_head = NULL;
}
void SListPushFront(SList* plist, SLTDataType x)//头插
{
	assert(plist);
	SListNode *cur = (SListNode *)malloc(sizeof(SListNode));
	cur->_data = x;
	cur->_next = plist->_head;
	plist->_head = cur;
}
void SListPopFront(SList* plist)//头删
{
	assert(plist);
	SListNode *tmp;
	if (plist->_head)
	{
		tmp = plist->_head;
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}

void SListPrint(SList* plist)//打印链表
{
	assert(plist);
	SListNode * cur;
	for (cur = plist->_head; cur; cur = cur->_next)
	{
		printf("%d->", cur->_data);
	}
	printf("NULL\n");
}

void SListDestory(SList* plist)//释放链表
{
	SListNode * tmp;
	while (plist->_head)
	{
		tmp = plist->_head;
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}

SListNode* SListFind(SList* plist, SLTDataType x)//查找一个节点，并且返回位置
{
	SListNode * cur;
	for (cur = plist->_head; cur; cur = cur->_next)
	{
		if (cur->_data == x)
		{
			return cur;
		}
	}
	return NULL;
}
void SListInsertAfter(SListNode* pos, SLTDataType x)//在pos的后面插入结点
{
	assert(pos);
	SListNode *cur = (SListNode *)malloc(sizeof(SListNode));
	cur->_data = x;
	cur->_next = pos->_next;
	pos->_next = cur;
}

//void SListInsertFront(SList * plist, SLTDataType x)//在pos的前面插入结点
//{
//	SListNode * cur;
//	SListNode * newdata = (SListNode *)malloc(sizeof(SListNode));
//	if (plist->_head->_data == x)
//	{
//		SListPushFront(plist, x);
//		return;
//	}
//	for (cur = plist->_head; cur->_next; cur = cur->_next)
//	{
//		if (cur->_next->_data == x)
//		{
//			break;
//		}
//	}
//	newdata->_next = cur->_next;
//	cur->_next = newdata;
//}
void SListEraseAfter(SListNode* pos)//在pos的后面删除结点
{
	SListNode * tmp;
	tmp= pos->_next;
	pos->_next=tmp->_next;
	free(tmp);
}