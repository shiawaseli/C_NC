#include "Leetcode.h"

/*
 *
 *	226. ��ת������
 *
 *  	ִ����ʱ:		4 ms, ������ C++ �ύ�л�����72.72%���û�
 *  	�ڴ�����:		9.1 MB, ������ C++ �ύ�л�����48.29%���û�
 *
 */
TreeNode* invertTree(TreeNode* root)
{
	if (root)
	{
		TreeNode* tmp = root->left;
		root->left = root->right;
		root->right = tmp;
		invertTree(root->left);
		invertTree(root->right);
	}
	return root;
}