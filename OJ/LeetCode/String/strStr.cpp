#include "Leetcode.h"

/*
 *
 *	28. ʵ�� strStr()
 *
 *  	ִ����ʱ:		4 ms, ������ C++ �ύ�л�����93.41%���û�
 *  	�ڴ�����:		9.2 MB, ������ C++ �ύ�л�����75.85%���û�
 *
 */
int strStr(string haystack, string needle)
{
	if (needle == "")
		return 0;
	int i, size1 = haystack.size(), size2 = needle.size();
	for (i = 0; i + size2 <= size1; i++)
	{
		if (haystack[i] == needle[0] && haystack.substr(i, size2) == needle)
		{
			return i;
		}
	}
	return -1;
}