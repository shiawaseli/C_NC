#include "Leetcode.h"

/*
 *
 *	35. ��������λ��
 *
 *  	ִ����ʱ:		8 ms, ������ C++ �ύ�л�����80.20%���û�
 *  	�ڴ�����:		8.9 MB, ������ C++ �ύ�л�����78.37%���û�
 *
 */
int searchInsert(vector<int>& nums, int target)
{
	int left = 0, right = nums.size() - 1, mid = (left + right) / 2;
	if (right == -1 || nums[0] > target)
		return 0;
	else if (nums[right] < target)
		return right + 1;
	while (left <= right)
	{
		if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid - 1;
		else
			return mid;
		mid = (left + right) / 2;
	}
	for (mid = right; nums[mid] < target; mid++)
		continue;
	return mid;
}