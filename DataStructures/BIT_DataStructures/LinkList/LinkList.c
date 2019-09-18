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
			cur->_next = tmp->_next;
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

	SListNode *tmp, *cur = plist->_head; // һ��һ�����Ĳ��뿪ͷ

	while (cur->_next) // ����Ҫ����Ľ��
	{
		tmp = cur->_next; // �� tmp ָ��Ҫ����Ľ��
		cur->_next = tmp->_next; // ���������Ƴ�Ҫ����Ľ��
		tmp->_next = plist->_head; // ��Ҫ����Ľ��ŵ�����Ŀ�ͷ
		plist->_head = tmp; // ������ָ���׽��
	}

#elif 1

	SListNode *cur = plist->_head;
	SListNode *tmp;

	if (cur)
	{
		tmp = cur->_next; // �� tmp ָ��ʣ��δ����Ľ��
		cur->_next = NULL; // cur ���׽��ȡ��
		while (tmp) // tmp �����µ��׽��
		{
			plist->_head = tmp; // ������ָ���µ��׽��
			tmp = tmp->_next; // �� tmp ָ��ʣ��δ����Ľ��
			plist->_head->_next = cur; // �����׽����ԭ�׽������
			cur = plist->_head; // �� cur ָ�����ڵ��׽��
		}
	}

#else

	SList *newhead = (SList*)malloc(sizeof(SList)); // ����һ���µ�ͷָ��
	SListNode *cur;

	SListInit(newhead); // ��ʼ��������
	
	for (cur = plist->_head; cur; cur = cur->_next)
	{
		SListPushFront(newhead, cur->_data); // ���������������������
	}
	SListDestory(plist); // ���پ�����
	plist->_head = newhead->_head; // ��������ͷָ��ָ����������׽��

	free(newhead); // �ͷ��������ͷָ��

#endif
}
// �ж��������Ƿ��ཻ�������ཻ���
SListNode* GetIntersectionNode(SList* listA, SList* listB)
{
	assert(listA);
	assert(listB);

	int lenA = 0, lenB = 0, i, gap;
	SListNode *cur, *headlong = listA->_head, *headshort = listB->_head; //Ĭ������A�ĳ��ȴ��ڵ�������B�ĳ���

	for (cur = listA->_head; cur; cur = cur->_next) // ������A�ĳ���
	{
		lenA++;
	}
	for (cur = listB->_head; cur; cur = cur->_next) // ������B�ĳ���
	{
		lenB++;
	}
	gap = lenA - lenB; // ������A������B�ĳ��Ȳ�
	if (gap < 0) // headlong ��Զָ��ϳ�������
	{
		gap *= -1;
		headshort = listA->_head;
		headlong = listB->_head;
	}
	for (i = 0; i < gap; i++) // �����������Ȼ���ཻ�Ĳ��֣�ʹ������ĳ�����ͬ
	{
		headlong = headlong->_next;
	}
	for (; headlong; headlong = headlong->_next, headshort = headshort->_next)
	{
		if (headlong == headshort) // ���ȳ������ཻ������
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
		slow = slow->_next; // slow ÿ������ƶ�һ�����
		fast = fast->_next->_next; // fast ÿ������ƶ��������
		if (slow == fast) // �����ָ���ཻ˵������ɻ�
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
	SListNode *slow = plist->_head, *fast = plist->_head;

	while (slow && fast && fast->_next)
	{
		slow = slow->_next;
		fast = fast->_next->_next;
		if (slow == fast) // �ҵ��������
		{
			while (cur != slow) // ������㵽�ཻ���Ľ����������ʼ��㵽�ཻ���Ľ����
			{
				cur = cur->_next;
				slow = slow->_next;
			}
			return cur;
		}
	}

	return NULL;
}

// ɾ������ָ�����ݣ�����ɾ�����ݵĸ���
int RemoveElements(SList* head, int val)
{
	assert(head);

	int count = 0;
	SListNode h, *cur = &h, *tmp;

	cur->_next = head->_head;
	while (head->_head && head->_head->_data == val) // �������ͷָ��ָ���׸���Ϊָ��ֵ�Ľ��
	{
		head->_head = head->_head->_next;
	}
	while (cur)
	{
		if (cur->_next && cur->_next->_data == val) // ����һ���Ϊָ��ֵʱ��������ɾ����һ���
		{
			count++;
			tmp = cur->_next;
			cur->_next = tmp->_next;
			free(tmp);
			continue;
		}
		cur = cur->_next;
	}

	return count;
}
// �����м���(ż�������ʱΪƫ�ҽ��)
SListNode* MiddleNode(SList* head)
{
	assert(head);

	SListNode *cur = head->_head, *next;

	if (!cur) // ��Ϊ����ʱ������ NULL
	{
		return NULL;
	}
	next = cur->_next; // ������Ϊ next = cur; ��ż�������ʱΪƫ����
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
// ������������ϲ�
SListNode* MergeTwoLists(SList* plist1, SList* plist2)
{
	SList head;
	SListNode *l1 = plist1->_head, *l2 = plist2->_head, *cur;

	plist1->_head = plist2->_head = NULL;
	if (l1 && l2 && l1->_data < l2->_data || l1 && !l2) // �����������ڻ�ֻ������1����ʱ��������������1Ϊ�׽��
	{
		head._head = l1;
		l1 = l1->_next;
	}
	else if (l2) // ��ֻ������2����ʱ��������������2Ϊ�׽��
	{
		head._head = l2;
		l2 = l2->_next;
	}
	else // ��������������ʱ��û���׽��
	{
		head._head = NULL;
	}
	cur = head._head;
	while (l1 && l2) // ������������ʱ�Ĳ���
	{
		if (l1->_data < l2->_data)
		{
			cur->_next = l1;
			l1 = l1->_next;
		}
		else
		{
			cur->_next = l2;
			l2 = l2->_next;
		}
		cur = cur->_next;
	}
	if (l1) // ����ᴦ��֮ǰδ����Ľ��
	{
		cur->_next = l1;
	}
	else if (l2)
	{
		cur->_next = l2;
	}

	return head._head;
}
// k ����������ϲ�
SListNode* MergeKLists(SListNode** lists, int k)
{
	SListNode *list1, *list2, *newHead, *cur;

	if (k > 2)
	{
		list1 = MergeKLists(lists, k - 1);
	}
	else if (k == 2)
	{
		list1 = lists[0];
	}
	else if (k == 1)
	{
		return lists[0];
	}
	else
	{
		return NULL;
	}
	list2 = lists[k - 1];
	if (list1 && list2 && list1->_data > list2->_data || list2 && !list1)
	{
		newHead = list2;
		list2 = list2->_next;
	}
	else if (list1 && list2 && list1->_data <= list2->_data || list1 && !list2)
	{
		newHead = list1;
		list1 = list1->_next;
	}
	else
	{
		return NULL;
	}
	cur = newHead;
	while (list1 && list2)
	{
		if (list1->_data < list2->_data)
		{
			cur->_next = list1;
			list1 = list1->_next;
		}
		else
		{
			cur->_next = list2;
			list2 = list2->_next;
		}
		cur = cur->_next;
	}
	if (list1)
	{
		cur->_next = list1;
	}
	else
	{
		cur->_next = list2;
	}

	return newHead;
}
// ������
SListNode* SListClone(SList* plist)
{
	assert(plist);

	SListNode *aim = plist->_head, head, *cur = (SListNode*)malloc(sizeof(SListNode));

	head._next = cur;
	cur->_data = aim->_data;
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
// �Ը���ֵ val Ϊ��׼����ԭ��������˳������ָ��������
SListNode* SListPartition(SList* plist, int val)
{
	assert(plist);

	SListNode head1, head2; // ��ͷ���
	SListNode *cur = plist->_head, *before= &head1, *after = &head2;

	while (cur)
	{
		if (cur->_data < val) // С�ڻ�׼ֵ�Ĳ���
		{
			before->_next = cur;
			before = before->_next;
		}
		else // ���ڻ�׼ֵ�Ĳ���
		{
			after->_next = cur;
			after = after->_next;
		}
		cur = cur->_next;
	}
	before->_next = head2._next; // ���������ֹ���һ������
	after->_next = NULL;

	return head1._next;
}
// ����������ɾ���ظ����
SListNode* DeleteDuplication(SList* plist)
{
	assert(plist);

	SListNode *cur = plist->_head, *tmp;

	while (cur && cur->_next)
	{
		if (cur->_data == cur->_next->_data)
		{
			tmp = cur->_next;
			cur->_next = tmp->_next;
			free(tmp);
			continue;
		}
		cur = cur->_next;
	}

	return plist->_head;
}
// ���������ж�
int CheckPalindrome(SList* plist)
{
	assert(plist);

	int flag = 1;
	SList head;
	SListNode *cur = plist->_head, *other;

	head._head = SListClone(plist); // ���Ƴ�һ��������
	SListReverse(&head); // ������������
	other = head._head;
	while (cur)
	{
		if (cur->_data != other->_data) // �������������ԭ����ͬʱ��ԭ�����ǻ�������
		{
			flag = 0;
			break;
		}
		cur = cur->_next;
		other = other->_next;
	}
	SListDestory(&head); // ��������������
	
	return flag;
}
// ������ӣ� �������ݰ������ֵ�ÿһλ�ĵ������洢
SListNode* AddTwoNumbers(SList* plist1, SList* plist2) 
{
	assert(plist1);
	assert(plist2);

	int flag = 0; // flag Ϊ��λ
	SListNode head, *l1 = plist1->_head, *l2 = plist2->_head, *l3 = &head;

	while (l1 || l2 || flag) // ��������һλʱ����ѭ��
	{
		l3->_next = (SListNode*)malloc(sizeof(SListNode));
		l3 = l3->_next;
		l3->_data = flag;
		flag = 0;
		if (l1)
		{
			l3->_data += l1->_data;
			l1 = l1->_next;
		}
		if (l2)
		{
			l3->_data += l2->_data;
			l2 = l2->_next;
		}
		if (l3->_data > 9)
		{
			flag = 1;
			l3->_data -= 10;
		}
	}
	l3->_next = NULL;

	return head._next;
}
// ��������Ϊһ�������������
SListNode* SListSwapPairs(SListNode* head)
{
	SListNode *newHead = head, *cur = NULL, *tmp = head;

	if (head && head->_next)
	{
		cur = head->_next;
		newHead = cur;
	}
	while (cur)
	{
		tmp->_next = cur->_next;
		cur->_next = tmp;
		cur = tmp->_next;
		if (cur && cur->_next)
		{
			tmp->_next = cur->_next;
			tmp = cur;
			cur = cur->_next;
		}
		else if (cur)
		{
			cur = cur->_next;
		}
	}

	return newHead;
}

// ��ӡ����
void SListPrint(SList* plist)
{
	assert(plist);

	SListNode *cur;

	for (cur = plist->_head; cur; cur = cur->_next)
	{
		printf("%2d -> ", cur->_data);
	}
	printf("NULL\n");
}


void TestSList()
{
	SList test1, *pt1 = &test1;
	SList test2, *pt2 = &test2;
	SList test3, *pt3 = &test3;
	SListNode ha[5];
	SListNode **list = (SListNode **)&ha;

	SListInit(pt1);
	SListInit(pt2);
	SListInit(pt3);

	SListPushFront(pt1, 35);
	SListPushFront(pt1, 34);
	SListPushFront(pt1, 23);
	SListPushFront(pt1, 12);
	SListPushFront(pt1, 1);

	SListPushFront(pt2, 39);
	SListPushFront(pt2, 28);
	SListPushFront(pt2, 24);
	SListPushFront(pt2, 18);
	SListPushFront(pt2, 13);

	SListPushFront(pt3, 29);
	SListPushFront(pt3, 24);
	SListPushFront(pt3, 13);
	SListPushFront(pt3, 7);
	SListPushFront(pt3, 3);

	list[0] = pt1->_head;
	list[1] = pt2->_head;
	list[2] = pt3->_head;
	SListPrint(pt1);
	SListPrint(pt2);
	SListPrint(pt3);
	pt1->_head = MergeKLists(list, 3);
	SListPrint(pt1);
	pt1->_head = SListSwapPairs(pt1->_head);
	SListPrint(pt1);

	SListDestory(pt1);
}



// ���Ժ���
void TestSList_1()
{
	int ret, val = 9;
	SList test, *pt = &test;
	SList test2, *pt2 = &test2;
	SList test3, *pt3 = &test3;
	SList test4, *pt4 = &test4;
	SList test5, *pt5 = &test5;
	SListNode *tmp1, *tmp2;

	SListInit(pt);
	SListInit(pt2);
	SListInit(pt3);
	SListInit(pt4);
	SListInit(pt5);

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
	pt4->_head = SListClone(pt2);
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

	DeleteDuplication(pt3);
	printf("pt3 :> ");
	SListPrint(pt3);

	printf("pt4 :> ");
	SListPrint(pt4);
	pt4->_head = SListPartition(pt4, 3);
	printf("pt4 :> ");
	SListPrint(pt4);

	SListPushFront(pt2, 9);
	SListPushFront(pt2, 3);
	SListPushFront(pt2, 1);
	SListPushFront(pt2, 2);
	SListPushFront(pt2, 1);
	SListPushFront(pt2, 3);
	SListPushFront(pt2, 9);
	printf("pt2 :> ");
	SListPrint(pt2);
	if (CheckPalindrome(pt2))
	{
		printf("True\n");
	}
	else
	{
		printf("False\n");
	}

	if (MiddleNode(pt))
	{
		printf("MiddleNode(pt) = %d\n", MiddleNode(pt)->_data);
	}

	printf("pt1 :> ");
	SListPrint(pt);
	ret = RemoveElements(pt, 9);
	printf("RemoveElements(pt, %d) = %d\n", 9, ret);
	SListPrint(pt);
	if (MiddleNode(pt))
	{
		printf("MiddleNode(pt) = %d\n", MiddleNode(pt)->_data);
	}

	printf("pt1 :> ");
	SListPrint(pt);
	printf("pt2 :> ");
	SListPrint(pt2);
	printf("pt3 :> ");
	SListPrint(pt3);
	printf("pt4 :> ");
	SListPrint(pt4);

	pt5->_head = AddTwoNumbers(pt, pt2);
	printf("pt5 :> ");
	SListPrint(pt5);

	SListPopFront(pt);
	printf("pt1 :> ");
	SListPrint(pt);
	SListPopFront(pt);
	printf("pt1 :> ");
	SListPrint(pt);

	SListReverse(pt);
	printf("pt1 :> ");
	SListPrint(pt);

	SListInsertAfter(SListFind(pt, 3), 0);
	printf("pt1 :> ");
	SListPrint(pt);

	SListInsertFront(pt, SListFind(pt, 3), 0);
	printf("pt1 :> ");
	SListPrint(pt);

	SListEraseAfter(SListFind(pt, 3));
	printf("pt1 :> ");
	SListPrint(pt);

	SListRemove(pt, 0);
	printf("pt1 :> ");
	SListPrint(pt);

	tmp1 = SListFind(pt5, 3);
	//tmp1 = pt5->_head;
	tmp2 = SListFind(pt5, 9);
	tmp2->_next = tmp1;
	if (SListHasCycle(pt5) > 0)
	{
		printf("yes\n");
		printf("%d\n", (SListDetectCycle(pt5))->_data);
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
	SListDestory(pt3);
	SListDestory(pt4);
	//SListDestory(pt5);
}