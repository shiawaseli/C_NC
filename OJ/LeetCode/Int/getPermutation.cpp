#include "Leetcode.h"

/*
 *
 *	60. ��k������
 *
 *  	ִ����ʱ:		520 ms, ������ C++ �ύ�л�����12.05%���û�
 *  	�ڴ�����:		8.1 MB, ������ C++ �ύ�л�����82.28%���û�
 *
 */
string getPermutation(int n, int k)
{
	int i;
	string res;
	for (i = 0; i < n; ++i)
		res.push_back('1' + i);
	for (i = 1; i < k; ++i)
		next_permutation(res.begin(), res.end());
	return res;
}