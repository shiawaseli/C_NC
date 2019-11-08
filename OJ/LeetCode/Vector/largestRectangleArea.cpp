#include "Leetcode.h"

/*
 *
 *	84. ��״ͼ�����ľ���
 *
 *  	ִ����ʱ :		520 ms, ������ C++ �ύ�л�����15.97%���û�
 *  	�ڴ����� :		9.7 MB, ������ C++ �ύ�л�����93.51%���û�
 *
 */
int largestRectangleArea(vector<int>& heights)
{
	int i = 0, res = 0, left = 0, right = 0;
	while (i < heights.size())
	{
		if (i - 1 >= 0 && heights[i] > heights[i - 1])
			left = right = i;
		while (left - 1 >= 0 && heights[i] <= heights[left - 1])
			--left;
		while (right + 1 < heights.size() && heights[i] <= heights[right + 1])
			++right;
		if (res < (right - left + 1) * heights[i])
			res = (right - left + 1) * heights[i];
		++i;
	}
	return res;
}