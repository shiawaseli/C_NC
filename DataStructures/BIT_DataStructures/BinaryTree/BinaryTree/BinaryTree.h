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
typedef struct BinaryTreeNode 
{    
	struct BinTreeNode* _pParent; // ָ��ǰ�ڵ��˫��    
	struct BinTreeNode* _pLeft;   // ָ��ǰ�ڵ�����    
	struct BinTreeNode* _pRight; // ָ��ǰ�ڵ��Һ���    
	BTDataType _data; // ��ǰ�ڵ�ֵ�� 
}BTNode;
// ͨ��ǰ�����������"ABD##E#H##CF##G##"���������� 
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi, BTNode* parent); 
void BinaryTreeDestory(BTNode** root);

int BinaryTreeSize(BTNode* root); 
int BinaryTreeLeafSize(BTNode* root); 
int BinaryTreeLevelKSize(BTNode* root, int k);
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

// ���� 
void BinaryTreePrevOrder(BTNode* root); 
void BinaryTreeInOrder(BTNode* root); 
void BinaryTreePostOrder(BTNode* root);

// �ǵݹ���� // ������� 
void BinaryTreeLevelOrder(BTNode* root); 
// �ж϶������Ƿ�����ȫ������ 
int BinaryTreeComplete(BTNode* root);

void BinaryTreePrevOrderNonR(BTNode* root); 
void BinaryTreeInOrderNonR(BTNode* root); 
void BinaryTreePostOrderNonR(BTNode* root);

void BinaryTreePrint(BTNode* root);

void TestBinaryTree();

#endif //_BINARYTREE_H_