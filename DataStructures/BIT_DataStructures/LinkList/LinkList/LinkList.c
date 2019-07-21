#include"LinkList.h"
// �����ʼ��
void SListInit(SList* plist)
{
	assert(plist);

	plist->_head = NULL;
}
// ��������
void SListDestory(SList* plist)
{
	assert(plist);

	SListNode *tmp;

	while (plist->_head)
	{
		tmp = plist->_head;
		plist->_head = plist->_head->_next;
		free(tmp);
	}
	plist->_head = NULL;
}

// �����ݷ���һ�����
SListNode* BuySListNode(SLTDataType val)
{
	SListNode *cur = (SListNode*)malloc(sizeof(SListNode));

	assert(cur);

	cur->_data = val;
	cur->_next = NULL;

	return cur;
}
// ͷ�巨��������
void SListPushFront(SList* plist, SLTDataType val)
{
	assert(plist);

	SListNode *cur = (SListNode*)malloc(sizeof(SListNode));

	assert(cur);

	cur->_data = val;
	cur->_next = plist->_head;
	plist->_head = cur;
}
// ͷɾ��ɾ������
void SListPopFront(SList* plist)
{
	assert(plist);

	SListNode *tmp = plist->_head;

	if (plist->_head)
	{
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}
// �������в�������
SListNode* SListFind(SList* plist, SLTDataType val)
{
	assert(plist);

	SListNode *cur;

	for (cur = plist->_head; cur; cur = cur->_next)
	{
		if (cur->_data == val)
		{
			return cur;
		}
	}

	return NULL;
}
// ��pos�ĺ�����в��� 
void SListInsertAfter(SListNode* pos, SLTDataType val)
{
	assert(pos);

	SListNode *tmp = (SListNode*)malloc(sizeof(SListNode));

	assert(tmp);

	tmp->_data = val;
	tmp->_next = pos->_next;
	pos->_next = tmp;
}
// ��pos��ǰ����в��� 
void SListInsertFront(SList* plist, SListNode* pos, SLTDataType val)
{
	assert(plist);

	SListNode *tmp = (SListNode*)malloc(sizeof(SListNode));
	SListNode *cur;

	assert(tmp);

	tmp->_data = val;
	if (plist->_head == pos)
	{
		tmp->_next = plist->_head;
		plist->_head = tmp;
		return;
	}
	for (cur = plist->_head; cur->_next; cur = cur->_next)
	{
		if (cur->_next == pos)
		{
			tmp->_next = cur->_next;
			cur->_next = tmp;
			return;
		}
	}
}
// ɾ��pos��һ��λ�õ�����
void SListEraseAfter(SListNode* pos)
{
	assert(pos);

	SListNode *tmp = pos->_next;

	if (pos->_next)
	{
		pos->_next = pos->_next->_next;
		free(tmp);
	}
}
// ɾ�����ȳ��ֵ�ָ������
void SListRemove(SList* plist, SLTDataType val)
{
	assert(plist);

	SListNode *cur, *tmp;

	for (cur = plist->_head; cur->_next; cur = cur->_next)
	{
		if (cur->_next->_data == val)
		{
			tmp = cur->_next;
			cur->_next = cur->_next->_next;
			free(tmp);
			return;
		}
	}
}
// ����ת
void SListReverse(SList* plist)
{
	assert(plist);

#if 0

	SListNode *tmp, *cur = plist->_head;

	while (cur->_next)
	{
		tmp = cur->_next;
		cur->_next = tmp->_next;
		tmp->_next = plist->_head;
		plist->_head = tmp;
	}

#elif 1

	SListNode *cur = plist->_head;
	SListNode *tmp;

	if (cur)
	{
		tmp = cur->_next;
		cur->_next = NULL;
		while (tmp)
		{
			plist->_head = tmp;
			tmp = tmp->_next;
			plist->_head->_next = cur;
			cur = plist->_head;
		}
	}

#else

	SList *newhead = (SList*)malloc(sizeof(SList));
	SListNode *cur;

	SListInit(newhead);
	
	for (cur = plist->_head; cur; cur = cur->_next)
	{
		SListPushFront(newhead, cur->_data);
	}
	SListDestory(plist);
	plist->_head = newhead->_head;

	free(newhead);

#endif
}
// �ж��������Ƿ��ཻ
SListNode* GetIntersectionNode(SList* listA, SList* listB)
{
	assert(listA);
	assert(listB);

	int lenA = 0, lenB = 0, i, gap;
	SListNode *cur, *headlong = listA->_head, *headshort = listB->_head;

	for (cur = listA->_head; cur; cur = cur->_next)
	{
		lenA++;
	}
	for (cur = listB->_head; cur; cur = cur->_next)
	{
		lenB++;
	}
	gap = lenA - lenB;
	if (gap < 0)
	{
		gap *= -1;
		headshort = listA->_head;
		headlong = listB->_head;
	}
	for (i = 0; i < gap; i++)
	{
		headlong = headlong->_next;
	}
	for (; headlong; headlong = headlong->_next, headshort = headshort->_next)
	{
		if (headlong == headshort)
		{
			return headlong;
		}
	}

	return NULL;
}
// �ж������Ƿ�ɻ�
int SListHasCycle(SList* plist)
{
	assert(plist);

	SListNode *slow = plist->_head, *fast = plist->_head->_next;

	while (slow && fast && fast->_next)
	{
		slow = slow->_next;
		fast = fast->_next->_next;
		if (slow == fast)
		{
			return 1;
		}
	}

	return -1;
}
// �ҵ��뻷���
SListNode* SListDetectCycle(SList* plist)
{
	assert(plist);

	SListNode *cur = plist->_head;
	SListNode *slow = plist->_head, *fast = plist->_head->_next;

	while (slow && fast && fast->_next)
	{
		slow = slow->_next;
		fast = fast->_next->_next;
		if (slow == fast)
		{
			slow = slow->_next;
			while (cur != slow)
			{
				cur = cur->_next;
				slow = slow->_next;
			}
			return cur;
		}
	}

	return NULL;
}

// ɾ������ָ��Ԫ��
int RemoveElements(SList* head, int val)
{
	assert(head);

	int count = 0;
	SListNode *cur, *tmp;

	while (head->_head && head->_head->_data == val)
	{
		count++;
		tmp = head->_head;
		head->_head = tmp->_next;
		free(tmp);
	}
	cur = head->_head;
	while (cur)
	{
		if (cur->_next && cur->_next->_data == val)
		{
			count++;
			tmp = cur->_next;
			cur->_next = tmp->_next;
			free(tmp);
		}
		cur = cur->_next;
	}

	return count;
}
// �����м���
SListNode* MiddleNode(SList* head)
{
	assert(head);

	SListNode *cur = head->_head, *next;

	if (!cur)
	{
		return NULL;
	}
	next = cur->_next;
	while (next)
	{
		next = next->_next;
		if (next)
		{
			next = next->_next;
		}
		cur = cur->_next;
	}

	return cur;
}
// ��������
void SListQuickSort(SListNode *head)
{
	SListNode *cur, *last, *mid;
	SLTDataType key;

	if (head && head->_next) // ����������������ʱ����
	{
		cur = head->_next;
		mid = cur; // mid �� key ֵ�Ľ��
		key = cur->_data;
		if (head->_data > cur->_data) // ȷ��������С�ڴ����ݣ���ʼ���Դ�����Ϊ key 
		{
			key = head->_data;
			head->_data = cur->_data;
			cur->_data = key;
		}
		while (cur->_next)
		{
			last = cur;
			cur = cur->_next;
			if (cur->_data < key) // ���� key С�����ݶ��ŵ� mid ����ǰ��
			{
				last->_next = cur->_next;
				cur->_next = head->_next;
				head->_next = cur;
				cur = last;
			}
		}
		SListQuickSort(mid->_next);
		if (head->_next != mid) // ��ǰ�벿��ֻ��һ������ʱ��ǰ�벿�ֲ����п���
		{
			SListQuickSort(head);
		}
	}
}
// ��������ϲ�
SListNode* MergeTwoLists(SList* plist1, SList* plist2)
{
	SList head;
	SListNode *cur, *node1, *node2;

	if (!plist1 || !plist1->_head)
	{
		return plist2->_head;
	}
	else if (!plist2 || !plist2->_head)
	{
		return plist1->_head;
	}
	node1 = plist1->_head;
	node2 = plist2->_head;
	plist1->_head = NULL;
	plist2->_head = NULL;

	if (node1->_data < node2->_data)
	{
		head._head = node1;
		node1 = node1->_next;
	}
	else
	{
		head._head = node2;
		node2 = node2->_next;
	}
	cur = head._head;
	while (node1 && node2)
	{
		if (node1->_data < node2->_data)
		{
			cur->_next = node1;
			node1 = node1->_next;
		}
		else
		{
			cur->_next = node2;
			node2 = node2->_next;
		}
		cur = cur->_next;
	}
	if (node1)
	{
		cur->_next = node1;
	}
	else
	{
		cur->_next = node2;
	}

	return head._head;
}
// ������
SListNode* SListClone(SList* plist)
{
	assert(plist);

	SListNode *aim = plist->_head, head, *cur = (SListNode*)malloc(sizeof(SListNode));

	head._next = cur;
	cur->_data = aim->_data;
	aim = aim->_next;
	while (aim->_next)
	{
		cur->_next = (SListNode*)malloc(sizeof(SListNode));
		cur = cur->_next;
		aim = aim->_next;
		cur->_data = aim->_data;
	}
	cur->_next = NULL;

	return head._next;
}

// ��ӡ����
void SListPrint(SList* plist)
{
	assert(plist);

	SListNode *cur;

	for (cur = plist->_head; cur; cur = cur->_next)
	{
		printf("%d->", cur->_data);
	}
	printf("NULL\n");
}
// ���Ժ���
void TestSList()
{
	int ret, val = 9;
	SList test, *pt = &test;
	SList test2, *pt2 = &test2;
	SList test3, *pt3 = &test3;

	SListInit(pt);
	SListInit(pt2);
	SListInit(pt3);

	SListPushFront(pt, 4);
	SListPushFront(pt, 3);
	SListPushFront(pt, 1);
	SListPushFront(pt, 2);
	SListPushFront(pt, 9);
	SListPushFront(pt, 4);
	SListPushFront(pt, 1);

	SListPrint(pt);
	pt2->_head = SListClone(pt);
	SListPushFront(pt2, -2);
	SListPushFront(pt2, 6);
	SListQuickSort(pt2->_head);
	SListQuickSort(pt->_head);
	printf("pt1 :> ");
	SListPrint(pt);
	printf("pt2 :> ");
	SListPrint(pt2);

	pt3->_head = SListClone(pt);
	pt3->_head = MergeTwoLists(pt2, pt3);
	printf("pt3 :> ");
	SListPrint(pt3);

	if (MiddleNode(pt))
	{
		printf("MiddleNode(pt) = %d\n", MiddleNode(pt)->_data);
	}

	ret = RemoveElements(pt, val);
	printf("RemoveElements(pt, %d) = %d\n", val, ret);
	SListPrint(pt);
	if (MiddleNode(pt))
	{
		printf("MiddleNode(pt) = %d\n", MiddleNode(pt)->_data);
	}

	SListPopFront(pt);
	SListPrint(pt);
	SListPopFront(pt);
	SListPrint(pt);

	SListReverse(pt);
	SListPrint(pt);

	SListInsertAfter(SListFind(pt, 3), 0);
	SListPrint(pt);

	SListInsertFront(pt, SListFind(pt, 3), 0);
	SListPrint(pt);

	SListEraseAfter(SListFind(pt, 3));
	SListPrint(pt);

	SListRemove(pt, 0);
	SListPrint(pt);

	//tmp1 = SListFind(pt, 3);
	//tmp1 = pt->_head;
	//tmp2 = SListFind(pt, 9);
	//tmp2->_next = tmp1;
	if (SListHasCycle(pt) > 0)
	{
		printf("yes\n");
		printf("%d\n", (SListDetectCycle(pt))->_data);
	}
	else
		printf("no\n");

	SListReverse(pt);
	//SListPrint(pt);
	//SListPrint(pt2);

	//if (GetIntersectionNode(pt, pt2))
	//{
	//	SListPrint(GetIntersectionNode(pt, pt2));
	//}
	//else
	//{
	//	printf("δ�ཻ!\n");
	//}


	SListDestory(pt);
	SListDestory(pt2);
}