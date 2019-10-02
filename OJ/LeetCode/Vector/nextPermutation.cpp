#include "Leetcode.h"

/*
 *
 *	31. ��һ������
 *
 *  	ִ����ʱ :		12 ms, ������ C++ �ύ�л�����81.71%���û�
 *  	�ڴ����� :		8.6 MB, ������ C++ �ύ�л�����87.02%���û�
 *
 */
void nextPermutation(vector<int>& nums)
{
	int i, j, min, size = nums.size();
	if (size <= 1)
		return;
	for (i = size - 1; i > 0; i--)
	{
		if (nums[i] > nums[i - 1])
		{
			j = i - 1;
			break;
		}
	}
	if (i == 0)
	{
		sort(nums.begin(), nums.end());
		return;
	}
	for (min = i; i < size; i++)
	{
		if (nums[i] > nums[j] && nums[i] < nums[min])
		{
			min = i;
		}
	}
	i = nums[j];
	nums[j] = nums[min];
	nums[min] = i;
	sort(nums.begin() + j + 1, nums.end());
}