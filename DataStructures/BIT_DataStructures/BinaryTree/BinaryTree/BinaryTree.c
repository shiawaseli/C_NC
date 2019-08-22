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
		BinaryTreeInOrder(root->_pLeft);
		BTREE_PRINT(root->_data);
		BinaryTreeInOrder(root->_pRight);
	}
}
// �������
void BinaryTreePostOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreePostOrder(root->_pLeft);
		BinaryTreePostOrder(root->_pRight);
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
	assert(root);

	BTNode *stack[100], *cur;
	int top = -1;

	stack[++top] = root;
	while (top >= 0)
	{
		cur = stack[top--];
		if (cur)
		{
			BTREE_PRINT(cur->_data);
			stack[++top] = cur->_pRight;
			stack[++top] = cur->_pLeft;
		}
	}
}
// �������
void BinaryTreeInOrderNonR(BTNode* root)
{
	assert(root);

	BTNode *stack[100], *cur = root;
	int top = -1;

	while (top >= 0 || cur)
	{
		if (cur)
		{
			stack[++top] = cur;
			cur = cur->_pLeft;
		}
		else
		{
			cur = stack[top--];
			BTREE_PRINT(cur->_data);
			cur = cur->_pRight;
		}
	}
}
// �������
void BinaryTreePostOrderNonR(BTNode* root)
{
	assert(root);

	BTNode *stack[100], *cur = root, *last = root;
	int top = -1;

	stack[++top] = cur;
	cur = cur->_pLeft;
	while (top >= 0)
	{
		while (cur && cur->_pLeft != last && cur->_pRight != last)
		{
			stack[++top] = cur;
			cur = cur->_pLeft;
		}
		cur = stack[top--];
		if (!cur->_pRight || cur->_pRight == last)
		{
			last = cur;
			BTREE_PRINT(cur->_data);
			if (top >= 0)
			{
				cur = stack[top];
			}
		}
		else
		{
			stack[++top] = cur;
			cur = cur->_pRight;
		}
	}
}

// �ǵݹ���� 
// �������
void BinaryTreePrevOrderNonR2(BTNode* root)
{
	assert(root);

	BTNode *stack[100], *cur = root;
	int top = -1;

	while (top > -2)
	{
		BTREE_PRINT(cur->_data); // ���ʽ��
		if (cur->_pRight) // ������Һ��ӣ��Һ�����ջ
		{
			stack[++top] = cur->_pRight;
		}
		if (cur->_pLeft) // ��������ӣ��ȷ�������
		{
			cur = cur->_pLeft;
		}
		else // û�����ӣ�����ջ��
		{
			cur = stack[top--];
		}
	}
}
// �������
void BinaryTreeInOrderNonR2(BTNode* root)
{
	assert(root);

	BTNode *stack[100], *cur = root;
	int top = -1;

	while (top > -2)
	{
		while (cur && cur->_pLeft && cur != stack[top + 1])
		{
			stack[++top] = cur;
			cur = cur->_pLeft;
		}
		BTREE_PRINT(cur->_data);
		if (cur->_pRight)
		{
			cur = cur->_pRight;
		}
		else
		{
			cur = stack[top--];
		}
	}
}
// �������
void BinaryTreePostOrderNonR2(BTNode* root)
{
	assert(root);

	BTNode *stack[100], *cur = root, *last = root;
	int top = -1;

	while (top > -2)
	{
		while (cur && cur->_pLeft && cur != stack[top + 1])
		{
			stack[++top] = cur;
			cur = cur->_pLeft;
		}
		if (cur->_pRight && cur->_pRight != stack[top + 2])
		{
			stack[++top] = cur;
			cur = cur->_pRight;
		}
		else
		{
			BTREE_PRINT(cur->_data);
			stack[top + 1] = cur;
			cur = stack[top--];
		}
	}
}
// �������
void BinaryTreeInOrderNonR3(BTNode* root)
{
	assert(root);

	BTNode *stack[100], *cur = root;
	int top = -1;

	while (top >= 0 || cur)
	{
		for (; cur; cur = cur->_pLeft) // ����ǰ��������������ջ
		{
			stack[++top] = cur;
		}
		if (top >= 0)
		{
			cur = stack[top--]; // ����ջ����δ���ʽ���������·��Ľ�㣩
			BTREE_PRINT(cur->_data); // ���ʽ��
			cur = cur->_pRight; 
		}
	}
}
// �������
void BinaryTreePostOrderNonR3(BTNode* root)
{
	assert(root);

	BTNode *stack[100], *cur = root, *last = root;
	int tag[100] = { 0 };
	int top = -1;

	do
	{
		for (; cur; cur = cur->_pLeft) // ����ǰ��������������ջ����� 0
		{
			stack[++top] = cur;
			tag[top] = 0;
		}
		while (top >= 0 && tag[top]) // ����ջ�������Һ����ѷ��ʹ��Ľ��
		{
			cur = stack[top--];
			BTREE_PRINT(cur->_data);
		}
		if (top >= 0)
		{
			cur = stack[top];
			cur = cur->_pRight;
			tag[top] = 1; // ��ʾ�Ѿ����ʹ��Һ��ӽ��
		}
	} while (top >= 0);
}

// ͨ�����ø��ֱ�������ӡ
void BinaryTreePrint(BTNode* root)
{
	assert(root);

	printf("\n���������");
	BinaryTreePrevOrder(root);
	printf("(����ʵ��)\t");
	BinaryTreePrevOrderNonR(root);
	printf("(�Ǳ���ʵ��)\t");
	BinaryTreePrevOrderNonR2(root);
	printf("(�Ǳ���ʵ��2)\t");

	printf("\n���������");
	BinaryTreeInOrder(root);
	printf("(����ʵ��)\t");
	BinaryTreeInOrderNonR(root);
	printf("(�Ǳ���ʵ��)\t");
	BinaryTreeInOrderNonR2(root);
	printf("(�Ǳ���ʵ��2)\t");
	BinaryTreeInOrderNonR3(root);
	printf("(�Ǳ���ʵ��3)\t");

	printf("\n���������");
	BinaryTreePostOrder(root);
	printf("(����ʵ��)\t");
	BinaryTreePostOrderNonR(root);
	printf("(�Ǳ���ʵ��)\t");
	BinaryTreePostOrderNonR2(root);
	printf("(�Ǳ���ʵ��2)\t");
	BinaryTreePostOrderNonR3(root);
	printf("(�Ǳ���ʵ��3)\t");

	printf("\n���������");
	BinaryTreeLevelOrder(root);
	putchar('\n');
}

// ���Ժ���
void TestBinaryTree()
{
	BTNode *root, *tmp;
	BTDataType a[100] = "ABD##E#H##CF##G##";
	BTDataType a2[100] = "ABD##E##CF##G##";
	BTDataType a3[100] = "ABDK##N##E##CF##G##";
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