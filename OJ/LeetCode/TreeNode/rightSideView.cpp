#include "Leetcode.h"

/*
 *
 *	199. ������������ͼ
 *
 *  	ִ����ʱ:		4 ms, ������ C++ �ύ�л�����87.15%���û�
 *  	�ڴ�����:		10 MB, ������ C++ �ύ�л�����5.63%���û�
 *
 */
vector<int> rightSideView(TreeNode* root)
{
	if (!root)
		return vector<int>();
	int i, size;
	TreeNode *cur;
	vector<int> ret(1, root->val);
	vector<TreeNode*> s1(1, root), s2;
	while (s1.size())
	{
		size = s1.size();
		for (i = 0; i < size; ++i)
		{
			if (s1[i]->left)
				s2.push_back(s1[i]->left);
			if (s1[i]->right)
				s2.push_back(s1[i]->right);
		}
		if (s2.size())
			ret.push_back(s2[s2.size() - 1]->val);
		s1 = s2;
		s2.clear();
	}
	return ret;
}