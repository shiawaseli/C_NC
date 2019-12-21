#include "Leetcode.h"

/*
 *
 *	202. ������
 *
 *  	ִ����ʱ:		4 ms, ������ C++ �ύ�л�����77.15%���û�
 *  	�ڴ�����:		8.2 MB, ������ C++ �ύ�л�����55.61%���û�
 *
 */
bool isHappy(int n)
{
	int tmp = n, sum = 0;
	vector<int> book;
	sum = (tmp % 10) * (tmp % 10);
	tmp /= 10;
	while (tmp != 0 || find(book.begin(), book.end(), sum) == book.end())
	{
		if (tmp == 0)
		{
			if (sum == 1)
				return true;
			book.push_back(sum);
			tmp = sum;
			sum = 0;
		}
		sum += (tmp % 10) * (tmp % 10);
		tmp /= 10;
	}
	return false;
}