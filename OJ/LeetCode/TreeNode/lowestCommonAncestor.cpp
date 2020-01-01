#include "Leetcode.h"

/*
 *
 *	235. �����������������������
 *
 *  	ִ����ʱ:		40 ms, ������ C++ �ύ�л�����72.39%���û�
 *  	�ڴ�����:		25.5 MB, ������ C++ �ύ�л�����99.62%���û�
 *
 */
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	TreeNode *cur = root;
	while (cur)
	{
		if (cur->val > p->val && cur->val > q->val)
			cur = cur->left;
		else if (cur->val < p->val && cur->val < q->val)
			cur = cur->right;
		else
			break;
	}
	return cur;
}