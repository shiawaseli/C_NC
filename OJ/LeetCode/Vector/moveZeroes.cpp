#include "Leetcode.h"

/*
 *
 *	283. �ƶ���
 *
 *  	ִ����ʱ :		24 ms, ������ C++ �ύ�л�����32.11%���û�
 *  	�ڴ����� :		10.2 MB, ������ C++ �ύ�л�����5.49%���û�
 *
 */
void moveZeroes(vector<int>& nums)
{
	int i, j;
	for (i = 0; i < nums.size(); ++i)
	{
		while (i < nums.size() && nums[i] != 0)
			++i;
		j = i + 1;
		while (j < nums.size() && nums[j] == 0)
			++j;
		if (j >= nums.size())
			return;
		nums[i] = nums[j];
		nums[j] = 0;
	}
}