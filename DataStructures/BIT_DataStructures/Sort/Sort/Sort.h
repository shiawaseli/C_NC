#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#ifndef _SORT_H_

#define _SORT_H_

#define DATAPRINT(data) printf("%d ", data)
typedef int SORTDATA;

void InsertSort(SORTDATA arr[], int size); // ֱ�Ӳ�������
void ShellSort(SORTDATA arr[], int size); // ϣ������(��С��������)
void SeclectionSort(SORTDATA arr[], int size); // ѡ������

void Print(SORTDATA arr[], int size); // ��ӡ����

#endif // _SORT_H_