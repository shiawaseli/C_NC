#include "Leetcode.h"

/*
 *
 *	50. Pow(x, n)
 *
 *  	ִ����ʱ:		4 ms, ������ C++ �ύ�л�����81.71%���û�
 *  	�ڴ�����:		8.2 MB, ������ C++ �ύ�л�����94.79%���û�
 *
 */
double myPow(double x, int n)
{
	if (n == 0)
		return 1;
	else if (x == 0)
		return 0;
	int i, flag = 0;
	double res = 1;
	if (n < 0)
	{
		if (n == -2147483648LL)
		{
			n = 2147483647;
			res *= x;
		}
		else
			n = -n;
		flag = 1;
	}
	for (i = 0; i < n % 4; ++i)
		res *= x;
	if (n == 4)
		res *= x * x * x * x;
	else if (n / 4 > 0)
		res *= myPow(myPow(x, n / 4), 4);
	if (flag)
		return 1 / res;
	return res;
}