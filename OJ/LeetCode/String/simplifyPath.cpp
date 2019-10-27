#include "Leetcode.h"

/*
 *
 *	71. ��·��
 *
 *  	ִ����ʱ:		12 ms, ������ C++ �ύ�л�����68.01%���û�
 *  	�ڴ�����:		8.9 MB, ������ C++ �ύ�л�����100.00%���û�
 *
 */
string simplifyPath(string path)
{
	string tmp;
	int start = 1, i = 0, pos = 1;
	if (path[path.size() - 1] != '/')
		path.push_back('/');
	while (start + i < path.size())
	{
		if (path[start + i] == '/')
		{
			if (tmp.size() != 0)
			{
				if (tmp == ".." && pos == 1 || tmp == "." && pos == 1)
					pos = 1;
				else if (tmp == "..")
					pos = path.find_last_of('/', pos - 2) + 1;
				else if (tmp != ".")
				{
					copy(tmp.begin(), tmp.end(), path.begin() + pos);
					pos += tmp.size() + 1;
					path[pos - 1] = '/';
				}
			}
			start += i + 1;
			i = 0;
			tmp.clear();
		}
		else
			tmp.push_back(path[start + (i++)]);
	}
	path.erase(path.begin() + pos - 1, path.end());
	if (path.size() == 0)
		return "/";
	return path;
}