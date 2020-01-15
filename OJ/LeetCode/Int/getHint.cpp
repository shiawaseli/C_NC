#include "Leetcode.h"

/*
 *
 *	299. ��������Ϸ
 *
 *  	ִ����ʱ:		4 ms, ������ C++ �ύ�л�����95.27%���û�
 *  	�ڴ�����:		9.1 MB, ������ C++ �ύ�л�����5.30%���û�
 *
 */
string getHint(string secret, string guess)
{
	int i, cntA = 0, cntB = 0;
	char book1[10] = { 0 }, book2[10] = { 0 };
	for (i = 0; i < secret.size(); ++i)
	{
		if (secret[i] == guess[i])
			++cntA;
		else
		{
			++book1[secret[i] - '0'];
			++book2[guess[i] - '0'];
		}
	}
	for (i = 0; i < 10; ++i)
		cntB += min(book1[i], book2[i]);
	return to_string(cntA) + 'A' + to_string(cntB) + 'B';
}