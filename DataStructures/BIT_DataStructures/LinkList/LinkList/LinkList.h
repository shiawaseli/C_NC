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
}SList; // ��ͷ�����ѭ�������ͷָ��

void SListInit(SList* plist); // �����ʼ��
void SListDestory(SList* plist); // ��������

SListNode* BuySListNode(SLTDataType val); // �����ݷ���һ�����
void SListPushFront(SList* plist, SLTDataType val); // ͷ�巨��������
void SListPopFront(SList* plist); // ͷɾ��ɾ������
SListNode* SListFind(SList* plist, SLTDataType val); // �������в�������

void SListInsertAfter(SListNode* pos, SLTDataType val); // ��pos�ĺ�����в��� 
void SListInsertFront(SList* plist, SListNode* pos, SLTDataType val); // ��pos��ǰ����в��� 
void SListEraseAfter(SListNode* pos); // ɾ��pos��һ��λ�õ�����
void SListRemove(SList* plist, SLTDataType val); // ɾ�����ȳ��ֵ�ָ������

void SListReverse(SList* plist); // ����ת
SListNode* GetIntersectionNode(SList* listA, SList* listB); // �ж��������Ƿ��ཻ�������ཻ���
int SListHasCycle(SList* plist); // �ж������Ƿ�ɻ�
SListNode* SListDetectCycle(SList* plist); // �ҵ��뻷���

int RemoveElements(SList* head, int val); // ɾ������ָ�����ݣ�����ɾ�����ݵĸ���
SListNode* MiddleNode(SList* head); // �����м���(ż�������ʱΪƫ�ҽ��)
void SListQuickSort(SListNode *head); // ��������
SListNode* MergeTwoLists(SList* plist1, SList* plist2); // ��������ϲ�
SListNode* SListClone(SList* plist); // ������
SListNode* SListPartition(SList* plist, int val); // �Ը���ֵ val Ϊ��׼����ԭ��������˳������ָ��������
SListNode* DeleteDuplication(SList* plist); // ����������ɾ���ظ����
int CheckPalindrome(SList* plist); // ���������ж�
SListNode* AddTwoNumbers(SList* plist1, SList* plist2); // ������ӣ� �������ݰ������ֵ�ÿһλ�ĵ������洢

void SListPrint(SList* plist); // ��ӡ����
void TestSList(); // ���Ժ���

#endif //_LINKLIST_H_