#include "Leetcode.h"

/*
 *
 *	53. ��������
 *
 *  	ִ����ʱ:		4 ms, ������ C++ �ύ�л�����99.20%���û�
 *  	�ڴ�����:		9.3 MB, ������ C++ �ύ�л�����77.84%���û�
 *
 */
int maxSubArray(vector<int>& nums)
{
	int i, sum = 0, res = -2147483647, size = nums.size();
	for (i = 0; i < size; ++i)
	{
		sum += nums[i];
		if (sum > res)
			res = sum;
		if (sum < 0)
			sum = 0;
	}
	return res;
}