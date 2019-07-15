#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>

#ifndef _BINARYTREE_H_

#define _BINARYTREE_H_

#define BTREE_END '#'
#define BTREE_PRINT(data) printf("%c ", (data))
typedef char BTDataType;

// ������ 
typedef struct BTNode
{    
	struct BTNode* _pParent; // ָ��ǰ�ڵ��˫��    
	struct BTNode* _pLeft;   // ָ��ǰ�ڵ�����    
	struct BTNode* _pRight; // ָ��ǰ�ڵ��Һ���    
	BTDataType _data; // ��ǰ�ڵ�ֵ�� 
}BTNode;
// ͨ���������������"ABD##E#H##CF##G##"���������� 
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi, BTNode* parent); // �������Ľ���
void BinaryTreeDestory(BTNode** root); // ������������

int BinaryTreeSize(BTNode* root); // �������Ľ����
int BinaryTreeLeafSize(BTNode* root); // ��������Ҷ�ӽ����
int BinaryTreeLevelKSize(BTNode* root, int k); // ��������ָ����Ľ����
BTNode* BinaryTreeFind(BTNode* root, BTDataType x); // ����ָ������

//�ݹ����
void BinaryTreePrevOrder(BTNode* root); // �������
void BinaryTreeInOrder(BTNode* root);  // �������
void BinaryTreePostOrder(BTNode* root); // �������

void BinaryTreeLevelOrder(BTNode* root); // �������
int BinaryTreeComplete(BTNode* root); // �ж϶������Ƿ�����ȫ������ 

// �ǵݹ����
void BinaryTreePrevOrderNonR(BTNode* root); // �������
void BinaryTreeInOrderNonR(BTNode* root); // �������
void BinaryTreePostOrderNonR(BTNode* root); // �������

void BinaryTreePrint(BTNode* root); // ͨ�����ø��ֱ�������ӡ

void TestBinaryTree(); // ���Ժ���

#endif //_BINARYTREE_H_