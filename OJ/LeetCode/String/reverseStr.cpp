#include "Leetcode.h"

/*
 *
 *	541. ��ת�ַ��� II
 *
 *  	ִ����ʱ:		8 ms, ������ C++ �ύ�л�����69.49%���û�
 *  	�ڴ�����:		9.8 MB, ������ C++ �ύ�л�����14.98%���û�
 *
 */
string reverseStr(string s, int k)
{
	char tmp;
	int i = 0, j;
	while (i < s.size())
	{
		if (i + k >= s.size())
			k = s.size() - i;
		for (j = 0; j < k / 2; ++j)
		{
			tmp = s[i + j];
			s[i + j] = s[i + k - j - 1];
			s[i + k - j - 1] = tmp;
		}
		i += 2 * k;
	}
	return s;
}