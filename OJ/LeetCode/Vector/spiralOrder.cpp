#include "Leetcode.h"

/*
 *
 *	54. ��������
 *
 *  	ִ����ʱ:		0 ms, ������ C++ �ύ�л�����100.00%���û�
 *  	�ڴ�����:		8.6 MB, ������ C++ �ύ�л�����58.52%���û�
 *
 */
vector<int> spiralOrder(vector< vector<int> >& matrix)
{
	vector<int> res;
	if (matrix.size() == 0)
		return res;
	int i, x = 0, y = 0, row = matrix.size(), col = matrix[0].size(), num = row * col;
	if (row == 1)
		return matrix[0];
	while (num)
	{
		if (col == 1)
			break;
		for (i = 1; num && i < col; ++i)
		{
			res.push_back(matrix[x][y]);
			--num;
			++y;
		}
		for (i = 1; num && i < row; ++i)
		{
			res.push_back(matrix[x][y]);
			--num;
			++x;
		}
		for (i = 1; num && i < col; ++i)
		{
			res.push_back(matrix[x][y]);
			--num;
			--y;
		}
		for (i = 1; num && i < row; ++i)
		{
			res.push_back(matrix[x][y]);
			--num;
			--x;
		}
		++x;
		++y;
		row -= 2;
		col -= 2;
	}
	for (i = 0; i < num; ++i)
		res.push_back(matrix[x + i][y]);
	return res;
}