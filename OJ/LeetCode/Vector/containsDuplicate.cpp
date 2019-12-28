#include "Leetcode.h"

/*
 *
 *	217. �����ظ�Ԫ��
 *
 *  	ִ����ʱ:		56 ms, ������ C++ �ύ�л�����39.23%���û�
 *  	�ڴ�����:		16.6 MB, ������ C++ �ύ�л�����16.11%���û�
 *
 */
bool containsDuplicate(vector<int>& nums)
{
	map<int, int> book;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (book[nums[i]] == 1)
			return true;
		book[nums[i]] = 1;
	}
	return false;
}