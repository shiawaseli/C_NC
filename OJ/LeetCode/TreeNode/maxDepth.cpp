#include "Leetcode.h"

/*
 *
 *	104. ��������������
 *
 *  	ִ����ʱ:		20 ms, ������ C++ �ύ�л�����31.92%���û�
 *  	�ڴ�����:		19 MB, ������ C++ �ύ�л�����94.16%���û�
 *
 */
int maxDepth(TreeNode* root)
{
	if (!root)
		return 0;
	int res1 = maxDepth(root->left), res2 = maxDepth(root->right);
	return res1 > res2 ? res1 + 1 : res2 + 1;
}