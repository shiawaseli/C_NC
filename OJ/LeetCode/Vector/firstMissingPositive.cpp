#include "Leetcode.h"

/*
 *
 *	41. ȱʧ�ĵ�һ������
 *
 *  	ִ����ʱ:		0 ms, ������ C++ �ύ�л�����100.00%���û�
 *  	�ڴ�����:		8.5 MB, ������ C++ �ύ�л�����94.05%���û�
 *
 */
int firstMissingPositive(vector<int>& nums)
{
	int i, size = nums.size();
	char *book = new char[size];
	for (i = 0; i < size; ++i)
		book[i] = 0;
	for (i = 0; i < size; ++i)
	{
		if (nums[i] > 0 && nums[i] < size + 1)
			++book[nums[i] - 1];
	}
	for (i = 0; i < size; ++i)
	{
		if (book[i] == 0)
			break;
	}
	return i + 1;
}