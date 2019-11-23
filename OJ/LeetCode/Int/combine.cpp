#include "Leetcode.h"

/*
 *
 *	77. ���
 *
 *  	ִ����ʱ:		616 ms, ������ C++ �ύ�л�����16.24%���û�
 *  	�ڴ�����:		166.7 MB, ������ C++ �ύ�л�����19.21%���û�
 *
 */
void subCombine(vector<int> arr, int pos, int n, int k, vector< vector<int> >& ans)
{
	if (k == arr.size())
	{
		ans.push_back(arr);
		return;
	}
	for (int i = pos; i <= n; ++i)
	{
		arr.push_back(i);
		subCombine(arr, i + 1, n, k, ans);
		arr.pop_back();
	}
}
vector< vector<int> > combine(int n, int k)
{
	vector<int> arr;
	vector< vector<int> > res;
	subCombine(arr, 1, n, k, res);
	return res;
}