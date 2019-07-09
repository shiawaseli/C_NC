#include"BinaryTree.h"

BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi, BTNode* parent)
{
	assert(a);
	assert(pi);

	BTNode *root = (BTNode*)malloc(sizeof(BTNode));

	if (*pi < n && a[*pi] != BTREE_END)
	{
		root->_data = a[*pi];
		(*pi)++;
		root->_pLeft = BinaryTreeCreate(a, n, pi, root);
		(*pi)++;
		root->_pRight = BinaryTreeCreate(a, n, pi, root);
		(*pi)++;
		root->_pParent = parent;
	}
	else
	{
		free(root);
		root = NULL;
	}

	return root;
}
void BinaryTreeDestory(BTNode** root)
{

}

int BinaryTreeSize(BTNode* root)
{

}
int BinaryTreeLeafSize(BTNode* root)
{

}
int BinaryTreeLevelKSize(BTNode* root, int k)
{

}
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{

}

// ���� 
void BinaryTreePrevOrder(BTNode* root)
{

}
void BinaryTreeInOrder(BTNode* root)
{

}
void BinaryTreePostOrder(BTNode* root)
{

}

// �ǵݹ���� // ������� 
void BinaryTreeLevelOrder(BTNode* root) 
{

}
// �ж϶������Ƿ�����ȫ������ 
int BinaryTreeComplete(BTNode* root)
{

}

void BinaryTreePrevOrderNonR(BTNode* root)
{

}
void BinaryTreeInOrderNonR(BTNode* root)
{

}
void BinaryTreePostOrderNonR(BTNode* root)
{

}

void BinaryTreePrint(BTNode* root)
{
	if (root)
	{
		BTREE_PRINT(root->_data);
		BinaryTreePrint(root->_pLeft);
		BinaryTreePrint(root->_pRight);
	}
}

void TestBinaryTree()
{

}