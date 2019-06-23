#include "slist.h"

void SListInit(SList* plist)//��ʼ��һ��ͷ���
{
	plist->_head = NULL;
}
void SListPushFront(SList* plist, SLTDataType x)//ͷ��
{
	assert(plist);
	SListNode *cur = (SListNode *)malloc(sizeof(SListNode));
	cur->_data = x;
	cur->_next = plist->_head;
	plist->_head = cur;
}
void SListPopFront(SList* plist)//ͷɾ
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

void SListPrint(SList* plist)//��ӡ����
{
	assert(plist);
	SListNode * cur;
	for (cur = plist->_head; cur; cur = cur->_next)
	{
		printf("%d->", cur->_data);
	}
	printf("NULL\n");
}

void SListDestory(SList* plist)//�ͷ�����
{
	SListNode * tmp;
	while (plist->_head)
	{
		tmp = plist->_head;
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}

SListNode* SListFind(SList* plist, SLTDataType x)//����һ���ڵ㣬���ҷ���λ��
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
void SListInsertAfter(SListNode* pos, SLTDataType x)//��pos�ĺ��������
{
	assert(pos);
	SListNode *cur = (SListNode *)malloc(sizeof(SListNode));
	cur->_data = x;
	cur->_next = pos->_next;
	pos->_next = cur;
}

//void SListInsertFront(SList * plist, SLTDataType x)//��pos��ǰ�������
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
void SListEraseAfter(SListNode* pos)//��pos�ĺ���ɾ�����
{
	SListNode * tmp;
	tmp= pos->_next;
	pos->_next=tmp->_next;
	free(tmp);
}