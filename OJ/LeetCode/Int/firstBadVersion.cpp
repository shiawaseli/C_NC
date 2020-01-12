#include "Leetcode.h"

/*
 *
 *	278. ��һ������İ汾
 *
 *  	ִ����ʱ:		0 ms, ������ C++ �ύ�л�����100.00%���û�
 *  	�ڴ�����:		8.1 MB, ������ C++ �ύ�л�����41.47%���û�
 *
 */
int badVersion;
bool isBadVersion(int version)
{
	return version == badVersion;
}
int firstBadVersion(int n)
{
	int l = 0, r = n - 1, mid;
	while (l <= r)
	{
		mid = l + (r - l) / 2;
		if (isBadVersion(mid))
			r = mid - 1;
		else
			l = mid + 1;
	}
	return l;
}