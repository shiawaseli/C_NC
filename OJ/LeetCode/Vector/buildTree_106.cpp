#include "Leetcode.h"

/*
 *
 *	106. �����������������й��������
 *
 *  	ִ����ʱ:		72 ms, ������ C++ �ύ�л�����18.58%���û�
 *  	�ڴ�����:		76.9 MB, ������ C++ �ύ�л�����22.81%���û�
 *
 */
TreeNode* buildTree_106(vector<int>& inorder, vector<int>& postorder)
{
	TreeNode *root = nullptr;
	for (int i = postorder.size() - 1; i >= 0; --i)
	{
		for (int j = 0; j < inorder.size(); ++j)
		{
			if (inorder[j] == postorder[i])
			{
				root = new TreeNode(postorder[i]);
				vector<int> newpost(postorder.begin(), postorder.begin() + i);
				vector<int> newin1(inorder.begin(), inorder.begin() + j);
				root->left = buildTree(newin1, newpost);
				vector<int> newin2(inorder.begin() + j + 1, inorder.end());
				root->right = buildTree(newin2, newpost);
				return root;
			}
		}
	}
	return root;
}