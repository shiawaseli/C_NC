#include "Leetcode.h"

/*
 *
 *	73. ��������
 *
 *  	ִ����ʱ:		52 ms, ������ C++ �ύ�л�����98.34%���û�
 *  	�ڴ�����:		11.2 MB, ������ C++ �ύ�л�����98.10%���û�
 *
 */
void setZeroes(vector< vector<int> >& matrix)
{
	int i, j, flagrow = 0, flagcol = 0;
	for (i = 0; i < matrix.size(); ++i)
		if (matrix[i][0] == 0)
			flagcol = 1;
	for (j = 0; j < matrix[0].size(); ++j)
		if (matrix[0][j] == 0)
			flagrow = 1;
	for (i = 1; i < matrix.size(); ++i)
	{
		for (j = 1; j < matrix[0].size(); ++j)
		{
			if (matrix[i][j] == 0)
				matrix[i][0] = matrix[0][j] = 0;
		}
		for (j = 1; j < matrix[0].size(); ++j)
		{
			if (matrix[i][0] == 0)
				matrix[i][j] = 0;
		}
	}
	for (j = 0; j < matrix[0].size(); ++j)
	{
		if (matrix[0][j] == 0)
			for (i = 1; i < matrix.size(); ++i)
				matrix[i][j] = 0;
	}
	if (flagrow || matrix[0][0] == 0)
		for (j = 0; j < matrix[0].size(); ++j)
			matrix[0][j] = 0;
	if (flagcol)
		for (i = 0; i < matrix.size(); ++i)
			matrix[i][0] = 0;
}

/*
 *
 *	73. ��������
 *
 *  	ִ����ʱ:		60 ms, ������ C++ �ύ�л�����81.45%���û�
 *  	�ڴ�����:		11.4 MB, ������ C++ �ύ�л�����68.41%���û�
 *
 */
void setZeroes(vector<vector<int>>& matrix)
{
	int i, j;
	vector<int> row(matrix.size(), 0), col(matrix[0].size(), 0);
	for (i = 0; i < matrix.size(); ++i)
	{
		for (j = 0; j < matrix[0].size(); ++j)
		{
			if (matrix[i][j] == 0)
				row[i] = col[j] = 1;
		}
	}
	for (i = 0; i < matrix.size(); ++i)
	{
		for (j = 0; j < matrix[0].size(); ++j)
		{
			if (row[i] || col[j])
				matrix[i][j] = 0;
		}
	}
}