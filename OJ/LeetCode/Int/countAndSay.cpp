#include "Leetcode.h"

/*
 *
 *	38. ����
 *
 *  	ִ����ʱ:		4 ms, ������ C++ �ύ�л�����91.27%���û�
 *  	�ڴ�����:		8.5 MB, ������ C++ �ύ�л�����97.52%���û�
 *
 */
string countAndSay(int n)
{
	int i, j, k;
	string str, tmp, res;
	res.push_back('1');
	for (i = 1; i < n; i++)
	{
		str = res;
		res = tmp;
		if (str.size() == 1)
		{
			res.push_back('1');
			res.push_back(str[0]);
			continue;
		}
		for (j = 0; j < str.size(); j++)
		{
			k = j;
			while (j + 1 < str.size() && str[j] == str[j + 1])
				j++;
			res.push_back('0' + j - k + 1);
			res.push_back(str[k]);
		}
	}
	return res;
}