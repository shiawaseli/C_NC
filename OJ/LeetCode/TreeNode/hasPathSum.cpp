#include "Leetcode.h"

/*
 *
 *	112. ·���ܺ�
 *
 *  	ִ����ʱ:		24 ms, ������ C++ �ύ�л�����27.34%���û�
 *  	�ڴ�����:		19.7 MB, ������ C++ �ύ�л�����80.69%���û�
 *
 */
bool hasPathSum(TreeNode* root, int sum)
{
	if (!root)
		return false;
	if (!root->left && !root->right && root->val == sum)
		return true;
	return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}