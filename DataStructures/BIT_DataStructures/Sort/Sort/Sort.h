#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#ifndef _SORT_H_

#define _SORT_H_

#define DATAPRINT(data) printf("%2d ", data)
typedef int SORTDATA;

void InsertSort(SORTDATA arr[], int size); // ֱ�Ӳ�������
void ShellSort(SORTDATA arr[], int size); // ϣ������(��С��������)
void SeclectionSort(SORTDATA arr[], int size); // ѡ������
void HeapSort(SORTDATA arr[], int size); // ������
void BubbleSort(SORTDATA arr[], int size); // ð������
void MergeSort(SORTDATA arr[], int left, int right); // �鲢����

void Print(SORTDATA arr[], int size); // ��ӡ����

#endif // _SORT_H_