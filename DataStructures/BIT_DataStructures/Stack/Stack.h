#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>

#ifndef _STACK_H_
#define _STACK_H_

#define N 10

#define INT 1
#define CHAR 2
#define STACKDATATYPE CHAR

#if STACKDATATYPE == INT

typedef int STDataType; 
#define PRINT(data) printf("%2d || ", (data))
#define PLUS 0

#elif STACKDATATYPE == CHAR

typedef char STDataType;
#define PRINTSTACK(data) printf("|| %c ", (data))
#define PRINTQUEUE(data) printf("%c || ", (data))
#define PLUS '0'

#endif

typedef struct Stack 
{
	STDataType* _data;    
	int _top;       // ջ��    
	int _capacity;  // ���� 
}Stack;

typedef struct QueueByStack
{
	Stack *queue;
	Stack *tmp;
}QueueByStack;

void StackInit(Stack* ps); // ջ��ʼ��
void StackDestory(Stack* ps); // ջ����

void StackPush(Stack* ps, STDataType val); // ������ջ
STDataType StackPop(Stack* ps); // ���ݳ�ջ
STDataType StackTop(Stack* ps); // �õ�ջ������(����ջ)
int StackEmpty(Stack* ps); // �ж�ջ�Ƿ�Ϊ��ջ
int StackSize(Stack* ps); // ��ջ����ʱ����������Ϊ����������ջ��Ԫ�صĸ�����
void StackPrint(Stack* ps); // ��ӡ��ǰջ��Ԫ��

int IsValid(char *str); // �ж������Ƿ�ƥ��

void TestStack(); // �����������й���ջ�ĺ���


// ջʵ�ֵĶ���


void QueueInit(QueueByStack* ps); // ���г�ʼ��
void QueueDestory(QueueByStack* ps); // ��������
void QueuePush(QueueByStack* pq, STDataType val); // �������
STDataType QueuePop(QueueByStack* pq); // ���ݳ���
STDataType QueueTop(QueueByStack* pq); // �õ���������(������)
int QueueEmpty(QueueByStack* pq); // �ж϶����Ƿ�Ϊ�ն�
void QueuePrint(QueueByStack* pq); // ��ӡ��ǰ������Ԫ��

void TestQueueByStack(); // �����������й�����ջʵ�ֵĶ��еĺ���

#endif // _STACK_H_