#include "Leetcode.h"

/*
 *
 *	977. ���������ƽ��
 *
 *  	ִ����ʱ:		56 ms, ������ C++ �ύ�л�����86.28%���û�
 *  	�ڴ�����:		17.4 MB, ������ C++ �ύ�л�����5.08%���û�
 *
 */
vector<int> sortedSquares(vector<int>& A)
{
	vector<int> ret;
	for (int i = 0; i < A.size(); ++i)
		ret.push_back(A[i] * A[i]);
	sort(ret.begin(), ret.end());
	return ret;
}