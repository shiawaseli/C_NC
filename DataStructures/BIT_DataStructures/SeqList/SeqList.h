#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

#ifndef _SEQLIST_H_
#define _SEQLIST_H_
// ˳���Ķ�̬�洢 

#define SLDataType int //˳��������

typedef struct SeqList
{
	SLDataType* array;  // ָ��̬���ٵ�����     
	size_t size;       // ��Ч���ݸ���     
	size_t capacity;   // �����ռ�Ĵ�С 
}SeqList;

// ������ɾ��Ľӿ� 
void SeqListInit(SeqList* psl, size_t capacity); //˳����ʼ��
void SeqListDestory(SeqList* psl); //˳�������

void CheckCapacity(SeqList* psl); //˳�������ʱ����˳�������Ϊ����
void SeqListPushBack(SeqList* psl, SLDataType x); //�ӱ�β��������
void SeqListPopBack(SeqList* psl); //�ӱ�βɾ������
void SeqListPushFront(SeqList* psl, SLDataType x); //�ӱ�ͷ��������
void SeqListPopFront(SeqList* psl); //�ӱ�ͷɾ������

int SeqListFind(SeqList* psl, SLDataType x); //��˳����в�������
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x); //��posλ�ò�������
void SeqListErase(SeqList* psl, size_t pos); //ɾ��posλ�õ�����
void SeqListRemove(SeqList* psl, SLDataType x); //ɾ�����ȳ��ֵ�ָ������
void SeqListModify(SeqList* psl, size_t pos, SLDataType x); //�޸�posλ�õ�����Ϊָ������
void SeqListPrint(SeqList* psl); //��ӡ˳���

// ��չ������ʵ��
void SeqListBubbleSort(SeqList* psl); //ð������
int SeqListBinaryFind(SeqList* psl, SLDataType x); //���ֲ���

// ����Ҫ��ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(1) 

void SeqListRemoveAll(SeqList* psl, SLDataType x); //ɾ���ظ���ָ������
#endif // !_SEQLIST_H_
