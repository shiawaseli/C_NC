#include "Leetcode.h"

/*
 *
 *	414. ���������
 *
 *  	ִ����ʱ:		12 ms, ������ C++ �ύ�л�����52.80%���û�
 *  	�ڴ�����:		9.5 MB, ������ C++ �ύ�л�����43.54%���û�
 *
 */
int thirdMax(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	for (int i = nums.size() - 2, cnt = 1; i >= 0; --i)
	{
		while (i >= 0 && nums[i] == nums[i + 1])
			--i;
		if (i >= 0)
			++cnt;
		if (cnt == 3)
			return nums[i];
	}
	return nums[nums.size() - 1];
}