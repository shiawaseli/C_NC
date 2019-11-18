#include "Leetcode.h"

/*
 *
 *	118. �������
 *
 *  	ִ����ʱ:		8 ms, ������ C++ �ύ�л�����38.83%���û�
 *  	�ڴ�����:		8.6 MB, ������ C++ �ύ�л�����72.81%���û�
 *
 */
vector< vector<int> > generate(int numRows)
{
	vector<int> line;
	vector< vector<int> > res;
	if (!numRows)
		return res;
	line.push_back(1);
	res.push_back(line);
	for (int i = 1; i < numRows; ++i)
	{
		line.push_back(1);
		for (int j = i - 1; j > 0; --j)
			line[j] += line[j - 1];
		res.push_back(line);
	}
	return res;
}