#include "Leetcode.h"

/*
 *
 *	34. �����������в���Ԫ�صĵ�һ�������һ��λ��
 *
 *  	ִ����ʱ:		8 ms, ������ C++ �ύ�л�����94.65%���û�
 *  	�ڴ�����:		10.4 MB, ������ C++ �ύ�л�����75.63%���û�
 *
 */
vector<int> searchRange(vector<int>& nums, int target)
{
	vector<int> res(2, -1);
	int left = 0, right = nums.size() - 1, mid = (left + right) / 2;
	while (left <= right)
	{
		if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid - 1;
		else
			break;
		mid = (left + right) / 2;
	}
	if (left <= right)
	{
		for (res[0] = mid; res[0] > 0 && nums[res[0]] == nums[res[0] - 1]; --res[0])
			continue;
		for (res[1] = mid; res[1] + 1 < nums.size() && nums[res[1]] == nums[res[1] + 1]; ++res[1])
			continue;
	}
	return res;
}