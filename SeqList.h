#ifndef _SEQLIST_H_
#define _SEQLIST_H_
typedef int SLDataType;

#include <stdio.h>
#include <stdlib.h>

typedef struct SeqList
{
	SLDataType * array;//指向动态开辟的数组
	size_t size;//有效数据的个数
	size_t capicity;//容量空间大小
}SeqList;
void SeqListInit(SeqList* psl, size_t capacity);
void SeqListDestory(SeqList* psl);

void CheckCapacity(SeqList* psl);
void SeqListPushBack(SeqList* psl, SLDataType x);
void SeqListPopBack(SeqList* psl);
void SeqListPushFront(SeqList* psl, SLDataType x);
void SeqListPopFront(SeqList* psl);

int SeqListFind(SeqList* psl, SLDataType x);
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);
void SeqListErase(SeqList* psl, size_t pos);
void SeqListRemove(SeqList* psl, SLDataType x);
void SeqListModify(SeqList* psl, size_t pos, SLDataType x);

void SeqListPrint(SeqList* psl);

void SeqListBubbleSort(SeqList* psl);
int SeqListBinaryFind(SeqList* psl, SLDataType x);// 本题要求：时间复杂度：O(N) 空间复杂度 O(1)
void SeqListRemoveAll(SeqList* psl, SLDataType x);//作业：先排序->(去重，1 3 3 3 4 5->1 3 4 5)
#endif //_SEQLIST_H_