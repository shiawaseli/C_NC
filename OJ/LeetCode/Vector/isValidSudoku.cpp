#include "Leetcode.h"

/*
 *
 *	36. ��Ч������
 *
 *  	ִ����ʱ:		16 ms, ������ C++ �ύ�л�����87.65%���û�
 *  	�ڴ�����:		9.3 MB, ������ C++ �ύ�л�����96.04%���û�
 *
 */
int offSet[9][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };

bool isValidSudoku(vector< vector<char> >& board)
{
	int i, j, k;
	char book[10];
	for (i = 0; i < 9; ++i)
	{
		for (j = 0; j < 10; ++j)
			book[j] = 0;
		for (j = 0; j < 9; ++j)
		{
			if (board[i][j] == '.')
				continue;
			if (book[board[i][j] - '0'])
				return false;
			++book[board[i][j] - '0'];
		}
		for (j = 0; j < 10; ++j)
			book[j] = 0;
		for (j = 0; j < 9; ++j)
		{
			if (board[j][i] == '.')
				continue;
			if (book[board[j][i] - '0'])
				return false;
			++book[board[j][i] - '0'];
		}
	}
	for (j = 0; j < 10; ++j)
		book[j] = 0;
	for (i = 1, j = 1, k = 0; i < 9 && j < 9; ++k)
	{
		if (k == 9)
		{
			for (k = 0; k < 10; ++k)
				book[k] = 0;
			if (j == 7)
			{
				i += 3;
				j = 1;
			}
			else
				j += 3;
			k = -1;
			continue;
		}
		if (board[i + offSet[k][0]][j + offSet[k][1]] == '.')
			continue;
		if (book[board[i + offSet[k][0]][j + offSet[k][1]] - '0'])
			return false;
		++book[board[i + offSet[k][0]][j + offSet[k][1]] - '0'];
	}
	return true;
}