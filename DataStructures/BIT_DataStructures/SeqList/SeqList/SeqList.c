#include"SeqList.h"
//˳����ʼ��
void SeqListInit(SeqList* psl, size_t capacity)
{
	assert(psl);

	psl->array = (SLDataType*)calloc(capacity, sizeof(SLDataType));

	assert(psl->array);

	psl->capacity = capacity;
	psl->size = 0;
}
//˳�������
void SeqListDestory(SeqList* psl)
{
	assert(psl);

	if (psl->array)
	{
		free(psl->array);
		psl->array = NULL;
		psl->capacity = 0;
		psl->size = 0;
	}
}
//˳�������ʱ����˳�������Ϊ����
void CheckCapacity(SeqList* psl)
{
	assert(psl);

	if (psl->capacity == psl->size)
	{
		psl->capacity *= 2;
		psl->array = (SLDataType*)realloc(psl->array, psl->capacity * sizeof(SLDataType));
	}

	assert(psl->array);
}
//�ӱ�β��������
void SeqListPushBack(SeqList* psl, SLDataType x)
{
	assert(psl);

	CheckCapacity(psl);

	psl->array[psl->size] = x;
	psl->size++;
}
//�ӱ�βɾ������
void SeqListPopBack(SeqList* psl)
{
	assert(psl || psl->size);

	psl->size--;
}
//�ӱ�ͷ��������
void SeqListPushFront(SeqList* psl, SLDataType x)
{
	assert(psl);

	int i;

	CheckCapacity(psl);

	for (i = psl->size; i > 0; i--)
	{
		psl->array[i] = psl->array[i - 1];
	}
	psl->array[i] = x;
	psl->size++;
}
//�ӱ�ͷɾ������
void SeqListPopFront(SeqList* psl)
{
	assert(psl);

	unsigned int i;

	psl->size--;
	for (i = 0; i < psl->size; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}

}

//��˳����в�������
int SeqListFind(SeqList* psl, SLDataType x)
{
	assert(psl);

	unsigned int i;

	for (i = 0; i < psl->size; i++)
	{
		if (psl->array[i] == x)
		{
			return i;
		}
	}

	return -1;
}
//��posλ�ò�������
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl || pos <= psl->size);

	unsigned int i;

	CheckCapacity(psl);

	for (i = psl->size; i > pos; i--)
	{
		psl->array[i] = psl->array[i - 1];
	}
	psl->array[pos] = x;
	psl->size++;
}
//ɾ��posλ�õ�����
void SeqListErase(SeqList* psl, size_t pos)
{
	assert(psl || pos < psl->size);

	unsigned int i;

	psl->size--;
	for (i = pos; i < psl->size; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
}
//ɾ�����ȳ��ֵ�ָ������
void SeqListRemove(SeqList* psl, SLDataType x)
{
	assert(psl);

	int pos = SeqListFind(psl, x);

	if (pos >= 0)
	{
		SeqListErase(psl, pos);
	}
}
//�޸�posλ�õ�����Ϊָ������
void SeqListModify(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl || pos < psl->size);

	psl->array[pos] = x;
}
//��ӡ˳���
void SeqListPrint(SeqList* psl)
{
	assert(psl);

	unsigned int i;

	for (i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->array[i]);
	}
	putchar('\n');
}

// ��չ������ʵ��

//ð������
void SeqListBubbleSort(SeqList* psl)
{
	assert(psl);

	size_t i, j;
	SLDataType tmp;

	for (i = 0; i < psl->size - 1; i++)
	{
		for (j = 0; j < psl->size - i - 1; j++)
		{
			if (psl->array[j] > psl->array[j + 1])
			{
				tmp = psl->array[j];
				psl->array[j] = psl->array[j + 1];
				psl->array[j + 1] = tmp;
			}
		}
	}
}
//���ֲ���
int SeqListBinaryFind(SeqList* psl, SLDataType x)
{
	assert(psl);

	int left = 0;
	int right = psl->size - 1;
	int mid;

	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (psl->array[mid] == x)
		{
			return mid;
		}
		else if (psl->array[mid] > x)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	return -1;
}
// ����Ҫ��ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(1) 

//ɾ���ظ���ָ������
void SeqListRemoveAll(SeqList* psl, SLDataType x)
{
	assert(psl);

	size_t i;
	int ret, num = 0;

	for (i = 0; i < psl->size; i++)
	{
		if (psl->array[i] == x)
		{
			num++;
		}
	}
	while (num > 1)
	{
		ret = SeqListBinaryFind(psl, x);
		SeqListErase(psl, ret);
		num--;
	}
}