#include "Leetcode.h"

/*
 *
 *	94. ���������������
 *
 *  	ִ����ʱ:		0 ms, ������ C++ �ύ�л�����100.00%���û�
 *  	�ڴ�����:		9.1 MB, ������ C++ �ύ�л�����69.40%���û�
 *
 */
vector<int> inorderTraversal(TreeNode* root)
{
	TreeNode* cur = root;
	stack<TreeNode*> st;
	vector<int> res;
	while (cur)
	{
		st.push(cur);
		cur = cur->left;
	}
	while (!st.empty())
	{
		cur = st.top();
		st.pop();
		res.push_back(cur->val);
		if (cur->right)
		{
			cur = cur->right;
			while (cur)
			{
				st.push(cur);
				cur = cur->left;
			}
		}
	}
	return res;
}