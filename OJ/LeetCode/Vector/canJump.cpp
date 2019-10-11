#include "Leetcode.h"

/*
 *
 *	55. ��Ծ��Ϸ
 *
 *  	ִ����ʱ:		8 ms, ������ C++ �ύ�л�����98.28%���û�
 *  	�ڴ�����:		9.9 MB, ������ C++ �ύ�л�����73.32%���û�
 *
 */
bool canJump1(vector<int>& nums)
{
	int i, j, size = nums.size();
	for (i = 0; i < size; ++i)
	{
		j = i + nums[i] - 1;
		if (j >= size)
			j = size - 1;
		while (j > i)
		{
			if (nums[j] + j - i <= nums[i])
				nums[j] = 0;
			--j;
		}
	}
	for (i = 0, j = 0; i < size; ++i)
	{
		if (nums[i] == 0)
		{
			if (nums[j] + j == size - 1)
				return true;
			else if (nums[j] <= i - j)
				return false;
		}
		else
			j = i;
	}
	return true;
}

/*
 *
 *	55. ��Ծ��Ϸ
 *
 *  	ִ����ʱ:		24 ms, ������ C++ �ύ�л�����25.61%���û�
 *  	�ڴ�����:		10.1 MB, ������ C++ �ύ�л�����66.32%���û�
 *
 */
bool canJump2(vector<int>& nums) // ���� 45. ��Ծ��Ϸ II
{
	if (nums.size() == 1)
		return true;
	vector<int> book(nums.size(), 2147483647);
	for (int i = nums.size() - 1; i >= 0; --i)
	{
		if (i > 0 && nums[i - 1] > nums[i])
			nums[i] = 0;
		if (!nums[i])
			continue;
		for (int jump = 1; jump <= nums[i] && i + jump < nums.size(); ++jump)
		{
			if (i + jump == nums.size() - 1)
			{
				book[i] = 1;
				break;
			}
			if (nums[i + jump] == 0)
				continue;
			if (book[i + jump] != 2147483647 && book[i] > book[i + jump] + 1)
				book[i] = book[i + jump] + 1;
		}
	}
	if (book[0] != 2147483647)
		return true;
	else
		return false;
}

bool canJump(vector<int>& nums)
{
	return canJump1(nums);
}