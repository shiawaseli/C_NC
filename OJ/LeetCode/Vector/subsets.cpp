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
vector< vector<int> > subsets1(vector<int>& nums)
{
	vector<int> ans;
	vector< vector<int> > ret;
	ret.push_back(ans);
	subfunc(nums, ans, 0, ret);
	return ret;
}

/*
 *
 *	78. �Ӽ�
 *
 *  	ִ����ʱ:		4 ms, ������ C++ �ύ�л�����91.88%���û�
 *  	�ڴ�����:		9.6 MB, ������ C++ �ύ�л�����24.43%���û�
 *
 */
vector< vector<int> > subsets2(vector<int>& nums)
{
	vector<int> tmp;
	vector< vector<int> > ret;
	if (nums.size() == 0)
	{
		ret.push_back(vector<int>());
		return ret;
	}
	int i, size, add = nums[nums.size() - 1];
	nums.pop_back();
	ret = subsets(nums);
	for (i = 0, size = ret.size(); i < size; ++i)
	{
		tmp = ret[i];
		tmp.push_back(add);
		ret.push_back(tmp);
	}
	return ret;
}

vector< vector<int> > subsets(vector<int>& nums)
{
	return subsets1(nums);
}