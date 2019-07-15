#include"BinaryTree.h"

// �������Ľ���
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
		root->_pParent = parent;
	}
	else
	{
		free(root);
		root = NULL;
	}

	return root;
}
// ������������
void BinaryTreeDestory(BTNode** root)
{
	if ((*root)->_pLeft)
	{
		BinaryTreeDestory(&((*root)->_pLeft));
	}
	if ((*root)->_pRight)
	{
		BinaryTreeDestory(&((*root)->_pRight));
	}
	if (*root)
	{
		free(*root);
	}
}
// �������Ľ����
int BinaryTreeSize(BTNode* root)
{
	assert(root);

	int count = 1;

	if (root->_pLeft)
	{
		count += BinaryTreeSize(root->_pLeft);
	}
	if (root->_pRight)
	{
		count += BinaryTreeSize(root->_pRight);
	}

	return count;
}
// ��������Ҷ�ӽ����
int BinaryTreeLeafSize(BTNode* root)
{
	assert(root);

	int count = 0;

	if (!root->_pLeft && !root->_pRight)
	{
		return 1;
	}
	if (root->_pLeft)
	{
		count += BinaryTreeLeafSize(root->_pLeft);
	}
	if (root->_pRight)
	{
		count += BinaryTreeLeafSize(root->_pRight);
	}

	return count;
}
// ��������ָ����Ľ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	assert(root);

	int count = 0;

	if (k == 1)
	{
		return 1;
	}
	if (root->_pLeft)
	{
		count += BinaryTreeLevelKSize(root->_pLeft, k - 1);
	}
	if (root->_pRight)
	{
		count += BinaryTreeLevelKSize(root->_pRight, k - 1);
	}

	return count;
}
// ����ָ������
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	assert(root);

	BTNode *cur = NULL;

	if (root->_data == x)
	{
		return root;
	}
	if (root->_pLeft)
	{
		cur = BinaryTreeFind(root->_pLeft, x);
	}
	if (!cur && root->_pRight)
	{
		cur = BinaryTreeFind(root->_pRight, x);
	}

	return cur;
}

// �ݹ���� 
// �������
void BinaryTreePrevOrder(BTNode* root)
{
	if (root)
	{
		BTREE_PRINT(root->_data);
		BinaryTreePrevOrder(root->_pLeft);
		BinaryTreePrevOrder(root->_pRight);
	}
}
// �������
void BinaryTreeInOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreePrevOrder(root->_pLeft);
		BTREE_PRINT(root->_data);
		BinaryTreePrevOrder(root->_pRight);
	}
}
// �������
void BinaryTreePostOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreePrevOrder(root->_pLeft);
		BinaryTreePrevOrder(root->_pRight);
		BTREE_PRINT(root->_data);
	}
}

// ������� 
void BinaryTreeLevelOrder(BTNode* root) 
{
	assert(root);

	BTNode *queue[100];
	int head = 0, tail = 0;

	queue[tail++] = root;
	while (head != tail)
	{
		BTREE_PRINT(queue[head]->_data);
		if (queue[head]->_pLeft)
		{
			queue[tail++] = queue[head]->_pLeft;
		}
		if (queue[head]->_pRight)
		{
			queue[tail++] = queue[head]->_pRight;
		}
		head++;
	}
}
// �ж϶������Ƿ�����ȫ������ 
int BinaryTreeComplete(BTNode* root)
{
	assert(root);

	BTNode *queue[100];
	int head = 0, tail = 0;

	queue[tail++] = root;
	while (head != tail)
	{
		if (!queue[head])
		{
			break;
		}
		queue[tail++] = queue[head]->_pLeft;
		queue[tail++] = queue[head]->_pRight;
		head++;
	}
	while (head != tail)
	{
		if (queue[head])
		{
			return 0;
		}
		head++;
	}

	return 1;
}

// �ǵݹ���� 
// �������
void BinaryTreePrevOrderNonR(BTNode* root)
{

}
// �������
void BinaryTreeInOrderNonR(BTNode* root)
{

}
// �������
void BinaryTreePostOrderNonR(BTNode* root)
{

}

// ͨ�����ø��ֱ�������ӡ
void BinaryTreePrint(BTNode* root)
{
	assert(root);

	printf("\n���������");
	BinaryTreePrevOrder(root);
	printf("\n���������");
	BinaryTreeInOrder(root);
	printf("\n���������");
	BinaryTreePostOrder(root);
	printf("\n���������");
	BinaryTreeLevelOrder(root);
	putchar('\n');
}

// ���Ժ���
void TestBinaryTree()
{
	BTNode *root, *tmp;
	BTDataType a1[100] = "ABD##E#H##CF##G##";
	BTDataType a2[100] = "ABD##E##CF##G##";
	BTDataType a[100] = "ABDK##N##E##CF##G##";
	int pi = 0, n = strlen(a), ret;

	root = BinaryTreeCreate(a, n, &pi, NULL);
	if (BinaryTreeComplete(root))
	{
		printf("����ȫ������!\n");
	}
	else
	{
		printf("������ȫ������!\n");
	}
	ret = BinaryTreeSize(root);
	printf("BinaryTreeSize = %d\n", ret);
	ret = BinaryTreeLeafSize(root);
	printf("BinaryTreeLeafSize = %d\n", ret);
	ret = BinaryTreeLevelKSize(root, 5);
	printf("BinaryTreeLevelKSize = %d\n", ret);
	tmp = BinaryTreeFind(root, 'C');
	BinaryTreePrint(tmp);
	putchar('\n');
	BinaryTreePrint(root);
	putchar('\n');
	BinaryTreeDestory(&root);
}