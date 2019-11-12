#include "Leetcode.h"

/*
 *
 *	89. ���ױ���
 *
 *  	ִ����ʱ:		20 ms, ������ C++ �ύ�л�����9.09%���û�
 *  	�ڴ�����:		8.6 MB, ������ C++ �ύ�л�����40.68%���û�
 *
 */
vector<int> grayCode(int n)
{
	int i, j, k, tmp, num = 0, size = pow(2, n);
	vector<int> res;
	res.push_back(0);
	for (i = 1; i < size; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			tmp = num ^ (1 << j);
			for (k = 0; k < i; ++k)
			{
				if (res[k] == tmp)
					break;
			}
			if (k >= i)
			{
				num = tmp;
				res.push_back(num);
				break;
			}
		}
	}
	return res;
}