#include "Leetcode.h"

/*
 *
 *	68. �ı����Ҷ���
 *
 *  	ִ����ʱ:		4 ms, ������ C++ �ύ�л�����80.36%���û�
 *  	�ڴ�����:		9 MB, ������ C++ �ύ�л�����82.03%���û�
 *
 */
vector<string> fullJustify(vector<string>& words, int maxWidth)
{
	string tmp;
	int i = 0, j = 0, more;
	int count = 0, mark = 0, blank = 0;
	vector<string> res;
	while (i < words.size())
	{
		if (count + words[i].size() + i - mark <= maxWidth)
		{
			count += words[i].size();
			++i;
		}
		else
		{
			res.push_back(string());
			if (i - mark - 1 > 0)
			{
				tmp = string((maxWidth - count) / (i - mark - 1), ' ');
				more = (maxWidth - count) % (i - mark - 1);
			}

			while (i - mark - 1 > 0)
			{
				res[j] += words[mark++] + tmp;
				if (more-- > 0)
					res[j] += ' ';
			}
			res[j] += words[mark++];
			while (res[j].size() < maxWidth)
				res[j].push_back(' ');
			++j;
			count = 0;
		}
	}
	if (i - mark)
	{
		res.push_back(string());
		while (i - mark - 1)
		{
			res[j] += words[mark++] + ' ';
		}
		res[j] += words[mark];
		while (res[j].size() < maxWidth)
			res[j].push_back(' ');
	}

	return res;
}