#include "Leetcode.h"

/*
 *
 *	917. ������ת��ĸ
 *
 *  	ִ����ʱ:		4 ms, ������ C++ �ύ�л�����65.08%���û�
 *  	�ڴ�����:		8.5 MB, ������ C++ �ύ�л�����5.19%���û�
 *
 */
string reverseOnlyLetters(string S)
{
	char tmp;
	int i = 0, j = S.size() - 1, k;
	while (i < j)
	{
		while (i < j && !(S[i] >= 'a' && S[i] <= 'z' || S[i] >= 'A' && S[i] <= 'Z'))
			++i;
		while (i < j && !(S[j] >= 'a' && S[j] <= 'z' || S[j] >= 'A' && S[j] <= 'Z'))
			--j;
		if (i < j)
		{
			tmp = S[i];
			S[i] = S[j];
			S[j] = tmp;
		}
		++i, --j;
	}
	return S;
}