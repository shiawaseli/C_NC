#include "Leetcode.h"

/*
 *
 *	204. ��������
 *
 *  	ִ����ʱ :		96 ms, ������ C++ �ύ�л�����60.69%���û�
 *  	�ڴ����� :		8.6 MB, ������ C++ �ύ�л�����67.83%���û�
 *
 */
int countPrimes(int n)
{
	if (n <= 2)
		return 0;
	int i, j, cnt = 0;
	vector<bool> book(n + 1, true);
	book[0] = book[1] = 0;
	for (i = 2; i < n; ++i)
	{
		if (book[i])
		{
			++cnt;
			for (j = 2; i * j <= n; ++j)
			{
				book[i * j] = false;
			}
		}
	}
	return cnt;
}