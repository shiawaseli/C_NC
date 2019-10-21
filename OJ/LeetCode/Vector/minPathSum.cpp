#include "Leetcode.h"

/*
 *
 *	64. ��С·����
 *
 *  	ִ����ʱ:		12 ms, ������ C++ �ύ�л�����74.23%���û�
 *  	�ڴ�����:		10.4 MB, ������ C++ �ύ�л�����97.53%���û�
 *
 */
int minPathSum(vector< vector<int> >& grid)
{
	if (grid.size() == 0 || grid.size() == 1 && grid[0].size() == 0)
		return 0;
	int i, j, tmp;
	for (j = 1; j < grid[0].size(); ++j)
		grid[0][j] += grid[0][j - 1];
	for (i = 1; i < grid.size(); ++i)
	{
		for (j = 0; j < grid[0].size(); ++j)
		{
			if (j == 0)
				grid[i][j] += grid[i - 1][j];
			else
				grid[i][j] += (grid[i - 1][j] < grid[i][j - 1] ? grid[i - 1][j] : grid[i][j - 1]);
		}
	}
	return grid[grid.size() - 1][grid[0].size() - 1];
}