#include "Leetcode.h"

/*
 *
 *	125. ��֤���Ĵ�
 *
 *  	ִ����ʱ:		12 ms, ������ C++ �ύ�л�����49.47%���û�
 *  	�ڴ�����:		9.5 MB, ������ C++ �ύ�л�����30.40%���û�
 *
 */
bool isPalindrome(string s)
{
	int i = 0, j = s.size() - 1;
	while (i < j)
	{
		while (i < j && !isalnum(s[i]))
			++i;
		while (i < j && !isalnum(s[j]))
			--j;
		if (tolower(s[i]) != tolower(s[j]))
			break;
		++i, --j;
	}
	return i >= j;
}