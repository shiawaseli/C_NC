#include "Leetcode.h"

/*
 *
 *	67. ���������
 *
 *  	ִ����ʱ:		0 ms, ������ C++ �ύ�л�����100.00%���û�
 *  	�ڴ�����:		8.6 MB, ������ C++ �ύ�л�����51.84%���û�
 *
 */
string addBinary(string a, string b)
{
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int i, flag = 0, max = (a.size() < b.size() ? b.size() : a.size());
	a.resize(max, '0');
	b.resize(max, '0');
	for (i = 0; i < max; ++i)
	{
		flag += a[i] - '0' + b[i] - '0';
		a[i] = flag % 2 + '0';
		flag /= 2;
	}
	if (flag)
		a.push_back('1');
	reverse(a.begin(), a.end());
	return a;
}