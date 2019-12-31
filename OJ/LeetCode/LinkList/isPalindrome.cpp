#include "Leetcode.h"

/*
 *
 *	234. ��������
 *
 *  	ִ����ʱ :		24 ms, ������ C++ �ύ�л�����69.62%���û�
 *  	�ڴ����� :		13.2 MB, ������ C++ �ύ�л�����24.59%���û�
 *
 */
bool isPalindrome(ListNode* head)
{
	int tmp;
	stack<int> s;
	ListNode* cur;
	for (cur = head; cur; cur = cur->next)
		s.push(cur->val);
	for (cur = head; cur; cur = cur->next)
	{
		tmp = s.top();
		s.pop();
		if (tmp != cur->val)
			return false;
	}
	return true;
}