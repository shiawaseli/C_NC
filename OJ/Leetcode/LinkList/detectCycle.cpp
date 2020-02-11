#include "Leetcode.h"

/*
 *
 *	142. �������� II
 *
 *  	ִ����ʱ:		8 ms, ������ C++ �ύ�л�����97.50%���û�
 *  	�ڴ�����:		10.1 MB, ������ C++ �ύ�л�����23.56%���û�
 *
 */
ListNode *detectCycle(ListNode *head)
{
	if (head && head->next)
	{
		ListNode *cur = head->next, *cur2 = head->next->next;
		while (cur && cur2)
		{
			if (cur == cur2)
			{
				for (cur2 = head; cur != cur2; cur2 = cur2->next)
					cur = cur->next;
				return cur;
			}
			cur = cur->next;
			if (!cur2->next || cur2->next && !cur2->next->next)
				break;
			cur2 = cur2->next->next;
		}
	}
	return nullptr;
}