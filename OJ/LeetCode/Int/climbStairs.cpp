#include "Leetcode.h"

/*
 *
 *	70. ��¥��
 *
 *  	ִ����ʱ:		0 ms, ������ C++ �ύ�л�����100.00%���û�
 *  	�ڴ�����:		8.2 MB, ������ C++ �ύ�л�����75.90%���û�
 *
 */
int climbStairs(int n)
{
	int i, pre = 0, cur = 1, res = 0;
	for (i = 0; i < n; ++i)
	{
		res = pre + cur;
		pre = cur;
		cur = res;
	}
	return res;
}