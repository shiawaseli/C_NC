#include "Leetcode.h"

/*
 *
 *	258. ��λ���
 *
 *  	ִ����ʱ:		4 ms, ������ C++ �ύ�л�����78.69%���û�
 *  	�ڴ�����:		8.2 MB, ������ C++ �ύ�л�����23.20%���û�
 *
 */
int addDigits(int num)
{
	int tmp = 0;
	while (num > 9)
	{
		tmp += num % 10;
		num /= 10;
		if (num < 10)
		{
			tmp += num;
			num = tmp;
			tmp = 0;
		}
	}
	return num;
}