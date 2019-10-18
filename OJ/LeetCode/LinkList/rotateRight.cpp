#include "Leetcode.h"

/*
 *
 *	61. ��ת����
 *
 *  	ִ����ʱ:		12 ms, ������ C++ �ύ�л�����81.10%���û�
 *  	�ڴ�����:		8.8 MB, ������ C++ �ύ�л�����93.11%���û�
 *
 */
ListNode* rotateRight(ListNode* head, int k)
{
	int count = 0;
	ListNode *cur = head, *tmp;
	for (cur = head; cur; cur = cur->next)
		++count;
	if (count == 0 || !(k % count))
		return head;
	k = k % count;
	if (k > 1)
		head = rotateRight(head, k - 1);
	for (cur = head; cur && cur->next && cur->next->next; )
		cur = cur->next;
	if (cur && cur->next)
	{
		tmp = cur->next;
		cur->next = NULL;
		tmp->next = head;
		head = tmp;
	}
	return head;
}