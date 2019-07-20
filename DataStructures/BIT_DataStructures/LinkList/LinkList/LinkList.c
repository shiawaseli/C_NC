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

	SListInit(pt);
	SListInit(pt2);

	SListPushFront(pt, 4);
	SListPushFront(pt, 3);
	SListPushFront(pt, 1);
	SListPushFront(pt, 2);
	SListPushFront(pt, 9);
	SListPushFront(pt, 4);
	SListPushFront(pt, 1);

	SListPrint(pt);
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
	SListPrint(pt2);

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