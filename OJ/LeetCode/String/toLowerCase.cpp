#include "Leetcode.h"

/*
 *
 *	709. ת����Сд��ĸ
 *
 *  	ִ����ʱ:		0 ms, ������ C++ �ύ�л�����100.00%���û�
 *  	�ڴ�����:		8.4 MB, ������ C++ �ύ�л�����5.44%���û�
 *
 */
string toLowerCase(string str)
{
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] - 'A' + 'a';
	}
	return str;
}