#include "Leetcode.h"

/*
 *
 *	102. �������Ĳ�α���
 *
 *  	ִ����ʱ:		8 ms, ������ C++ �ύ�л�����73.60%���û�
 *  	�ڴ�����:		14.7 MB, ������ C++ �ύ�л�����18.20%���û�
 *
 */
vector< vector<int> > levelOrder(TreeNode* root)
{
	vector<int> tmp;
	TreeNode *cur = root;
	queue<TreeNode*> q, qtmp, qclear;
	vector< vector<int> > res;
	if (root)
		q.push(root);
	while (!q.empty())
	{
		cur = q.front();
		q.pop();
		if (cur)
		{
			tmp.push_back(cur->val);
			if (cur->left)
				qtmp.push(cur->left);
			if (cur->right)
				qtmp.push(cur->right);
		}
		if (q.empty())
		{
			res.push_back(tmp);
			q = qtmp;
			qtmp = qclear;
			tmp.clear();
		}
	}
	return res;
}