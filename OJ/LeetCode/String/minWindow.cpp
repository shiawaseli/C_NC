#include "Leetcode.h"

/*
 *
 *	76. ��С�����Ӵ�
 *
 *  	ִ����ʱ:		72 ms, ������ C++ �ύ�л�����18.57%���û�
 *  	�ڴ�����:		9.7 MB, ������ C++ �ύ�л�����76.66%���û�
 *
 */
string minWindow(string s, string t)
{
	if (s.size() < t.size())
		return "";
	int i, left = 0, right = -1;
	int resleft = -1, resright = s.size();
	int book[64][2] = { 0 };

	for (i = 0; i < t.size(); ++i)
		++book[t[i] - 'A'][0];
	while (right - left + 1 < t.size())
	{
		++right;
		++book[s[right] - 'A'][1];
	}
	while (left <= s.size() - t.size())
	{
		i = 0;
		while (i < 64)
		{
			while (book[i][0] > book[i][1])
			{
				if (right + 1 >= s.size())
					break;
				++right;
				++book[s[right] - 'A'][1];
			}
			if (book[i][0] > book[i][1])
				break;
			++i;
		}
		if (i < 64)
			break;
		if (right - left + 1 < resright - resleft + 1)
		{
			resleft = left;
			resright = right;
		}
		if (book[s[left] - 'A'][0])
		{
			--book[s[left] - 'A'][1];
			++left;
		}
		while (left <= s.size() - t.size() && !book[s[left] - 'A'][0])
		{
			--book[s[left] - 'A'][1];
			++left;
		}
	}
	return resleft == -1 ? "" : s.substr(resleft, resright - resleft + 1);
}