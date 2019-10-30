#include "Leetcode.h"

/*
 *
 *	75. ��ɫ����
 *
 *  	ִ����ʱ:		4 ms, ������ C++ �ύ�л�����90.03%���û�
 *  	�ڴ�����:		8.6 MB, ������ C++ �ύ�л�����23.56%���û�
 *
 */
void sortColors(vector<int>& nums)
{
	int i = 0, flag1 = 0, flag2 = nums.size() - 1;
	while (i <= flag2)
	{
		if (nums[i] == 0)
			swap(nums[i++], nums[flag1++]);
		else if (nums[i] == 2)
			swap(nums[i], nums[flag2--]);
		else
			++i;
	}
}

/*
 *
 *	75. ��ɫ����
 *
 *  	ִ����ʱ:		0 ms, ������ C++ �ύ�л�����100.00%���û�
 *  	�ڴ�����:		8.4 MB, ������ C++ �ύ�л�����80.22%���û�
 *
 */
void sortColors(vector<int>& nums)
{
	int i = 0, flag1 = 0, flag2 = nums.size() - 1;
	if (flag2 < 1)
		return;
	while (i <= flag2)
	{
		if (nums[i] == 0)
		{
			nums[i] = nums[flag1];
			nums[flag1] = 0;
		}
		else if (nums[i] == 2)
		{
			nums[i] = nums[flag2];
			nums[flag2] = 2;
		}
		else
			++i;
		while (flag1 <= flag2 && nums[flag1] == 0)
			++flag1;
		while (flag1 <= flag2 && nums[flag2] == 2)
			--flag2;
		if (i < flag1)
			i = flag1;
	}
}

/*
 *
 *	75. ��ɫ����
 *
 *  	ִ����ʱ:		8 ms, ������ C++ �ύ�л�����55.89%���û�
 *  	�ڴ�����:		8.5 MB, ������ C++ �ύ�л�����41.75%���û�
 *
 */
void sortColors(vector<int>& nums)
{
	int i, red = 0, white = 0, blue = 0;
	for (i = 0; i < nums.size(); ++i)
	{
		if (nums[i] == 0)
			++red;
		else if (nums[i] == 1)
			++white;
		else
			++blue;
	}
	for (i = 0; i < nums.size(); ++i)
	{
		if (i < red)
			nums[i] = 0;
		else if (i < red + white)
			nums[i] = 1;
		else
			nums[i] = 2;
	}
}