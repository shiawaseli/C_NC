#include "Leetcode.h"

/*
 *
 *	119. ������� II
 *
 *  	ִ����ʱ:		8 ms, ������ C++ �ύ�л�����24.48%���û�
 *  	�ڴ�����:		8.4 MB, ������ C++ �ύ�л�����59.66%���û�
 *
 */
vector<int> getRow(int rowIndex)
{
	vector<int> res(rowIndex + 1, 0);
	res[0] = 1;
	for (int i = 1; i <= rowIndex; ++i)
	{
		for (int j = i; j > 0; --j)
			res[j] += res[j - 1];
	}
	return res;
}