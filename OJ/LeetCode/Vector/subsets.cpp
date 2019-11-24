#include "Leetcode.h"

/*
 *
 *	78. �Ӽ�
 *
 *  	ִ����ʱ:		12 ms, ������ C++ �ύ�л�����52.56%���û�
 *  	�ڴ�����:		9 MB, ������ C++ �ύ�л�����81.20%���û�
 *
 */
void subfunc(vector<int>& nums, vector<int>& ans, int pos, vector< vector<int> >& ret)
{
	if (pos == nums.size())
		return;
	for (int i = pos; i < nums.size(); ++i)
	{
		ans.push_back(nums[i]);
		if (find(ret.begin(), ret.end(), ans) == ret.end())
			ret.push_back(ans);
		subfunc(nums, ans, i + 1, ret);
		ans.pop_back();
	}
}
vector< vector<int> > subsets(vector<int>& nums)
{
	vector<int> ans;
	vector< vector<int> > ret;
	ret.push_back(ans);
	subfunc(nums, ans, 0, ret);
	return ret;
}