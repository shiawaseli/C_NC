#include "Leetcode.h"

/*
 *
 *	905. ����ż��������
 *
 *  	ִ����ʱ:		20 ms, ������ C++ �ύ�л�����76.80%���û�
 *  	�ڴ�����:		10.7 MB, ������ C++ �ύ�л�����5.02%���û�
 *
 */
vector<int> sortArrayByParity(vector<int>& A)
{
	vector<int> ret(A);
	int i = 0, j = A.size() - 1, tmp;
	while (i < j)
	{
		while (i < j && ret[i] % 2 == 0)
			++i;
		while (i < j && ret[j] % 2)
			--j;
		if (i < j)
		{
			tmp = ret[i];
			ret[i++] = ret[j];
			ret[j--] = tmp;
		}
	}
	return ret;
}