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
void SListInsertAfter(SListNode* pos, SLTDataType x);// 在pos的后面进行插入
void SListEraseAfter(SListNode* pos);// 在pos的前面进行插入

void SListRemove(SList* plist, SLTDataType x);//作业：给一个x，把这个结点删除(练习链表的遍历)

void SListPrint(SList* plist);
void TestSList();

#endif