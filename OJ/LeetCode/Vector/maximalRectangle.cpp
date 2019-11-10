#include "Leetcode.h"

/*
 *
 *	85. ������
 *
 *  	ִ����ʱ:		32 ms, ������ C++ �ύ�л�����54.59%���û�
 *  	�ڴ�����:		10.4 MB, ������ C++ �ύ�л�����98.86%���û�
 *
 */
int maximalRectangle(vector< vector<char> >& matrix)
{
	int i, j, res = 0;
	for (i = 1; i < matrix.size(); ++i)
	{
		for (j = 0; j < matrix[0].size(); ++j)
		{
			if (matrix[i][j] != '0')
				matrix[i][j] += matrix[i - 1][j] - '0';
		}
	}
	int left, right;
	for (i = 0; i < matrix.size(); ++i)
	{
		for (j = 0; j < matrix[0].size(); ++j)
		{
			if (j == 0 || matrix[i][j] > matrix[i][j - 1])
				left = right = j;
			while (left - 1 >= 0 && matrix[i][j] <= matrix[i][left - 1])
				--left;
			while (right + 1 < matrix[i].size() && matrix[i][j] <= matrix[i][right + 1])
				++right;
			if (res < (matrix[i][j] - '0') * (right - left + 1))
				res = (matrix[i][j] - '0') * (right - left + 1);
		}
	}
	return res;
}