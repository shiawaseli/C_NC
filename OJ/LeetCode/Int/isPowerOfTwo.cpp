#include "Leetcode.h"

/*
 *
 *	231. 2����
 *
 *  	ִ����ʱ:		4 ms, ������ C++ �ύ�л�����72.27%���û�
 *  	�ڴ�����:		8 MB, ������ C++ �ύ�л�����54.45%���û�
 *
 */
bool isPowerOfTwo(int n)
{
	if (n <= 0)
		return false;
	return !(n & n - 1);
}