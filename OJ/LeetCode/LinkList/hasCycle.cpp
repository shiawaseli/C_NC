#include "Leetcode.h"

/*
 *
 *	141. ��������
 *
 *  	ִ����ʱ :		8 ms, ������ C++ �ύ�л�����98.37%���û�
 *  	�ڴ����� :		9.7 MB, ������ C++ �ύ�л�����61.40%���û�
 *
 */
bool hasCycle(ListNode *head)
{
	ListNode *cur = head;
	ListNode *next = head;
	while (next)
	{
		cur = cur->next;
		next = next->next;
		if (next)
			next = next->next;
		if (cur == next && next != NULL)
			return true;
	}
	return false;
}