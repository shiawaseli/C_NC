#include "Leetcode.h"

/*
 *
 *	83. ɾ�����������е��ظ�Ԫ��
 *
 *  	ִ����ʱ :		12 ms, ������ C++ �ύ�л�����96.17%���û�
 *  	�ڴ����� :		9.1 MB, ������ C++ �ύ�л�����66.01%���û�
 *
 */
ListNode* deleteDuplicates_83(ListNode* head)
{
	ListNode *cur, *tmp;
	for (cur = head; cur; cur = cur->next)
	{
		while (cur->next && cur->val == cur->next->val)
		{
			tmp = cur->next;
			cur->next = tmp->next;
			delete tmp;
		}
	}
	return head;
}