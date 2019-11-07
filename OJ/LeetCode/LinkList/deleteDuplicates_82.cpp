#include "Leetcode.h"

/*
 *
 *	82. ɾ�����������е��ظ�Ԫ�� II
 *
 *  	ִ����ʱ :		12 ms, ������ C++ �ύ�л�����77.47%���û�
 *  	�ڴ����� :		9.3 MB, ������ C++ �ύ�л�����7.32%���û�
 *
 */
ListNode* deleteDuplicates_82(ListNode* head)
{
	int flag;
	ListNode *cur = head, *tmp, tmphead(0);
	tmphead.next = head;

	cur = &tmphead;
	while (cur->next && cur->next->next)
	{
		flag = 0;
		while (cur->next && cur->next->next && cur->next->val == cur->next->next->val)
		{
			flag = 1;
			tmp = cur->next->next;
			cur->next->next = tmp->next;
			delete tmp;
		}
		if (flag)
		{
			tmp = cur->next;
			cur->next = tmp->next;
			delete tmp;
		}
		else
			cur = cur->next;
	}
	return tmphead.next;
}