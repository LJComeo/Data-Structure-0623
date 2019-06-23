#ifndef SLIST_H_
#define SLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode* _next;
}SListNode;
typedef struct SList
{
	SListNode* _head;
}SList;

void SListInit(SList* plist);
void SListDestory(SList* plist);

SListNode* BuySListNode(SLTDataType x);

void SListPushFront(SList* plist, SLTDataType x);
void SListPopFront(SList* plist);

SListNode* SListFind(SList* plist, SLTDataType x);
void SListInsertAfter(SListNode* pos, SLTDataType x);// ��pos�ĺ�����в���
void SListEraseAfter(SListNode* pos);// ��pos��ǰ����в���

void SListRemove(SList* plist, SLTDataType x);//��ҵ����һ��x����������ɾ��(��ϰ����ı���)

void SListPrint(SList* plist);
void TestSList();

#endif