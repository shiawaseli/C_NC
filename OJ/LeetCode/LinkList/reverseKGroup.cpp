#include "Leetcode.h"

/*
 *
 *	25. K ��һ�鷭ת����
 *
 *  	ִ����ʱ:		24 ms, ������ C++ �ύ�л�����95.86%���û�
 *  	�ڴ�����:		9.7 MB, ������ C++ �ύ�л�����86.99%���û�
 *
 */
ListNode* reverseKGroup(ListNode* head, int k)
{
	int i, count = 0;
	ListNode *tmp, *cur = head, newhead(0);
	newhead.next = head;
	while (cur)
	{
		++count;
		cur = cur->next;
	}
	count = (count / k) * (k - 1);
	head = &newhead;
	tmp = head;
	for (i = 0; i < count; i++)
	{
		if (i % (k - 1) == 0)
		{
			head = tmp;
			tmp = tmp->next;
		}
		cur = tmp->next;
		tmp->next = cur->next;
		cur->next = head->next;
		head->next = cur;
	}
	return newhead.next;
}
