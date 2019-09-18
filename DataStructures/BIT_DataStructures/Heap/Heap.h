#include<stdio.h>
#include<stdlib.h>

#ifndef _HEAP_H_

#define _HEAP_H_

typedef int HPDataType;

typedef struct Heap
{
	HPDataType *data;
	int capacity;
	int size;
}Heap;

void HeapInit(Heap* hp, HPDataType* arr, int size); // ����󣩶ѵĽ���
void HeapDestory(Heap* hp); // �ѵ�����
void HeapPush(Heap* hp, HPDataType x); // �ѵĲ���
void HeapPop(Heap* hp); // �ѵ�ɾ��
HPDataType HeapTop(Heap* hp); // ��ȡ�Ѷ�Ԫ��
int HeapSize(Heap* hp);  // ��ȡ�ѵĴ�С
int HeapEmpty(Heap* hp); // �ж��Ƿ�Ϊ�ն�
void HeapSort(Heap* hp); // ������
void AdjustDown(Heap* hp, int n); // �ѵ����µ���
void AdjustUp(Heap* hp, int n); // �ѵ����ϵ���
void HeapPrint(Heap* hp); // �Ѵ�ӡ���������Ĵ�ӡ��
void HeapPrintS(Heap* hp); // ������ӡ�����ڲ鿴�����Ƿ����

#endif // _HEAP_H_
