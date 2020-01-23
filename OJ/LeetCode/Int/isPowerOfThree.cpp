#include "Leetcode.h"

/*
 *
 *	326. 3����
 *
 *  	ִ����ʱ:		20 ms, ������ C++ �ύ�л�����75.98%���û�
 *  	�ڴ�����:		7.9 MB, ������ C++ �ύ�л�����97.89%���û�
 *
 */
bool isPowerOfThree(int n)
{
	if (n <= 0)
		return false;
	while (n)
	{
		if (n == 1)
			break;
		if (n % 3)
			return false;
		n /= 3;
	}
	return true;
}