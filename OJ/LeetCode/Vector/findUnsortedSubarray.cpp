#include "Leetcode.h"

/*
 *
 *	581. �����������������
 *
 *  	ִ����ʱ:		60 ms, ������ C++ �ύ�л�����19.75%���û�
 *  	�ڴ�����:		11.6 MB, ������ C++ �ύ�л�����9.14%���û�
 *
 */
int findUnsortedSubarray(vector<int>& nums)
{
	int i, j;
	vector<int> tmp(nums);
	sort(nums.begin(), nums.end());
	for (i = 0; i < nums.size(); ++i)
	{
		if (nums[i] != tmp[i])
			break;
	}
	for (j = nums.size() - 1; j > i; --j)
	{
		if (nums[j] != tmp[j])
			break;
	}
	return j - i + 1;
}