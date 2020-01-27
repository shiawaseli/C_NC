#include "Leetcode.h"

/*
 *
 *	105. ��ǰ��������������й��������
 *
 *  	ִ����ʱ:		60 ms, ������ C++ �ύ�л�����23.81%���û�
 *  	�ڴ�����:		77.4 MB, ������ C++ �ύ�л�����25.72%���û�
 *
 */
TreeNode* buildTree_105(vector<int>& preorder, vector<int>& inorder)
{
	TreeNode *root = nullptr;
	for (int i = 0; i < preorder.size(); ++i)
	{
		for (int j = 0; j < inorder.size(); ++j)
		{
			if (preorder[i] == inorder[j])
			{
				root = new TreeNode(preorder[i]);
				vector<int> newpre(preorder.begin() + i + 1, preorder.end());
				vector<int> newin1(inorder.begin(), inorder.begin() + j);
				root->left = buildTree(newpre, newin1);
				vector<int> newin2(inorder.begin() + j + 1, inorder.end());
				root->right = buildTree(newpre, newin2);
				return root;
			}
		}
	}
	return root;
}