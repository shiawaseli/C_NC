#include "Leetcode.h"

/*
 *
 *	263. ����
 *
 *  	ִ����ʱ:		0 ms, ������ C++ �ύ�л�����100.00%���û�
 *  	�ڴ�����:		8.1 MB, ������ C++ �ύ�л�����18.02%���û�
 *
 */
bool isUgly(int num)
{
	while (num)
	{
		if (num % 2 == 0)
			num /= 2;
		else if (num % 3 == 0)
			num /= 3;
		else if (num % 5 == 0)
			num /= 5;
		else
			break;
	}
	return num == 1;
}