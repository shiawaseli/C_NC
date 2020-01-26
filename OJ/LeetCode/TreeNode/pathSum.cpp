#include "Leetcode.h"

/*
 *
 *	113. ·���ܺ� II
 *
 *  	ִ����ʱ:		12 ms, ������ C++ �ύ�л�����92.88%���û�
 *  	�ڴ�����:		35.4 MB, ������ C++ �ύ�л�����17.92%���û�
 *
 */
vector< vector<int> > pathSum(TreeNode* root, int sum)
{
	if (!root)
		return vector< vector<int> >();
	if (!root->left && !root->right && sum == root->val)
		return vector< vector<int> >(1, vector<int>(1, root->val));
	vector< vector<int> > ret, tmp;
	tmp = pathSum(root->right, sum - root->val);
	ret.insert(ret.begin(), tmp.begin(), tmp.end());
	tmp = pathSum(root->left, sum - root->val);
	ret.insert(ret.begin(), tmp.begin(), tmp.end());
	for (auto & i : ret)
		i.insert(i.begin(), root->val);
	return ret;
}