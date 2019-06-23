#include "SeqList.h"
#include <assert.h>

void SeqListInit(SeqList* psl, size_t capicity)//��ʼ��
{
	assert(psl);
	psl->capicity = capicity;
	psl->array = (SLDataType *)malloc(capicity*sizeof(SLDataType));
	assert(psl->array);
	psl->size = 0;
}

void SeqListDestory(SeqList* psl)//���ٺ���
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

void CheckCapacity(SeqList* psl)//���ݺ���
{
	assert(psl);
	if (psl->size == psl->capicity)
	{
		psl->capicity *= 2;
		psl->array = (SLDataType *)realloc(psl->array, psl->capicity*sizeof(SLDataType));
	}
}
void SeqListPushBack(SeqList* psl, SLDataType x)//β��
{
	assert(psl);
	CheckCapacity(psl);
	psl->array[psl->size] = x;
	psl->size++;
}
void SeqListPopBack(SeqList* psl)//βɾ
{
	assert(psl || psl->size);
	psl->size--;
}
void SeqListPushFront(SeqList* psl, SLDataType x)//ͷ��
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
void SeqListPopFront(SeqList* psl)//ͷɾ
{
	assert(psl || psl->size);
	int i;
	psl->size--;
	for (i = 0; i < psl->size;++i)
	{
		psl->array[i] = psl->array[i + 1];
	}
}

void SeqListPrint(SeqList* psl)//���
{
	assert(psl);
	int i;
	for (i = 0; i < psl->size; ++i)
	{
		printf("%d ", psl->array[i]);
	}
	putchar('\n');
}

int SeqListFind(SeqList* psl, SLDataType x)//����
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
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)//��λ�ò�������
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
void SeqListErase(SeqList* psl, size_t pos)//��λ��ɾ��
{
	assert(psl || pos < psl->size);
	psl->size--;
	int i;
	for (i = pos; i<psl->size; ++i)
	{
		psl->array[i ] = psl->array[i+1];
	}
}
void SeqListRemove(SeqList* psl, SLDataType x)//ɾ������x���������
{
	int pos=SeqListFind(psl,x);
	if (pos >= 0)
	{
		SeqListErase(psl,pos);
	}
}
void SeqListModify(SeqList* psl, size_t pos, SLDataType x)//��posλ�õ������滻Ϊx
{
	assert(psl || pos < psl->size);

	psl->array[pos-1] = x;
}

void SeqListBubbleSort(SeqList* psl)//ð������
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
int SeqListBinaryFind(SeqList* psl, SLDataType x)// ����Ҫ��ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(1)
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