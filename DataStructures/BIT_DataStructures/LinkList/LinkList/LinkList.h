#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

#ifndef _LINKLIST_H_
#define _LINKLIST_H_

// 1����ͷ�����ѭ��������ɾ���ʵ�� 

typedef int SLTDataType; //��ͷ�����ѭ�����������

typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode* _next;
}SListNode;//��ͷ�����ѭ������Ľ��

typedef struct SList
{
	SListNode* _head;
}SList;//��ͷ�����ѭ�������ͷ���

void SListInit(SList* plist); //�����ʼ��
void SListDestory(SList* plist); //��������

SListNode* BuySListNode(SLTDataType x); //�����ݷ���һ�����
void SListPushFront(SList* plist, SLTDataType x); //ͷ�巨��������
void SListPopFront(SList* plist); //ͷɾ��ɾ������
SListNode* SListFind(SList* plist, SLTDataType x); //�������в�������

void SListInsertAfter(SListNode* pos, SLTDataType x); // ��pos�ĺ�����в��� 
void SListInsertFront(SList* plist, SListNode* pos, SLTDataType x); // ��pos��ǰ����в��� 
void SListEraseAfter(SListNode* pos); //ɾ��pos��һ��λ�õ�����
void SListRemove(SList* plist, SLTDataType x); //ɾ�����ȳ��ֵ�ָ������

void SListPrint(SList* plist); //��ӡ����
void TestSList();

void SListReverse(SList* plist); //����ת
SListNode* GetIntersectionNode(SList* listA, SList* listB); //�ж��������Ƿ��ཻ
int SListHasCycle(SList* plist); //�ж������Ƿ�ɻ�
SListNode* SListDetectCycle(SList* plist); //�ҵ��뻷���

#endif //_LINKLIST_H_