#include "Leetcode.h"

/*
 *
 *	101. �Գƶ�����
 *
 *  	ִ����ʱ:		8 ms, ������ C++ �ύ�л�����71.89%���û�
 *  	�ڴ�����:		14.7 MB, ������ C++ �ύ�л�����89.46%���û�
 *
 */
bool isSymmetric(TreeNode* root)
{
	if (root == NULL)
		return true;
	if (root->left != NULL && root->right != NULL)
	{
		if (root->left->val == root->right->val)
		{
			TreeNode tmp1(0), tmp2(0);
			tmp1.left = root->left->left;
			tmp1.right = root->right->right;
			tmp2.left = root->left->right;
			tmp2.right = root->right->left;
			return isSymmetric(&tmp1) && isSymmetric(&tmp2);
		}
		else
			return false;
	}
	else if (root->left == NULL && root->right == NULL)
		return true;
	else
		return false;
}