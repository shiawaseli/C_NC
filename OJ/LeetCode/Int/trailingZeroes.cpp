#include "Leetcode.h"

/*
 *
 *	172. �׳˺����
 *
 *  	ִ����ʱ :		4 ms, ������ C++ �ύ�л�����70.20%���û�
 *  	�ڴ����� :		8.1 MB, ������ C++ �ύ�л�����80.43%���û�
 *
 */
int trailingZeroes(int n)
{
	int cnt = 0;
	while (n)
	{
		cnt += n / 5;
		n /= 5;
	}
	return cnt;
}