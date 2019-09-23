#include "Leetcode.h"

/*
 *
 *	4. Ѱ�����������������λ��
 *
 *  	ִ����ʱ:		32 ms, ������ C++ �ύ�л�����48.78%���û�
 *  	�ڴ�����:		10 MB, ������ C++ �ύ�л�����79.98%���û�
 *
 */
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	vector<int> t;
	int i = 0, j = 0, size = nums1.size() + nums2.size();
	while (i + j <= size / 2)
	{
		if (j >= nums2.size() || i < nums1.size() && nums1[i] < nums2[j])
		{
			t.push_back(nums1[i++]);
		}
		else
		{
			t.push_back(nums2[j++]);
		}
	}
	if (size % 2)
	{
		return t[size / 2];
	}
	else
	{
		return (t[size / 2 - 1] + t[size / 2]) / 2.0;
	}
}
