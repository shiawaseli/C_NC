#include "Leetcode.h"

/*
 *
 *	167. ����֮�� II - ������������
 *
 *  	ִ����ʱ:		280 ms, ������ C++ �ύ�л�����5.69%���û�
 *  	�ڴ�����:		9.6 MB, ������ C++ �ύ�л�����19.68%���û�
 *
 */
vector<int> twoSum_167(vector<int>& numbers, int target)
{
	int i, j;
	vector<int> res;
	for (i = 0; i < numbers.size(); ++i)
	{
		for (j = i + 1; j < numbers.size(); ++j)
		{
			if (numbers[i] + numbers[j] > target)
				break;
			else if (numbers[i] + numbers[j] == target)
			{
				res.push_back(i + 1);
				res.push_back(j + 1);
				return res;
			}
		}
	}
	return res;
}