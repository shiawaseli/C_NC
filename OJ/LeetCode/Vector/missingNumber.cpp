#include "Leetcode.h"

/*
 *
 *	268. ȱʧ����
 *
 *  	ִ����ʱ :		36 ms, ������ C++ �ύ�л�����24.31%���û�
 *  	�ڴ����� :		10.2 MB, ������ C++ �ύ�л�����5.19%���û�
 *
 */
int missingNumber(vector<int>& nums)
{
	int i;
	sort(nums.begin(), nums.end());
	if (nums[0] == 1)
		return 0;
	for (i = 0; i + 1 < nums.size(); ++i)
	{
		if (nums[i] + 2 == nums[i + 1])
			break;
	}
	return nums[i] + 1;
}