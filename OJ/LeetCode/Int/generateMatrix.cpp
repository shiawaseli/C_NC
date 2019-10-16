#include "Leetcode.h"

/*
 *
 *	59. �������� II
 *
 *  	ִ����ʱ:		4 ms, ������ C++ �ύ�л�����94.59%���û�
 *  	�ڴ�����:		9 MB, ������ C++ �ύ�л�����36.16%���û�
 *
 */
vector< vector<int> > generateMatrix(int n)
{
	int i, row = 0, col = 0, num = 1, max = n * n;
	vector< vector<int> > res;
	for (i = 0; i < n; ++i)
		res.push_back(vector<int>(n, 1));
	for (--n; n > 0; n -= 2)
	{
		for (i = 0; num <= max && i < n; ++i)
			res[row][col++] = num++;
		for (i = 0; num <= max && i < n; ++i)
			res[row++][col] = num++;
		for (i = 0; num <= max && i < n; ++i)
			res[row][col--] = num++;
		for (i = 0; num <= max && i < n; ++i)
			res[row--][col] = num++;
		++row;
		++col;
	}
	if (num <= max)
		res[row][col] = num;
	return res;
}