#include "Leetcode.h"

/*
 *
 *	114. ������չ��Ϊ����
 *
 *  	ִ����ʱ:		8 ms, ������ C++ �ύ�л�����75.53%���û�
 *  	�ڴ�����:		9.9 MB, ������ C++ �ύ�л�����13.20%���û�
 *
 */
void flatten(TreeNode* root)
{
	TreeNode *cur = root, *tmp;
	if (cur)
	{
		if (cur->left)
			flatten(cur->left);
		if (cur->right)
			flatten(cur->right);
		tmp = cur->left;
		if (tmp)
		{
			while (tmp->right)
				tmp = tmp->right;
			tmp->right = cur->right;
			cur->right = cur->left;
		}
		cur->left = nullptr;
	}
}