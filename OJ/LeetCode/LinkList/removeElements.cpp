#include "Leetcode.h"

/*
 *
 *	203. �Ƴ�����Ԫ��
 *
 *  	ִ����ʱ:		32 ms, ������ C++ �ύ�л�����84.96%���û�
 *  	�ڴ�����:		11.2 MB, ������ C++ �ύ�л�����56.68%���û�
 *
 */
ListNode* removeElements(ListNode* head, int val)
{
	ListNode *cur = head, *tmp;
	while (cur && cur->val == val)
	{
		cur = cur->next;
		delete head;
		head = cur;
	}
	while (cur && cur->next)
	{
		if (cur->next->val == val)
		{
			tmp = cur->next;
			cur->next = tmp->next;
			delete tmp;
		}
		else
			cur = cur->next;
	}
	return head;
}