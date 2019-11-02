#include "Leetcode.h"

/*
 *
 *	100. ��ͬ����
 *
 *  	ִ����ʱ:		4 ms, ������ C++ �ύ�л�����78.15%���û�
 *  	�ڴ�����:		9.9 MB, ������ C++ �ύ�л�����74.73%���û�
 *
 */
bool isSameTree(TreeNode* p, TreeNode* q)
{
	if (p && q)
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right) && p->val == q->val;
	else if (p || q)
		return false;
	else
		return true;
}