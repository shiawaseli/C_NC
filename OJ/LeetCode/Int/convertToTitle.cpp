#include "Leetcode.h"

/*
 *
 *	168. Excel��������
 *
 *  	ִ����ʱ :		0 ms, ������ C++ �ύ�л�����100.00%���û�
 *  	�ڴ����� :		8.2 MB, ������ C++ �ύ�л�����24.04%���û�
 *
 */
string convertToTitle(int n)
{
	string ret;
	while (n)
	{
		ret.push_back((n - 1) % 26 + 'A');
		n = (n - 1) / 26;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}