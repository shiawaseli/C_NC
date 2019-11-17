#include "Leetcode.h"

/*
 *
 *	111. ����������С���
 *
 *  	ִ����ʱ:		16 ms, ������ C++ �ύ�л�����74.21%���û�
 *  	�ڴ�����:		19.6 MB, ������ C++ �ύ�л�����77.81%���û�
 *
 */
int minDepth(TreeNode* root)
{
	if (!root)
		return 0;
	int left = minDepth(root->left), right = minDepth(root->right);
	return (left && right) ? min(left, right) + 1 : left + right + 1;
}