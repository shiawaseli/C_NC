#include "Leetcode.h"

/*
 *
 *	88. �ϲ�������������
 *
 *  	ִ����ʱ :		4 ms, ������ C++ �ύ�л�����97.31%���û�
 *  	�ڴ����� :		8.6 MB, ������ C++ �ύ�л�����92.46%���û�
 *
 */
void merge_88(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	int i = 0, j = 0;
	vector<int> res(m + n);
	while (i < m && j < n)
	{
		if (nums1[i] < nums2[j])
		{
			res[i + j] = nums1[i];
			++i;
		}
		else
		{
			res[i + j] = nums2[j];
			++j;
		}
	}
	while (i < m)
	{
		res[i + j] = nums1[i];
		++i;
	}
	while (j < n)
	{
		res[i + j] = nums2[j];
		++j;
	}
	nums1 = res;
}

void merge_88(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	return merge_88(nums1, m, nums2, n);
}