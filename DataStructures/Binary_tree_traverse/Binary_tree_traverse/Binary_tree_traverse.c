#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	char data;
	struct Node* left;
	struct Node* right;
}TREE;
//stack_trees
TREE gs_trees[1000];
int top = -1;
//queue_trees
TREE gq_trees[1000];
int head = 0;
int tail = 0;

void CreateTree(TREE **t)
{
	char ch;

	ch = getchar();
	if (ch == '#')
	{
		*t = NULL;
	}
	else
	{
		if (!(*t = (TREE*)malloc(sizeof(TREE))))
		{
			printf("�ռ�����ʧ��\n");
		}
		else
		{
			(*t)->data = ch;
			CreateTree(&(*t)->left);
			CreateTree(&(*t)->right);
		}
	}
}

void InOrderTraval(TREE *t)
{
	if (t == NULL)
	{
		putchar('#');
	}
	else
	{
		InOrderTraval(t->left);
		putchar(t->data);
		InOrderTraval(t->right);
	}
}

void InOrderTraval_unre(TREE *t)
{
	TREE *p = t, *q = NULL;

	while (1)
	{
		if (p != NULL && p->left != NULL && q != p)
		{
			gs_trees[++top] = *p;
			p = p->left;
			q = NULL;
		}
		else if(p != NULL)
		{
			if (p->left == NULL)
			{
				putchar('#');
			}
			else if(p != q)
			{
				gs_trees[++top] = *p;
				p = p->left;
				continue;
			}
			putchar(p->data);
			if (p->right == NULL)
			{
				putchar('#');
				p = NULL;
				if (top == -1)
				{
					break;
				}
			}
			else
			{
				p = p->right;
			}
		}
		else if (p == NULL)
		{
			p = &gs_trees[top--];
			q = p;
		}
	}
	putchar('\n');
}

void TreeQueueTraval(TREE *t)
{
	TREE *p;

	gq_trees[tail++] = *t;
	while (head < tail)
	{
		p = &gq_trees[head++];
		putchar(p->data);
		if (p->left != NULL)
		{
			gq_trees[tail++] = *(p->left);
		}
		if (p->right != NULL)
		{
			gq_trees[tail++] = *(p->right);
		}
	}
	putchar('\n');
}

int TreeHeight(TREE *t)
{
	int left = 0, right = 0;

	if (t == NULL)
	{
		return 0;
	}
	left = TreeHeight(t->left);
	right = TreeHeight(t->right);

	return left > right ? left + 1 : right + 1;
}

int TreeNodeCount(TREE *t)
{
	int count = 1;

	if (t == NULL)
	{
		return 0;
	}
	count += TreeNodeCount(t->left);
	count += TreeNodeCount(t->right);

	return count;
}

int TreeLeafCount(TREE *t)
{
	int count = 0;

	if (t == NULL)
	{
		return 0;
	}
	else if (t->left == NULL || t->right == NULL)
	{
		return 1;
	}
	count += TreeLeafCount(t->left);
	count += TreeLeafCount(t->right);

	return count;
}

void TreeExchange(TREE *t)
{
	TREE *tmp;

	if (t == NULL)
	{
		return;
	}
	tmp = t->left;
	t->left = t->right;
	t->right = tmp;
	TreeExchange(t->left);
	TreeExchange(t->right);
}

void Menu()
{
	putchar('\n');
	putchar('\n');
	printf("0.�˳�\n");
	printf("1.��д����, �����ַ�����, �����������Ķ�������\n");
	printf("2.��д����, ʵ�ֶ�����������ݹ�����㷨\n");
	printf("3.��д����, ʵ�ֶ�����������ǵݹ�����㷨\n");
	printf("4.��д����, ��������ʵ�ֶ������Ĳ�α����㷨\n");
	printf("5.��д����, ��������ĸ߶�\n");
	printf("6.��д����, ��������Ľ�����\n");
	printf("7.��д����, ���������Ҷ�Ӹ���\n");
	printf("8.��д����, ����������ÿ��������������������\n");
	putchar('\n');
	putchar('\n');
}

int main()
{
	int choice, flag = 1;
	TREE *tree = NULL;

	while (flag)
	{
		Menu();
		scanf("%d", &choice);
		switch (choice)
		{
		case 0:
			flag = 0;
			break;
		case 1:
			printf("����������abd##e##cf##g##\n");
			//printf("��������2(����ʹ��)��abd##eh###cfi###g##\n");
			getchar();
			CreateTree(&tree);
			printf("������ɶ�������\n");
			break;
		case 2:
			printf("������������ݹ����:>");
			InOrderTraval(tree);
			putchar('\n');
			printf("����������\n");
			break;
		case 3:
			printf("������������ǵݹ����:>");
			InOrderTraval_unre(tree);
			printf("����������\n");
			break;
		case 4:
			printf("��������ʵ�ֶ������Ĳ�α���:>");
			TreeQueueTraval(tree);
			printf("����������\n");
			break;
		case 5:
			printf("�������ĸ߶�Ϊ%d\n", TreeHeight(tree));
			break;
		case 6:
			printf("�������Ľ�����Ϊ%d��\n", TreeNodeCount(tree));
			break;
		case 7:
			printf("��������Ҷ�Ӹ���Ϊ%d��\n", TreeLeafCount(tree));
			break;
		case 8:
			printf("����������ÿ��������������������\n");
			TreeExchange(tree);
			printf("������ɡ�\n");
			break;
		default:
			break;
		}
	}
	
	system("pause");
	return 0;
}