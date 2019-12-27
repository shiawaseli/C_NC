#include "Leetcode.h"

/*
 *
 *	205. ͬ���ַ���
 *
 *  	ִ����ʱ:		4 ms, ������ C++ �ύ�л�����99.75%���û�
 *  	�ڴ�����:		9.1 MB, ������ C++ �ύ�л�����38.94%���û�
 *
 */
bool isIsomorphic(string s, string t)
{
	if (s.size() != t.size())
		return false;
	map<char, char> book;
	int bbook[128] = { 0 };
	for (int i = 0; i < s.size(); ++i)
	{
		if (book[s[i]] != t[i])
		{
			if (book[s[i]] || bbook[t[i]])
				return false;
			book[s[i]] = t[i];
			bbook[t[i]] = 1;
		}
	}
	return true;
}