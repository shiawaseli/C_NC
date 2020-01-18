#include "Leetcode.h"

/*
 *
 *	96. ��ͬ�Ķ���������
 *
 *  	ִ����ʱ:		560 ms, ������ C++ �ύ�л�����6.99%���û�
 *  	�ڴ�����:		72.7 MB, ������ C++ �ύ�л�����5.19%���û�
 *
 */
int numTrees_1(int n)
{
	if (n <= 1)
		return 1;
	int i, sum = 0;
	map<int, int> book;
	for (i = 0; i < n; ++i)
	{
		if (!book[i])
			book[i] = numTrees(i);
		if (!book[n - i - 1])
			book[n - i - 1] = numTrees(n - i - 1);
		sum += book[i] * book[n - i - 1];
	}
	return sum;
}

/*
 *
 *	96. ��ͬ�Ķ���������
 *
 *  	ִ����ʱ:		0 ms, ������ C++ �ύ�л�����100.00%���û�
 *  	�ڴ�����:		8.3 MB, ������ C++ �ύ�л�����50.23%���û�
 *
 */
int numTrees_2(int n) 
{
	int s[n + 1] = { 0 };
	s[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int k = 1; k <= i; k++)
			s[i] += s[i - k] * s[k - 1];
	}
	return s[n];
}

int numTrees(int n)
{
	return numTrees_2(n);
}