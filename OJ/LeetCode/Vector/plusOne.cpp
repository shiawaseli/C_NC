#include "Leetcode.h"

/*
 *
 *	66. ��һ
 *
 *  	ִ����ʱ:		4 ms, ������ C++ �ύ�л�����87.74%���û�
 *  	�ڴ�����:		8.7 MB, ������ C++ �ύ�л�����6.09%���û�
 *
 */
vector<int> plusOne(vector<int>& digits)
{
	int i = digits.size() - 1;
	++digits[i];
	while (i > 0 && digits[i] > 9)
	{
		++digits[i - 1];
		digits[i--] = 0;
	}
	if (digits[0] > 9)
	{
		digits[0] = 0;
		digits.insert(digits.begin(), 1);
	}
	return digits;
}