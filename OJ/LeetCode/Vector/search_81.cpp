#include "Leetcode.h"

/*
 *
 *	81. ������ת�������� II
 *
 *  	ִ����ʱ:		4 ms, ������ C++ �ύ�л�����97.57%���û�
 *  	�ڴ�����:		8.8 MB, ������ C++ �ύ�л�����18.18%���û�
 *
 */
bool search_81(vector<int>& nums, int target)
{
	int size = nums.size(), left, right = size - 1, mid;
	for (left = 1; left < size; ++left)
		if (nums[left] < nums[left - 1])
			break;
	right += left;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (nums[mid % size] == target)
			return true;
		else if (nums[mid % size] > target)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return false;
}