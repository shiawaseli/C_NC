#include "Leetcode.h"

/*
 *
 *	58. ���һ�����ʵĳ���
 *
 *  	ִ����ʱ:		0 ms, ������ C++ �ύ�л�����100.00%���û�
 *  	�ڴ�����:		8.8 MB, ������ C++ �ύ�л�����71.77%���û�
 *
 */
int lengthOfLastWord(string s)
{
	while (s.size() != 0 && s.find_last_of(' ') == s.size() - 1)
		s.pop_back();
	if (s.find_last_of(' ') >= 0)
		return s.size() - s.find_last_of(' ') - 1;
	else
		return s.size();
}