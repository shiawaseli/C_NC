#include "Leetcode.h"

/*
 *
 *	237. ɾ�������еĽڵ�
 *
 *  	ִ����ʱ :		16 ms, ������ C++ �ύ�л�����71.68%���û�
 *  	�ڴ����� :		9.2 MB, ������ C++ �ύ�л�����50.13%���û�
 *
 */
void deleteNode(ListNode* node)
{
	*node = *(node->next);
}