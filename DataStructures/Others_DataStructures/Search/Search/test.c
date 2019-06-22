#define _CRT_SECURE_NO_WARNINGS 1

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int data[100];
	int top;
}List;

typedef struct Tree
{
	char data;
	struct Tree *left;
	struct Tree *right;
}Tree;

int Insert(List **p)
{
	int i, input;

	scanf("%d", &input);
	if ((*p)->top + 1 == 100)
	{
		printf("OVER ERROR!\n");
		return 0;
	}
	for (i = (*p)->top; i >= 0; i--)
	{
		if (input > (*p)->data[i])
		{
			break;
		}
		(*p)->data[i + 1] = (*p)->data[i];
	}
	(*p)->data[i + 1] = input;

	return 1;
}

void InsertCreat(List **p)
{
	int i, num;

	(*p)->top = -1;
	printf("�������ֵĸ���(<=100):>");
	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		if (Insert(p))
		{
			(*p)->top++;
		}
		else
		{
			return;
		}
	}
}

int BSearch(List *p, int k)
{
	int left = 0;
	int right = p->top;
	int mid;

	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (p->data[mid] > k)
		{
			right = mid - 1;
		}
		else if (p->data[mid] < k)
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}

	return -1;
}

void InputTree(Tree **tree, char input)
{
	Tree *p = *tree;

	while ((p->data >= '0' && p->data <= '9') || (p->data >= 'a' && p->data <= 'z') || (p->data >= 'A' && p->data <= 'Z'))
	{
		if (p->data < input)
		{
			if (p->right == NULL)
			{
				p->right = (Tree*)malloc(sizeof(Tree));
				p->right->data = input;
				p->right->right = NULL;
				p->right->left = NULL;
				break;
			}
			p = p->right;
		}
		else
		{
			if (p->left == NULL)
			{
				p->left = (Tree*)malloc(sizeof(Tree));
				p->left->data = input;
				p->left->right = NULL;
				p->left->left = NULL;
				break;
			}
			p = p->left;
		}
	}
}

void CandomCreate(Tree **tree)
{
	char tmp[100] = { 0 };
	int i, num, flag, book[130] = { 0 };

	srand((unsigned int)time(NULL));
	printf("����������ؼ��ֵĳ���(<=100):>");
	scanf("%d", &num);
	if (!num)
	{
		printf("ʲô��û������,����������ʧ��!\n");
		return;
	}
	for (i = 0; i < num; i++)
	{
		flag = rand() % 3;
		if (flag == 1)
		{
			tmp[i] = rand() % 10 + '0';
		}
		else if(flag == 2)
		{
			tmp[i] = rand() % 26 + 'a';
		}
		else
		{
			tmp[i] = rand() % 26 + 'A';
		}
		if (book[tmp[i]])
		{
			i--;
		}
		book[tmp[i]]++;
	}
	printf("����ؼ���Ϊ:%s\n", tmp);
	*tree = malloc(sizeof(Tree));
	(*tree)->left = NULL;
	(*tree)->right = NULL;
	(*tree)->data = tmp[0];
	for (i = 1; i < num; i++)
	{
		InputTree(tree, tmp[i]);
	}
}

void PrintTree(Tree *p)
{
	if (p == NULL)
	{
		return;
	}
	PrintTree(p->left);
	putchar(p->data);
	PrintTree(p->right);
}

void DeleteTreeNode(Tree **t, char k)
{
	int flag = -1;
	Tree *last = *t, *p = *t, *n = NULL;

	while (p != NULL && k != p->data)
	{
		last = p;
		if (k > p->data)
		{
			flag = 0;
			p = p->right;
		}
		else
		{
			flag = 1;
			p = p->left;
		}
	}
	if (p != NULL)
	{
		n = p;
		if (flag > 0)
		{
			if (p->right != NULL)
			{
				last->left = p->right;
				last->left->left = p->left;
			}
			else
			{
				last->left = p->left;
			}
		}
		else if (flag == 0)
		{
			if (p->right != NULL)
			{
				last->right = p->right;
				last->right->left = p->left;
			}
			else
			{
				last->right = p->left;
			}
		}
		else
		{
			if (p->right != NULL)
			{
				p = p->right;
				while (p->left != NULL)
				{
					p = p->left;
				}
				p->left = (*t)->left;
				*t = last->right;
			}
			else
			{
				*t = p->left;
			}
		}
		free(n);
	}
	else
	{
		printf("δ�ҵ�Ҫɾ�����ַ�!\n");
	}
}

void Menu()
{
	putchar('\n');
	printf("1�����������,�����۰����ʵ��ĳһ��֪�Ĺؼ��ֵĲ���(����˳���洢�ṹ)\n");
	printf("2���������һ��ؼ���, ���ö����������Ĳ����㷨��������������\n");
	printf("3�������϶�����������ɾ��ĳһָ���ؼ���Ԫ��\n");
	putchar('\n');
	printf("����������ѡ��:>");
}

int main()
{
	char ch;
	int k, ret, choice = 1;
	List list, *pl = &list;
	Tree *pt = NULL, *t = NULL;
	
	while (choice)
	{
		Menu();
		scanf("%d", &choice);
		getchar();
		switch (choice)
		{
		case 1:
			printf("�Ƿ�Ҫ�����µ������?(y/n)\n");
			scanf("%c", &ch);
			if (ch == 'y' || ch == 'Y')
			{
				InsertCreat(&pl);
			}
			printf("Ҫ���ҵ���:>");
			scanf("%d", &k);
			ret = BSearch(pl, k);
			if (ret != -1)
			{
				printf("�ҵ���!�ڵ�%d��\n", ret + 1);
			}
			else
			{
				printf("û�ҵ�!\n");
			}
			break;
		case 2:
			if (pt != NULL)
			{
				free(pt);
			}
			CandomCreate(&pt);
			if (pt != NULL)
			{
				printf("����������ɵĶ���������:>");
				PrintTree(pt);
				putchar('\n');
			}
			break;
		case 3:
			printf("��������Ҫɾ�����ַ�:>");
			ch = getchar();
			DeleteTreeNode(&pt, ch);
			printf("ɾ���ַ���Ķ���������:>");
			if (pt == NULL)
			{
				printf("������Ϊ��!\n");
			}
			PrintTree(pt);
			putchar('\n');
			break;
		default:
			printf("ERROR!\n");
			break;
		}
	}

	system("pause");
	return 0;
}