#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

#define QueueElementType int
#define StackElementType int
#define FALSE 0
#define TRUE 1
#define MAX 100

//ѭ������
typedef struct
{
	QueueElementType data[MAX];
	int front;
	int rear;
	int flag;
}SeqQueue;

int SeqQueueInit(SeqQueue *Q)
{
	Q->front = 0;
	Q->rear = 0;
	Q->flag = -1;

	return TRUE;
}

int SeqQueueEnter(SeqQueue *Q, QueueElementType elem)
{
	if (Q->rear == Q->front && Q->flag == 1)
	{
		return FALSE;
	}
	Q->data[Q->rear] = elem;
	Q->rear = (Q->rear + 1) % MAX;
	Q->flag = 1;

	return TRUE;
}

int SeqQueueDelete(SeqQueue *Q, QueueElementType *elem)
{
	if (Q->front == Q->rear && Q->flag == -1)
	{
		return FALSE;
	}
	*elem = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAX;
	Q->flag = -1;

	return TRUE;
}

//������
typedef struct QUEUE
{
	QueueElementType data;
	struct QUEUE *next;
}*LinkQueueNode, QueueNode;

typedef struct
{
	QueueNode *front;
	QueueNode *rear;
}LinkQueue;

int LQInit(LinkQueue *Q)
{
	LinkQueueNode pq = (LinkQueueNode)malloc(sizeof(QueueNode));
	if (pq == NULL)
	{
		return FALSE;
	}
	pq->next = NULL;
	Q->front = pq;
	Q->rear = pq;

	return TRUE;
}

int LQEnter(LinkQueue *Q, QueueElementType elem)
{
	QueueNode *p = (QueueNode*)malloc(sizeof(QueueNode));
	if (p == NULL)
	{
		return FALSE;
	}
	p->data = elem;
	p->next = Q->rear->next;
	Q->rear->next = p;
	Q->rear = p;

	return TRUE;
}

int LQDelete(LinkQueue *Q, QueueElementType *elem)
{
	QueueNode *tmp;

	if (Q->rear == Q->front)
	{
		return FALSE;
	}
	tmp = Q->front->next;
	Q->front->next = tmp->next;
	*elem = tmp->data;
	free(tmp);

	return TRUE;
}

//˳��ջ
typedef struct SEPSTACK
{
	StackElementType data[MAX];
	int top;
}SeqStack;

int SeqStackInit(SeqStack S)
{
	S.top = -1;
	return TRUE;
}

int SeqStackPush(SeqStack *S, StackElementType elem)
{
	if (S->top + 1 == MAX)
	{
		return FALSE;
	}
	S->top++;
	S->data[S->top] = elem;

	return TRUE;
}

int SeqStackPop(SeqStack *S, StackElementType *elem)
{
	if (S->top == -1)
	{
		return FALSE;
	}
	*elem = S->data[S->top];
	S->top--;

	return TRUE;
}

//��ջ
typedef struct STACK
{
	StackElementType data;
	struct STACK *next;
}*LinkStack, Stack;

int LSInit(LinkStack *top)
{
	*top = (LinkStack)malloc(sizeof(Stack));
	if (*top == NULL)
	{
		return FALSE;
	}
	(*top)->next = NULL;

	return TRUE;
}

int LSPush(LinkStack top, StackElementType elem)
{
	Stack *ps;

	ps = (Stack*)malloc(sizeof(Stack));
	if (ps == NULL)
	{
		return FALSE;
	}
	ps->data = elem;
	ps->next = top->next;
	top->next = ps;

	return TRUE;
}

int LSPop(LinkStack top, StackElementType *elem)
{
	Stack *ps;

	if (top->next == NULL)
	{
		return FALSE;
	}
	ps = top->next;
	top->next = ps->next;
	*elem = ps->data;
	free(ps);

	return TRUE;
}

void Menu()
{
	printf("\n\n");
	printf("0���˳�\n");
	printf("1��������ʽ�洢ʵ��ջ�ĳ�ʼ������ջ����ջ����\n");
	printf("2������˳��洢ʵ��ջ�ĳ�ʼ������ջ����ջ����\n");
	printf("3��������ʽ�洢ʵ�ֶ��еĳ�ʼ������ӡ����Ӳ���\n");
	printf("4������˳��洢ʵ�ֶ��еĳ�ʼ������ӡ����Ӳ���\n");
	printf("\n\n\n");
}

int main()
{
	int i, n, choice = -1;
	LinkStack LS;
	SeqStack SS = { 0 };
	LinkQueue LQ;
	SeqQueue SQ;
	StackElementType s_elem;
	QueueElementType q_elem;

	LSInit(&LS);
	SeqStackInit(SS);
	LQInit(&LQ);
	SeqQueueInit(&SQ);

	while (choice)
	{
		Menu();
		if (!scanf("%d", &choice))
		{
			choice = -1;
			getchar();
		}
		switch (choice)
		{
		case 1:
			printf("Ҫ��(��)ջ��Ԫ�ظ���:>");
			scanf("%d", &n);
			printf("��ջ:>");
			for (i = 0; i < n; i++)
			{
				scanf("%d", &s_elem);
				LSPush(LS, s_elem);
			}
			printf("\n��ջ:>");
			for (i = 0; i < n; i++)
			{
				LSPop(LS, &s_elem);
				printf("%d ", s_elem);
			}
			break;
		case 2:
			printf("Ҫ��(˳��)ջ��Ԫ�ظ���:>");
			scanf("%d", &n);
			printf("��ջ:>");
			for (i = 0; i < n; i++)
			{
				scanf("%d", &s_elem);
				SeqStackPush(&SS, s_elem);
			}
			printf("\n��ջ:>");
			for (i = 0; i < n; i++)
			{
				SeqStackPop(&SS, &s_elem);
				printf("%d ", s_elem);
			}
			break;
		case 3:
			printf("Ҫ��(��)���е�Ԫ�ظ���:>");
			scanf("%d", &n);
			printf("������:>");
			for (i = 0; i < n; i++)
			{
				scanf("%d", &q_elem);
				LQEnter(&LQ, q_elem);
			}
			printf("\n������:>");
			for (i = 0; i < n; i++)
			{
				LQDelete(&LQ, &q_elem);
				printf("%d ", q_elem);
			}
			break;
		case 4:
			printf("Ҫ��(˳��)���е�Ԫ�ظ���:>");
			scanf("%d", &n);
			printf("������:>");
			for (i = 0; i < n; i++)
			{
				scanf("%d", &q_elem);
				SeqQueueEnter(&SQ, q_elem);
			}
			printf("\n������:>");
			for (i = 0; i < n; i++)
			{
				SeqQueueDelete(&SQ, &q_elem);
				printf("%d ", q_elem);
			}
			break;
		default:
			break;
		}
		putchar('\n');
	}
	
	system("pause");
	return 0;
}
