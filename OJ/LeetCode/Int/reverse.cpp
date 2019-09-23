#include "Leetcode.h"

/*
 *
 *	7. ������ת
 *
 *  	ִ����ʱ:		0 ms, ������ C++ �ύ�л�����100.00%���û�
 *  	�ڴ�����:		8 MB, ������ C++ �ύ�л�����95.52%���û�
 *
 */
int reverse(int x)
{
	long tmp, y = 0;
	int flag = x < 0 ? -1 : 1;
	tmp = x < 0 ? -(long)x : (long)x;
	while (tmp > 0)
	{
		y = y * 10 + tmp % 10;
		tmp /= 10;
	}
	if (y > 2147483647 || y < -2147483638)
	{
		return 0;
	}
	return flag * y;
}
