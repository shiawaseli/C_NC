#include"Queue.h"

// ���г�ʼ��
void QueueInit(Queue* pq)
{
	assert(pq);

	pq->_front = (QueueNode*)malloc(sizeof(QueueNode));
	pq->_rear = pq->_front;
	pq->_rear->_next = pq->_front;
}
// ��������
void QueueDestory(Queue* pq)
{
	assert(pq);

	QueueNode *cur;

	while (pq->_front != pq->_rear)
	{
		cur = pq->_front;
		pq->_front = cur->_next;
		free(cur);
	}
	free(pq->_rear);
	pq->_front = NULL;
	pq->_rear = NULL;
}
// �����ݷ���ӽ�㲢����(��ʱû��ʹ��)
QueueNode* BuyQueueNode(QUDataType x)
{
	QueueNode *p = (QueueNode*)malloc(sizeof(QueueNode));

	assert(p);

	p->_data = x;
	p->_next = NULL;

	return p;
}
// β�����
void QueuePush(Queue* pq, QUDataType x)
{
	assert(pq);

	QueueNode *cur = (QueueNode*)malloc(sizeof(QueueNode));

	assert(cur);

	pq->_rear->_data = x;
	cur->_next = pq->_front;
	pq->_rear->_next = cur;
	pq->_rear = cur;
}
// ��Ԫ�س���
void QueuePop(Queue* pq)
{
	assert(pq);

	QueueNode *cur;

	if (pq->_front != pq->_rear);
	{
		cur = pq->_front;
		pq->_front = cur->_next;
		pq->_rear->_next = pq->_front;
	}
}
// ������Ԫ��
QUDataType QueueFront(Queue* pq)
{
	assert(pq);

	return pq->_front->_data;
}
// ����βԪ��(������)
QUDataType QueueBack(Queue* pq)
{
	assert(pq);

	QueueNode *t = pq->_front;

	while (t->_next != pq->_rear)
	{
		t = t->_next;
	}

	return t->_data;
}
// �ж��Ƿ�ն���
int QueueEmpty(Queue* pq)
{
	assert(pq);

	if (pq->_front != pq->_rear)
	{
		return 1;
	}

	return 0;
}
// ���ض�����Ԫ�ظ���
int QueueSize(Queue* pq)
{
	assert(pq);

	int num = 0;
	QueueNode *cur = pq->_front;

	while (cur != pq->_rear)
	{
		num++;
		cur = cur->_next;
	}

	return num;
}
// ��ӡ�����е�Ԫ��
void QueuePrint(Queue *pq)
{
	assert(pq);

	if (pq->_front == pq->_rear)
	{
		printf("Empty!");
	}

	QueueNode *cur = pq->_front;

	while (cur != pq->_rear)
	{
		printf("%d �� ", cur->_data);
		cur = cur->_next;
	}
	putchar('\n');
}
// ������е�״̬(����Ԫ�������������Ԫ�ء�βԪ�ء�����Ԫ�ظ������Ƿ�ն���)
void QueueState(Queue *pq)
{
	printf("�����е�Ԫ��:> ");
	QueuePrint(pq);
	
	printf("QueueSize(pq) = %d\n", QueueSize(pq));
	if (!QueueEmpty(pq))
	{
		printf("Empty Queue!\n");
		return;
	}
	printf("QueueFront(pq) = %d\n", QueueFront(pq));
	printf("QueueBack(pq) = %d\n", QueueBack(pq));
}

// ���Ժ���
void TestQueue()
{
	Queue Q, *pq = &Q;

	QueueInit(pq);

	QueuePush(pq, 18);
	QueuePush(pq, 52);
	QueuePush(pq, 92);
	QueuePush(pq, 124);
	QueuePush(pq, 145);
	QueuePush(pq, 163);

	QueueState(pq);
	while (QueueEmpty(pq))
	{
		QueuePop(pq);
		QueueState(pq);
	}

	QueueDestory(pq);
}