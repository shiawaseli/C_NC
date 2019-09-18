#include"Heap.h"

// �ѵ����µ���
void AdjustDown(Heap* hp, int n)
{
	int cur = n;
	int tmp, max;
	
	while (cur * 2 + 1 < hp->size)
	{
		if (cur * 2 + 2 >= hp->size) // �ҵ����ĺ��ӽ��
		{
			max = cur * 2 + 1;
		}
		else
		{
			max = hp->data[cur * 2 + 1] > hp->data[cur * 2 + 2] ? cur * 2 + 1 : cur * 2 + 2;
		}
		if (hp->data[cur] < hp->data[max]) // �ж��Ƿ���Ҫ����
		{
			tmp = hp->data[cur];
			hp->data[cur] = hp->data[max];
			hp->data[max] = tmp;

			cur = max;
		}
		else
		{
			break;
		}
	}
}
// �ѵ����ϵ���
void AdjustUp(Heap* hp, int n)
{
	int cur = n;

	while (hp->data[cur] > hp->data[(cur - 1) / 2]) // �ж��Ƿ���Ҫ����
	{
		int tmp = hp->data[cur];
		hp->data[cur] = hp->data[(cur - 1) / 2];
		hp->data[(cur - 1) / 2] = tmp;

		cur = (cur - 1) / 2;
	}
}
// ����󣩶ѵĽ���
void HeapInit(Heap* hp, HPDataType* arr, int size)
{
	hp->size = size;
	hp->capacity = 2 * size;
	hp->data = (HPDataType*)calloc(hp->capacity, sizeof(HPDataType));

	for (int i = 0; i < size; i++) // �������鵽����
	{
		hp->data[i] = arr[i];
	}
	for (int i = size / 2 - 1; i >= 0; i--) // ͨ�����ƽ�������󣩶�
	{
		AdjustDown(hp, i);
	}
}
// �ѵ�����
void HeapDestory(Heap* hp)
{
	if(hp->data)
	{
		free(hp->data);
	}
	hp->data = NULL;
	hp->capacity = 0;
	hp->size = 0;
}
// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x)
{
	if (hp->capacity == hp->size)
	{
		hp->capacity *= 2;
		hp->data = (HPDataType*)realloc(hp->data, hp->capacity * sizeof(HPDataType));
	}

	int cur = hp->size;
	hp->data[hp->size++] = x;
	
	AdjustUp(hp, cur);
}
// �ѵ�ɾ��
void HeapPop(Heap* hp)
{
	if (hp->size == 0)
	{
		return;
	}
	hp->size--;

	int tmp = hp->data[0];
	hp->data[0] = hp->data[hp->size];
	hp->data[hp->size] = tmp;

	AdjustDown(hp, 0);
}
// ��ȡ�Ѷ�Ԫ��
HPDataType HeapTop(Heap* hp)
{
	if (hp->size == 0)
	{
		return (HPDataType)0;
	}
	return hp->data[0];
}
// ��ȡ�ѵĴ�С
int HeapSize(Heap* hp)
{
	return hp->size;
}
// �ж��Ƿ�Ϊ�ն�
int HeapEmpty(Heap* hp)
{
	return hp->size == 0;
}

// ������ 
void HeapSort(Heap* hp)
{
	int tmp = hp->size;

	while (hp->size > 1)
	{
		HeapPop(hp);
	}
	hp->size = tmp;
}
// �Ѵ�ӡ���������Ĵ�ӡ��
void HeapPrint(Heap* hp)
{
	int i,rn = 0, bin = 2;

	for (i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->data[i]);
		if (i == rn)
		{
			putchar('\n');
			rn += bin;
			bin *= 2;
		}
	}
	putchar('\n');
}
// ������ӡ�����ڲ鿴�����Ƿ����
void HeapPrintS(Heap* hp)
{
	int i;

	for (i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->data[i]);
	}
	putchar('\n');
}