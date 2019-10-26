#include "Leetcode.h"

/*
 *
 *	69. x ��ƽ����
 *
 *  	ִ����ʱ:		24 ms, ������ C++ �ύ�л�����13.68%���û�
 *  	�ڴ�����:		8 MB, ������ C++ �ύ�л�����94.43%���û�
 *
 */
int mySqrt(int x)
{
	long res = 1;
	while (res * res <= x)
		++res;
	return res - 1;
}

/*
 *
 *	69. x ��ƽ����
 *
 *  	ִ����ʱ:		8 ms, ������ C++ �ύ�л�����58.12%���û�
 *  	�ڴ�����:		8.1 MB, ������ C++ �ύ�л�����83.99%���û�
 *
 */
int mySqrt(int x)
{
	long res = x / 2;
	while (res * res > x)
		res /= 2;
	while (res * res <= x)
		++res;
	return res - 1;
}

/*
 *
 *	69. x ��ƽ����
 *
 *  	ִ����ʱ:		4 ms, ������ C++ �ύ�л�����88.84%���û�
 *  	�ڴ�����:		8.2 MB, ������ C++ �ύ�л�����82.25%���û�
 *
 */
int mySqrt(int x)
{
	long left = 0, right = x, mid;
	while (left < right)
	{
		mid = left + (right - left + 1) / 2;
		if (mid * mid > x)
			right = mid - 1;
		else
			left = mid;
	}
	return left;
}