#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

#define	ERROR 0
#define TRUE 1
#define END -999
#define ElemType int

typedef struct NODE
{
	ElemType data;
	struct NODE *next;
} *LinkList, Node;

int InitList(LinkList *L)
{
	(*L) = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;

	return TRUE;
}

int PrintList(LinkList L)
{
	Node *current;
	current = L;
	if (L == NULL)
	{
		printf("��δ��ʼ��\n");
		return ERROR;
	}
	else if (L->next == NULL)
	{
		printf("��Ϊ�ձ�\n");
		return ERROR;
	}
	while (current->next != NULL)
	{
		current = current->next;
		printf("%4d ", current->data);
		if (current->next != NULL)
		{
			printf("-->");
		}
	}
	if (L->next != NULL)
	{
		putchar('\n');
	}

	return TRUE;
}

int DeleteList(LinkList L)
{
	Node *tmp;

	if (L == NULL)
	{
		printf("��δ��ʼ��\n");
		return ERROR;
	}
	while (L->next != NULL)
	{
		tmp = L->next;
		L->next = tmp->next;
		free(tmp);
	}
	printf("������Ϊ�ձ�\n");
	return TRUE;
}

//ͷ�巨����
int CreateListFromHead(LinkList L)
{
	Node *node;
	ElemType element;

	if (L == NULL)
	{
		printf("��δ��ʼ��\n");
		return ERROR;
	}
	while (1)
	{
		scanf("%d", &element);
		if (element == END)
		{
			break;
		}
		node = (Node *)malloc(sizeof(Node));
		node->data = element;
		node->next = L->next;
		L->next = node;
	}

	return TRUE;
}

int SizeOfList(LinkList L)
{
	int num = 0;
	Node *node;

	if (L == NULL)
	{
		printf("��δ��ʼ��\n");
		return ERROR;
	}
	node = L;
	while (node->next != NULL)
	{
		num++;
		node = node->next;
	}

	return num;
}

int ReverseList(LinkList *L)
{
	Node *tmp, *head;
	LinkList pl;

	if (*L == NULL)
	{
		printf("��δ��ʼ��\n");
		return ERROR;
	}
	InitList(&pl);
	head = (*L);
	while ( head->next != NULL)
	{
		tmp = head->next;
		head->next = tmp->next;
		tmp->next = pl->next;
		pl->next = tmp;
	}
	(*L)->next = pl->next;
	free(pl);

	return TRUE;
}

int InsNoDecreasing(LinkList L, ElemType element)
{
	Node *node, *tmp;

	if (L == NULL)
	{
		printf("��δ��ʼ��\n");
		return ERROR;
	}
	node = L;
	while (node->next != NULL && (node->next)->data < element)
	{
		node = node->next;
	}
	tmp = (Node *)malloc(sizeof(Node));
	tmp->data = element;
	tmp->next = node->next;
	node->next = tmp;

	return TRUE;
}

int ChangeToNoDecreasingList(LinkList L)
{
	Node *pre, *cur = NULL;
	ElemType tmp;

	if (L == NULL)
	{
		printf("��δ��ʼ��\n");
		return ERROR;
	}
	for (pre = L->next; pre->next != NULL; pre = pre->next)
	{
		for (cur = pre->next; cur != NULL; cur = cur->next)
		{
			if (cur->data < pre->data)
			{
				tmp = cur->data;
				cur->data = pre->data;
				pre->data = tmp;
			}
		}
	}

	return TRUE;
}

int DeleteFromNoDecreasingList(LinkList L, ElemType element)
{
	Node *node, *tmp;

	if (L == NULL)
	{
		printf("��δ��ʼ��\n");
		return ERROR;
	}
	node = L->next;
	tmp = L;
	while (node != NULL && node->data != element)
	{
		tmp = node;
		node = node->next;
	}
	if (node == NULL)
	{
		printf("%d�������ڱ���\n", element);
		return ERROR;
	}
	while (node != NULL && node->data == element)
	{
		tmp->next = node->next;
		free(node);
		node = tmp->next;
	}

	return TRUE;
}

int NoDecreasingList(LinkList L)
{
	ElemType element;

	if (L == NULL)
	{
		printf("��δ��ʼ��\n");
		return ERROR;
	}
	while (1)
	{
		scanf("%d", &element);
		if (element == END)
		{
			break;
		}
		InsNoDecreasing(L, element);
	}

	return TRUE;
}

int MergeList(LinkList La, LinkList Lb)
{
	Node *pa, *pb, *current;

	if (La == NULL || Lb == NULL)
	{
		printf("���ڱ�δ��ʼ��\n");
		return ERROR;
	}
	pa = La->next;
	pb = Lb->next;
	current = La;
	while (pa != NULL && pb != NULL)
	{
		if (pa->data < pb->data)
		{
			current->next = pa;
			current = current->next;
			pa = pa->next;
		}
		else
		{
			current->next = pb;
			current = current->next;
			pb = pb->next;
		}
	}
	if (pa == NULL)
	{
		current->next = pb;
	}
	else
	{
		current->next = pa;
	}
	Lb->next = NULL;

	return TRUE;
}

void Menu()
{
	printf("\n\n\n");
	printf("***************************************************************************************************\n");
	printf("*******              1����������һ��Ԫ�أ�����һ����ͷ���ĵ���������                  *******\n");
	printf("*******              2������������                                                          *******\n");
	printf("*******              3���ѵ���������Ԫ������                                                *******\n");
	printf("*******              4������һ���ǵݼ���������                                            *******\n");
	printf("*******              5�����������ǵݼ���������Ȼ��ϲ���һ���ǵݼ������������ÿգ�      *******\n");
	printf("*******              6���ڷǵݼ����������в���һ��Ԫ��ʹ������Ȼ����                      *******\n");
	printf("*******              7���ڷǵݼ�����������ɾ��ֵΪx�Ľ��                                   *******\n");
	printf("*******              8��ɾ����ǰ����                                                        *******\n");
	printf("*******              9�������ǰ�����е�Ԫ�ظ���                                            *******\n");
	printf("*******             10������ǰ��������Ϊ�ǵݼ���������                                        *******\n");
	printf("***************************************************************************************************\n");
	printf("\n\n\n");
}

int main()
{
	int choice = -1;
	ElemType elem;
	LinkList L = NULL;
	LinkList La = NULL, Lb = NULL;

	InitList(&L);
	InitList(&La);
	InitList(&Lb);

	printf("�ڿ�ʼ����ǰ���ȴ���һ����ʼ��:>");
	CreateListFromHead(L);
	printf("��ǰ����Ԫ���У�");
	PrintList(L);

	while (choice)
	{
		Menu();
		printf("��������Ҫ���ԵĹ���:>");
		if (!scanf("%d", &choice))
		{
			choice = -1;
			getchar();
		}
		switch (choice)
		{
		case 1:
			DeleteList(L);
			CreateListFromHead(L);
			printf("��ǰ������Ԫ��Ϊ��");
			PrintList(L);
			break;
		case 2:
			PrintList(L);
			break;
		case 3:
			printf("����ǰ������Ԫ��Ϊ��");
			PrintList(L);
			ReverseList(&L);
			printf("���ú�������Ԫ��Ϊ��");
			PrintList(L);
			break;
		case 4:
			DeleteList(L);
			NoDecreasingList(L);
			printf("��ǰ������Ԫ��Ϊ��");
			PrintList(L);
			break;
		case 5:
			printf("�������һ���ǵݼ����������Ԫ�أ�");
			NoDecreasingList(La);
			printf("��һ���ǵݼ����������Ԫ��Ϊ��");
			PrintList(La);
			printf("������ڶ����ǵݼ����������Ԫ�أ�");
			NoDecreasingList(Lb);
			printf("�ڶ����ǵݼ����������Ԫ��Ϊ��");
			PrintList(Lb);
			MergeList(La, Lb);
			printf("�ϲ��ɵķǵݼ������Ԫ��Ϊ��");
			PrintList(La);
			DeleteList(La);
			break;
		case 6:
			ChangeToNoDecreasingList(L);
			printf("�ǵݼ�����������Ԫ��Ϊ��");
			PrintList(L);
			printf("��������Ҫ�����ֵ:>\n");
			scanf("%d", &elem);
			InsNoDecreasing(L, elem);
			printf("����Ԫ�غ�ı�Ϊ��");
			PrintList(L);
			break;
		case 7:
			ChangeToNoDecreasingList(L);
			printf("�ǵݼ�����������Ԫ��Ϊ��");
			PrintList(L);
			printf("��������Ҫɾ����ֵ:>\n");
			scanf("%d", &elem);
			DeleteFromNoDecreasingList(L, elem);
			printf("ɾ��Ԫ�غ�ı�Ϊ��");
			PrintList(L);
			break;
		case 8:
			DeleteList(L);
			break;
		case 9:
			printf("%d\n", SizeOfList(L));
			break;
		case 10:
			printf("����ǰ������Ԫ��Ϊ��");
			PrintList(L);
			ChangeToNoDecreasingList(L);
			printf("�����������Ԫ��Ϊ��");
			PrintList(L);
			break;
		case 88:
			printf("����L��Ԫ��Ϊ��");
			PrintList(L);
			break;
		case 99:
			system("cls");
			break;
		default:
			system("cls");
			printf("������������\n");
			break;
		}
	}
	
	system("pause");
	return 0;
}
