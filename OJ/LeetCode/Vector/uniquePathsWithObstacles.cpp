#include "Leetcode.h"

/*
 *
 *	63. ��ͬ·�� II
 *
 *  	ִ����ʱ:		8 ms, ������ C++ �ύ�л�����58.87%���û�
 *  	�ڴ�����:		9.1 MB, ������ C++ �ύ�л�����69.25%���û�
 *
 */
int uniquePathsWithObstacles1(vector< vector<int> >& obstacleGrid)
{
	if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0 ||
		obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1] == 1 ||
		obstacleGrid[0][0] == 1)
		return 0;
	signed long tmp;
	int i, j, row = obstacleGrid.size(), col = obstacleGrid[0].size();
	obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1] = -1;
	for (i = row - 1; i >= 0; --i)
	{
		for (j = col - 1; j >= 0; --j)
		{
			if (obstacleGrid[i][j] != 1)
			{
				tmp = obstacleGrid[i][j];
				if (i != row - 1 && obstacleGrid[i + 1][j] < 0)
					tmp += obstacleGrid[i + 1][j];
				if (j != col - 1 && obstacleGrid[i][j + 1] < 0)
					tmp += obstacleGrid[i][j + 1];
				if (tmp > INT_MIN)
					obstacleGrid[i][j] = tmp;
			}
		}
	}
	return -obstacleGrid[0][0];
}

/*
 *
 *	63. ��ͬ·�� II
 *
 *  	ִ����ʱ:		8 ms, ������ C++ �ύ�л�����58.87%���û�
 *  	�ڴ�����:		9 MB, ������ C++ �ύ�л�����92.10%���û�
 *
 */
int uniquePathsWithObstacles2(vector< vector<int> >& obstacleGrid)
{
	long long dp[obstacleGrid[0].size()];
	for (int i = 0; i < obstacleGrid[0].size(); ++i)
		dp[i] = 0;
	dp[0] = 1;
	for (int i = 0; i < obstacleGrid.size(); ++i)
	{
		for (int j = 0; j < obstacleGrid[0].size(); ++j)
		{
			if (obstacleGrid[i][j])
				dp[j] = 0;
			else if (j)
				dp[j] += dp[j - 1];
		}
	}
	return dp[obstacleGrid[0].size() - 1];
}

int uniquePathsWithObstacles(vector< vector<int> >& obstacleGrid)
{
	return uniquePathsWithObstacles1(obstacleGrid);
}