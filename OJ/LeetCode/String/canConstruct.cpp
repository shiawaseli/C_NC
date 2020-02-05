#include "Leetcode.h"

/*
 *
 *	383. �����
 *
 *  	ִ����ʱ:		16 ms, ������ C++ �ύ�л�����91.87%���û�
 *  	�ڴ�����:		10.9 MB, ������ C++ �ύ�л�����74.54%���û�
 *
 */
bool canConstruct(string ransomNote, string magazine)
{
	int book[128] = { 0 };
	for (int i = 0; i < magazine.size(); ++i)
		++book[magazine[i]];
	for (int i = 0; i < ransomNote.size(); ++i)
	{
		if (--book[ransomNote[i]] < 0)
			return false;
	}
	return true;
}