#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

#ifndef _DLINKLIST_H_
#define _DLINKLIST_H_

// 2����ͷ˫��ѭ��������ɾ���ʵ�� 

typedef int LTDataType; //��ͷ˫��ѭ�����������

typedef struct DListNode
{
	LTDataType _data;
	struct DListNode* _next;
	struct DListNode* _prev;
}DListNode; //��ͷ˫��ѭ������Ľ��

typedef struct List
{
	DListNode* _head;
}DList; //��ͷ˫��ѭ�������ͷ���

void DListInit(DList* plist); //�����ʼ��
void DListDestory(DList* plist); //��������

void DListPushStart(DList* plist, LTDataType x); //ͷ�巨��������
void DListPopStart(DList* plist); //ͷ�巨ɾ������
void DListPushTail(DList* plist, LTDataType x); //β�巨��������
void DListPopTail(DList* plist); //β�巨ɾ������

DListNode* DListFind(DList* plist, LTDataType x); //�������в�������

void DListInsertBefore(DListNode* pos, LTDataType x); //��pos��ǰ����в���
void DListInsertAfter(DListNode* pos, LTDataType x); //��pos�ĺ�����в���
void DListErase(DListNode* pos); //ɾ��posλ�õĽ��
void DListRemove(DList* plist, LTDataType x); //ɾ����������Ϊx�Ľ��

void DListPrint(DList* plist); //��ӡ����

#endif //_DLINKLIST_H_