#include "Leetcode.h"

/*
 *
 *	171. Excel�������
 *
 *  	ִ����ʱ :		4 ms, ������ C++ �ύ�л�����80.55%���û�
 *  	�ڴ����� :		8.2 MB, ������ C++ �ύ�л�����63.96%���û�
 *
 */
int titleToNumber(string s)
{
	unsigned int ret = 0;
	for (auto & i : s)
		ret = ret * 26 + i - 'A' + 1;
	return ret;
}