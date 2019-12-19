#include "Leetcode.h"

/*
 *
 *	190. �ߵ�������λ
 *
 *  	ִ����ʱ:		4 ms, ������ C++ �ύ�л�����88.77%���û�
 *  	�ڴ�����:		8.1 MB, ������ C++ �ύ�л�����15.06%���û�
 *
 */
uint32_t reverseBits(uint32_t n)
{
	uint32_t res = 0;
	for (int i = 0; i < 32; ++i)
	{
		if ((1 << i) & n)
			res |= (1 << (31 - i));
	}
	return res;
}