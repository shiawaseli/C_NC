#include "Leetcode.h"

/*
 *
 *	5. ������Ӵ�
 *
 *  	ִ����ʱ:		28 ms, ������ C++ �ύ�л�����85.53%���û�
 *  	�ڴ�����:		15.9 MB, ������ C++ �ύ�л�����42.57%���û�
 *
 */
string longestPalindrome(string s)
{
	int i, mid = 0, mid2 = 0, len = 0, flag = 0;
	int size = s.size();
	string res;
	if (s.empty() || s.size() == 1)
	{
		return s;
	}
	while (mid < size)
	{
		for (i = 0; mid - i >= 0 && mid2 + i < size; i++)
		{
			if (s[mid - i] != s[mid2 + i])
			{
				break;
			}
		}
		if (len <= (mid2 + i - 1) - (mid - i + 1) + 1)
		{
			len = (mid2 + i - 1) - (mid - i + 1) + 1;
			res = s.substr(mid - i + 1, len);
		}
		if (s[mid] != s[mid + 1] || flag == 2)
		{
			mid++;
			mid2 = mid;
			flag = 1;
		}
		else
		{
			mid2 = mid + 1;
			flag = 2;
		}
	}
	return res;
}
