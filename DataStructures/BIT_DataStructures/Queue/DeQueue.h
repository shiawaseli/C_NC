#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

#ifndef _DEQUEUE_H_
#define _DEQUEUE_H

typedef int DeQUDataType;
#define QUEUENUM 5
#define PRINT(data) printf("%d �� ", (data))

typedef struct DeQueue
{
	DeQUDataType *data;
	int _head, _tail;
	int _capacity;
}DeQueue;

void DeQueueInit(DeQueue* pq); // ���г�ʼ��
void DeQueueDestory(DeQueue* pq); // ��������

void DeQueuePush(DeQueue* pq, DeQUDataType x); // β�����
void DeQueuePop(DeQueue* pq); // ��Ԫ�س���
DeQUDataType DeQueueFront(DeQueue* pq); // ������Ԫ��
DeQUDataType DeQueueBack(DeQueue* pq); // ����βԪ��(������)
int DeQueueEmpty(DeQueue* pq); // �ж��Ƿ�ն���
int DeQueueSize(DeQueue* pq); // ���ض�����Ԫ�ظ���

void DeQueuePrint(DeQueue *pq); // ��ӡ�����е�Ԫ��
void DeQueueState(DeQueue *pq); // ������е�״̬
void TestDeQueue();

#endif //_DEQUEUE_H_
