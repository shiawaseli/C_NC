#include "Leetcode.h"

/*
 *
 *	136. ֻ����һ�ε�����
 *
 *  	ִ����ʱ:		24 ms, ������ C++ �ύ�л�����28.09%���û�
 *  	�ڴ�����:		9.8 MB, ������ C++ �ύ�л�����32.95%���û�
 *
 */
int singleNumber(vector<int>& nums)
{
	int ret = nums[0];
	for (int i = nums.size() - 1; i > 0; --i)
		ret ^= nums[i];
	return ret;
}