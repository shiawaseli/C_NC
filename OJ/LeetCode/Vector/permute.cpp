#include "Leetcode.h"

/*
 *
 *	46. ȫ����
 *
 *  	ִ����ʱ:		12 ms, ������ C++ �ύ�л�����98.14%���û�
 *  	�ڴ�����:		9 MB, ������ C++ �ύ�л�����96.26%���û�
 *
 */
vector< vector<int> > permute(vector<int>& nums)
{
	vector<vector<int>> res;
	res.push_back(nums);
	next_permutation(nums.begin(), nums.end());
	while (res[0] != nums)
	{
		res.push_back(nums);
		next_permutation(nums.begin(), nums.end());
	}
	return res;
}