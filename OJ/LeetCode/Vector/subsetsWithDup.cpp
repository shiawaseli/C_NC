#include "Leetcode.h"

/*
 *
 *	90. �Ӽ� II
 *
 *  	ִ����ʱ:		16 ms, ������ C++ �ύ�л�����56.53%���û�
 *  	�ڴ�����:		9 MB, ������ C++ �ύ�л�����98.51%���û�
 *
 */
void subfunc(vector<int>& nums, int pos, vector<int>& tmp, vector< vector<int> >& res)
{
	for (int i = pos; i < nums.size(); ++i)
	{
		tmp.push_back(nums[i]);
		res.push_back(tmp);
		subfunc(nums, i + 1, tmp, res);
		tmp.pop_back();
		while (i + 1 < nums.size() && nums[i] == nums[i + 1])
			++i;
	}
}
vector< vector<int> > subsetsWithDup(vector<int>& nums)
{
	vector<int> tmp;
	vector< vector<int> > res;
	res.push_back(tmp);
	sort(nums.begin(), nums.end());
	subfunc(nums, 0, tmp, res);
	return res;
}