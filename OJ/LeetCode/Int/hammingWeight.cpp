#include "Leetcode.h"

/*
 *
 *	191. λ1�ĸ���
 *
 *  	ִ����ʱ:		0 ms, ������ C++ �ύ�л�����100.00%���û�
 *  	�ڴ�����:		8.2 MB, ������ C++ �ύ�л�����14.97%���û�
 *
 */
int hammingWeight_1(uint32_t n)
{
	int cnt = 0;
	for (int i = 0; i < 32; ++i)
	{
		if ((n >> i) & 1 == 1)
			++cnt;
	}
	return cnt;
}

/*
 *
 *	191. λ1�ĸ���
 *
 *  	ִ����ʱ:		0 ms, ������ C++ �ύ�л�����100.00%���û�
 *  	�ڴ�����:		8.2 MB, ������ C++ �ύ�л�����24.40%���û�
 *
 */
int hammingWeight_2(uint32_t n)
{
	int cnt = 0;
	while (n)
	{
		++cnt;
		n &= n - 1;
	}
	return cnt;
}

int hammingWeight(uint32_t n)
{
	return hammingWeight_1(n);
}