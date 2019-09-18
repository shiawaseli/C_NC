#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

#ifndef _QUEUE_H_
#define _QUEUE_H

typedef int QUDataType;
#define PRINT(data) printf("%d �� ", (data))

typedef struct QueueNode 
{ 
	struct QueueNode* _next;
	QUDataType _data; 
}QueueNode; //�ӽ��

typedef struct Queue 
{
	QueueNode* _front; // ��ͷ(ָ�����)
	QueueNode* _rear;  // ��β(ָ����һ����ӵĽ�㣬��β����һ��Ԫ��)
}Queue;

void QueueInit(Queue* pq); // ���г�ʼ��
void QueueDestory(Queue* pq); // ��������

QueueNode* BuyQueueNode(QUDataType x); // �����ݷ���ӽ�㲢����(��ʱû��ʹ��)
void QueuePush(Queue* pq, QUDataType x); // β�����
void QueuePop(Queue* pq); // ��Ԫ�س���
QUDataType QueueFront(Queue* pq); // ������Ԫ��
QUDataType QueueBack(Queue* pq); // ����βԪ��(������)
int QueueEmpty(Queue* pq); // �ж��Ƿ�ն���
int QueueSize(Queue* pq); // ���ض�����Ԫ�ظ���

void QueuePrint(Queue *pq); // ��ӡ�����е�Ԫ��
void QueueState(Queue *pq); // ������е�״̬
void TestQueue(); // ���Ժ���

#endif //_QUEUE_H_