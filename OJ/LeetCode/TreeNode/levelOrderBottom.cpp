#include "Leetcode.h"

/*
 *
 *	107. �������Ĳ�α��� II
 *
 *  	ִ����ʱ:		12 ms, ������ C++ �ύ�л�����66.48%���û�
 *  	�ڴ�����:		13.8 MB, ������ C++ �ύ�л�����73.60%���û�
 *
 */
vector< vector<int> > levelOrderBottom(TreeNode* root)
{
	TreeNode* cur;
	vector<TreeNode*> que;
	vector<int> floor;
	vector< vector<int> > res;
	int left = 0, right = 1, flag = 1;
	que.push_back(root);
	while (left < right)
	{
		cur = que[left++];
		if (cur)
		{
			floor.push_back(cur->val);
			que.push_back(cur->left);
			que.push_back(cur->right);
			right += 2;
		}
		if (left == flag && !floor.empty())
		{
			res.insert(res.begin(), floor);
			floor.clear();
			flag = right;
		}
	}
	return res;
}