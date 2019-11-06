#include "Leetcode.h"

/*
 *
 *	33. ������ת��������
 *
 *  	ִ����ʱ:		4 ms, ������ C++ �ύ�л�����91.44%���û�
 *  	�ڴ�����:		8.6 MB, ������ C++ �ύ�л�����91.11%���û�
 *
 */
int search_33(vector<int>& nums, int target)
{
	if (nums.size() == 0)
		return -1;
	else if (nums.size() == 1)
		return nums[0] == target ? 0 : -1;
	int left = 0, right = nums.size() - 1, mid = (right + left) / 2;
	while (left < right)
	{
		if (mid > 0 && nums[mid - 1] > nums[mid])
			break;
		else if (mid + 1 < nums.size() && nums[mid] > nums[mid + 1])
		{
			++mid;
			break;
		}
		if (nums[left] < nums[mid])
			left = mid;
		else
			right = mid;
		mid = (right + left) / 2;
	}
	if (left < right)
	{
		left = mid;
		right = mid + nums.size() - 1;
	}
	else
	{
		left = 0;
		right = nums.size() - 1;
	}
	mid = (right + left) / 2;
	while (left <= right)
	{
		if (nums[mid % nums.size()] < target)
			left = mid + 1;
		else if (nums[mid % nums.size()] > target)
			right = mid - 1;
		else
			return mid % nums.size();
		mid = (right + left) / 2;
	}
	return -1;
}