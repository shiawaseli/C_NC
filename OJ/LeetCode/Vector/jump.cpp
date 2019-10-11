#include "Leetcode.h"

/*
 *
 *	45. ��Ծ��Ϸ II
 *
 *  	ִ����ʱ:		12 ms, ������ C++ �ύ�л�����87.10%���û�
 *  	�ڴ�����:		10.4 MB, ������ C++ �ύ�л�����68.85%���û�
 *
 */
int jump(vector<int>& nums)
{
	if (nums.size() == 1)
		return 0;
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
	return book[0];
}