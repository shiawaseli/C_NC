#include "Leetcode.h"

/*
 *
 *	169. ����Ԫ��
 *
 *  	ִ����ʱ:		24 ms, ������ C++ �ύ�л�����62.41%���û�
 *  	�ڴ�����:		11 MB, ������ C++ �ύ�л�����85.94%���û�
 *
 */
int majorityElement(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	return nums[nums.size() / 2];
}