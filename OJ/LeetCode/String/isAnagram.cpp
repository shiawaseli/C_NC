#include "Leetcode.h"

/*
 *
 *	242. ��Ч����ĸ��λ��
 *
 *  	ִ����ʱ:		8 ms, ������ C++ �ύ�л�����96.59%���û�
 *  	�ڴ�����:		9.3 MB, ������ C++ �ύ�л�����27.74%���û�
 *
 */
bool isAnagram(string s, string t)
{
	if (s.size() != t.size())
		return false;
	int book[128] = { 0 };
	for (auto i : s)
		++book[i];
	for (auto j : t)
	{
		if (book[j] == 0)
			return false;
		--book[j];
	}
	return true;
}