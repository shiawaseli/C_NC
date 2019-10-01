#include "Leetcode.h"

/*
 *
 *	29. �������
 *
 *  	ִ����ʱ :		0 ms, ������ C++ �ύ�л�����100.00%���û�
 *  	�ڴ����� :		8.2 MB, ������ C++ �ύ�л�����74.70%���û�
 *
 */
int divide(int dividend, int divisor)
{
	if (!dividend)
		return 0;
	else if (dividend == -2147483648LL && divisor == -1LL)
		return 2147483647;
	int i, negative = (dividend ^ divisor) < 0 ? -1 : 1;
	unsigned num1 = dividend < 0 ? -(long long)dividend : dividend;
	unsigned num2 = divisor < 0 ? -(long long)divisor : divisor;
	unsigned res = 0;
	for (i = 31; i >= 0; i--)
	{
		if (num2 <= (num1 >> i))
		{
			res += ((unsigned)1) << i;
			num1 -= num2 << i;
		}
	}
	long num = (long)negative * res;
	if (num < -2147483647 || num > 2147483647)
		return -2147483648LL;
	return num;
}
