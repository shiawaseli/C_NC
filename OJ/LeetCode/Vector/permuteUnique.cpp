#include "Leetcode.h"

/*
 *
 *	47. ȫ���� II
 *
 *  	ִ����ʱ:		40 ms, ������ C++ �ύ�л�����66.14%���û�
 *  	�ڴ�����:		9.8 MB, ������ C++ �ύ�л�����91.38%���û�
 *
 */
vector< vector<int> > permuteUnique(vector<int>& nums)
{
	vector< vector<int> > res;
	res.push_back(nums);
	next_permutation(nums.begin(), nums.end());
	while (res[0] != nums)
	{
		res.push_back(nums);
		next_permutation(nums.begin(), nums.end());
	}
	return res;
}