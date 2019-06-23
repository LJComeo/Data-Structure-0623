#include "SeqList.h"
#include <assert.h>

void SeqListInit(SeqList* psl, size_t capicity)//初始化
{
	assert(psl);
	psl->capicity = capicity;
	psl->array = (SLDataType *)malloc(capicity*sizeof(SLDataType));
	assert(psl->array);
	psl->size = 0;
}

void SeqListDestory(SeqList* psl)//销毁函数
{
	assert(psl);
	if (psl->array)
	{
		free(psl->array);
		psl->array = NULL;
		psl->size = 0;
		psl->capicity = 0;
	}
}

void CheckCapacity(SeqList* psl)//扩容函数
{
	assert(psl);
	if (psl->size == psl->capicity)
	{
		psl->capicity *= 2;
		psl->array = (SLDataType *)realloc(psl->array, psl->capicity*sizeof(SLDataType));
	}
}
void SeqListPushBack(SeqList* psl, SLDataType x)//尾插
{
	assert(psl);
	CheckCapacity(psl);
	psl->array[psl->size] = x;
	psl->size++;
}
void SeqListPopBack(SeqList* psl)//尾删
{
	assert(psl || psl->size);
	psl->size--;
}
void SeqListPushFront(SeqList* psl, SLDataType x)//头插
{
	assert(psl);
	CheckCapacity(psl);
	int i;
	for (i = psl->size - 1; i >= 0; --i)
	{
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[0] = x;
	psl->size++;
}
void SeqListPopFront(SeqList* psl)//头删
{
	assert(psl || psl->size);
	int i;
	psl->size--;
	for (i = 0; i < psl->size;++i)
	{
		psl->array[i] = psl->array[i + 1];
	}
}

void SeqListPrint(SeqList* psl)//输出
{
	assert(psl);
	int i;
	for (i = 0; i < psl->size; ++i)
	{
		printf("%d ", psl->array[i]);
	}
	putchar('\n');
}

int SeqListFind(SeqList* psl, SLDataType x)//查找
{
	assert(psl);
	int i;
	for (i = 0; i < psl->size; ++i)
	{
		if (psl->array[i] == x)
		{
			return i;
		}
	}
	return -1;
}
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)//按位置插入数据
{
	assert(psl || pos <= psl->size);
	CheckCapacity(psl);

	int i;
	for (i = psl->size - 1; i >= pos; --i)
	{
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[pos] = x;
	psl->size++;
}
void SeqListErase(SeqList* psl, size_t pos)//按位置删除
{
	assert(psl || pos < psl->size);
	psl->size--;
	int i;
	for (i = pos; i<psl->size; ++i)
	{
		psl->array[i ] = psl->array[i+1];
	}
}
void SeqListRemove(SeqList* psl, SLDataType x)//删除含有x里面的数据
{
	int pos=SeqListFind(psl,x);
	if (pos >= 0)
	{
		SeqListErase(psl,pos);
	}
}
void SeqListModify(SeqList* psl, size_t pos, SLDataType x)//将pos位置的数据替换为x
{
	assert(psl || pos < psl->size);

	psl->array[pos-1] = x;
}

void SeqListBubbleSort(SeqList* psl)//冒泡排序
{
	int i, j;
	SLDataType tmp;
	for (i = 0; i < psl->size - 1; i++)
	{
		for (j = 0; j < psl->size - 1 - i; j++)
		{
			if (psl->array[j]>psl->array[j + 1])
			{
				tmp = psl->array[j];
				psl->array[j] = psl->array[j + 1];
				psl->array[j + 1] = tmp;
			}
		}
	}
}
int SeqListBinaryFind(SeqList* psl, SLDataType x)// 本题要求：时间复杂度：O(N) 空间复杂度 O(1)
{
	assert(psl);

	int left = 0;
	int right = psl->size - 1;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (psl->array[mid] < x)
		{
			left = mid + 1;
		}
		else if (psl->array[mid]>x)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}