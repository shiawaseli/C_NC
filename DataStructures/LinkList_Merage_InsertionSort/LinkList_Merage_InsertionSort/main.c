#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
}List, Node;

void CreateList(List *L, int size)
{
	Node *t = L;

	for (int i = 0; i < size; i++)
	{
		t->next = (Node*)calloc(1, sizeof(Node));
		t = t->next;
		scanf("%d", &(t->data));
	}
	t->next = NULL;
}

void MergeList(List *L1, List *L2, List *L3)
{
	int flag = 1;
	List *pa = L1->next;
	List *pb = L2->next;
	List *t = L3;

	while (pb != NULL)
	{
		t->next = (Node*)calloc(1, sizeof(Node));
		t = t->next;
		if (flag)
		{
			t->data = pa->data;
			pa = pa->next;
			flag = 0;
		}
		else
		{
			t->data = pb->data;
			pb = pb->next;
			flag = 1;
		}
	}
	while (pa != NULL)
	{
		t->next = (Node*)calloc(1, sizeof(Node));
		t = t->next;
		t->data = pa->data;
		pa = pa->next;
	}
	t->next = NULL;
}

void PrintList(List *L)
{
	List *t = L->next;

	while (t != NULL)
	{
		printf("%d", t->data);
		t = t->next;
		if (t != NULL)
		{
			printf(" -> ");
		}
	}
	putchar('\n');
}

void InsertionSort(List *L)
{
	List *t, *k, *tmp, *p = L;

	while (p != NULL)
	{
		t = L;
		k = p->next;
		if (k == NULL)
		{
			break;
		}
		while (t != p && t->next->data < p->next->data)
		{
			t = t->next;
		}
		if (t != p)
		{
			tmp = t->next;
			t->next = p->next;
			p->next = p->next->next;
			t->next->next = tmp;
		}
		if (p->next == k)
		{
			p = p->next;
		}
	}
}

void Test()
{
	int m, n;
	List L1, L2, L3;

	printf("\n(1)������������A��B������Ԫ�ظ����ֱ�Ϊm��n����\n");
	printf("������m��n:>");
	scanf("%d%d", &m, &n);
	printf("������%d������������A:>", m);
	CreateList(&L1, m);
	printf("����A:>");
	PrintList(&L1);
	printf("������%d������������B:>", n);
	CreateList(&L2, n);
	printf("����B:>");
	PrintList(&L2);
	printf("\n(2)�����Ǻϲ���һ�����Ա�C\n");
	if (m >= n)
	{
		MergeList(&L1, &L2, &L3);
	}
	else
	{
		MergeList(&L2, &L1, &L3);
	}
	printf("����C:>");
	PrintList(&L3);
	printf("\n(3)��ֱ�Ӳ������򷨶�C��������������������D\n");
	InsertionSort(&L3);
	printf("����D:>");
	PrintList(&L3);
}

int main()
{
	while (1)
	{
		printf("���Կ�ʼ:");
		Test();
		putchar('\n');
	}

	system("pause");
	return 0;
}

/*


(1)��������1

6 9
30 41 15 12 56 80
23 56 78 23 12 33 79 90 55

(2)��������2

9 5
30 41 15 12 56 80 23 12 34
23 56 78 23 12


*/