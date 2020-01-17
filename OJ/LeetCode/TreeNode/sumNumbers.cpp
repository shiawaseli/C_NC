#include "Leetcode.h"

/*
 *
 *	129. �����Ҷ�ӽڵ�����֮��
 *
 *  	ִ����ʱ:		4 ms, ������ C++ �ύ�л�����85.42%���û�
 *  	�ڴ�����:		12.7 MB, ������ C++ �ύ�л�����16.00%���û�
 *
 */
int sumNumbers(TreeNode* root)
{
	int res = 0;
	queue<TreeNode*> q;
	TreeNode *cur = root;
	if (cur)
		q.push(cur);
	while (!q.empty())
	{
		cur = q.front();
		q.pop();
		if (!cur->left && !cur->right)
			res += cur->val;
		else
		{
			if (cur->left)
			{
				cur->left->val += 10 * cur->val;
				q.push(cur->left);
			}
			if (cur->right)
			{
				cur->right->val += 10 * cur->val;
				q.push(cur->right);
			}
		}
	}
	return res;
}