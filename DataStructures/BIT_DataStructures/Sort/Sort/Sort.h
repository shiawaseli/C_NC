#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>

#ifndef _SORT_H_

#define _SORT_H_

#define SIZE 20000
#define DATAPRINT(data) printf("%5d ", data)
typedef int SORTDATA;

void InsertSort(SORTDATA arr[], int size); // ֱ�Ӳ�������
void ShellSort(SORTDATA arr[], int size); // ϣ������(��С��������)
void SeclectionSort(SORTDATA arr[], int size); // ѡ������
void HeapSort(SORTDATA arr[], int size); // ������
void BubbleSort(SORTDATA arr[], int size); // ð������
void QuickSort(SORTDATA arr[], int left, int right); // ��������
void MergeSort(SORTDATA arr[], int size); // �鲢����
void BucketSort(SORTDATA arr[], int size); // Ͱ����

void Print(SORTDATA arr[], int size); // ��ӡ����

#endif // _SORT_H_