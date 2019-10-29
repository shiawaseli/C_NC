#include "Leetcode.h"

/*
 *
 *	74. ������ά����
 *
 *  	ִ����ʱ:		4 ms, ������ C++ �ύ�л�����99.44%���û�
 *  	�ڴ�����:		9.7 MB, ������ C++ �ύ�л�����92.57%���û�
 *
 */
bool searchMatrix(vector< vector<int> >& matrix, int target)
{
	if (matrix.size() == 0 || matrix[0].size() == 0)
		return false;
	int i = 0, j = 0, m = matrix.size(), n = matrix[0].size();
	while (i < m && j < n)
	{
		if (i + 1 < m && matrix[i + 1][j] <= target)
			++i;
		else if (matrix[i][j] < target)
			++j;
		else if (matrix[i][j] == target)
			return true;
		else
			break;
	}
	return false;
}