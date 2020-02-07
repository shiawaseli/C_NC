#include "Leetcode.h"

/*
 *
 *	724. Ѱ���������������
 *
 *  	ִ����ʱ:		36 ms, ������ C++ �ύ�л�����31.70%���û�
 *  	�ڴ�����:		9.8 MB, ������ C++ �ύ�л�����65.26%���û�
 *
 */
int pivotIndex(vector<int>& nums)
{
	int i, leftsum = 0, sum = 0;
	for (i = 0; i < nums.size(); ++i)
		sum += nums[i];
	for (i = 0; i < nums.size(); ++i)
	{
		if (sum == leftsum * 2 + nums[i])
			return i;
		leftsum += nums[i];
	}
	return -1;
}