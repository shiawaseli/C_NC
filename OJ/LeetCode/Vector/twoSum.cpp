#include "Leetcode.h"

/*
 *
 *	1. ����֮��
 *
 *  	ִ����ʱ:		364 ms, ������ C++ �ύ�л�����17.71%���û�
 *  	�ڴ�����:		9.1 MB, ������ C++ �ύ�л�����92.84%���û�
 *
 */
vector<int> twoSum(vector<int>& nums, int target)
{
	vector<int> res;
	int i, j, size = nums.size();
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (i == j)
			{
				continue;
			}
			else if (nums[i] + nums[j] == target)
			{
				res.push_back(i);
				res.push_back(j);
				goto ret;
			}
		}
	}
ret:
	return res;
}
