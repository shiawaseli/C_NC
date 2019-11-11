#include "Leetcode.h"

/*
 *
 *	86. �ָ�����
 *
 *  	ִ����ʱ:		12 ms, ������ C++ �ύ�л�����54.35%���û�
 *  	�ڴ�����:		8.5 MB, ������ C++ �ύ�л�����92.44%���û�
 *
 */
ListNode* partition(ListNode* head, int x)
{
	if (!head || !head->next)
		return head;
	ListNode *left = nullptr, *right = nullptr, *cur, *tmp;
	for (cur = head; cur; cur = cur->next)
	{
		if (cur->val >= x)
		{
			right = cur;
			break;
		}
		else
			left = cur;
	}
	if (right == head)
	{
		for (cur = head; cur->next; cur = cur->next)
		{
			if (cur->next->val < x)
			{
				left = cur->next;
				cur->next = left->next;
				left->next = head;
				head = left;
				break;
			}
		}
	}
	while (cur && cur->next)
	{
		if (cur->next->val < x)
		{
			tmp = cur->next;
			cur->next = tmp->next;
			tmp->next = left->next;
			left->next = tmp;
			left = tmp;
		}
		else
			cur = cur->next;
	}
	return head;
}