#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

#ifndef _STACK_H_
#define _STACK_H_

#define N 10
typedef int STDataType; 

typedef struct Stack 
{
	STDataType* _a;    
	int _top;       // ջ��    
	int _capacity;  // ���� 
}Stack;

void StackInit(Stack* ps); //ջ��ʼ��
void StackDestory(Stack* ps); //ջ����

void StackPush(Stack* ps, STDataType x); //������ջ
void StackPop(Stack* ps); //���ݳ�ջ
STDataType StackTop(Stack* ps); //�õ�ջ������(����ջ)
int StackEmpty(Stack* ps); //�ж�ջ�Ƿ�Ϊ��ջ
int StackSize(Stack* ps); //��ջ����ʱ����������Ϊ����������ջ��Ԫ�صĸ�����
void StackPrint(Stack* ps); //��ӡ��ǰջ��Ԫ��

void TestStack(); //�����������еĺ���

#endif //_STACK_H_