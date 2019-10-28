#include "Leetcode.h"

/*
 *
 *	72. �༭����
 *
 *  	ִ����ʱ:		16 ms, ������ C++ �ύ�л�����78.20%���û�
 *  	�ڴ�����:		11.2 MB, ������ C++ �ύ�л�����40.95%���û�
 *
 */
int minDistance(string word1, string word2)
{
	int i, j, row = word1.size(), col = word2.size();
	vector< vector<int> > flag(row + 1, vector<int>(col + 1));
	for (i = 0; i <= row; ++i)
		flag[i][0] = i;
	for (i = 0; i <= col; ++i)
		flag[0][i] = i;
	for (i = 1; i <= row; ++i)
	{
		for (j = 1; j <= col; ++j)
		{
			if (word1[i - 1] == word2[j - 1])
				flag[i][j] = flag[i - 1][j - 1];
			else
				flag[i][j] = min(min(flag[i][j - 1], flag[i - 1][j]), flag[i - 1][j - 1]) + 1;
		}
	}
	return flag[row][col];
}