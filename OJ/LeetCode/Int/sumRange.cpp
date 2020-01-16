#include "Leetcode.h"

/*
 *
 *	303. ����ͼ��� - ���鲻�ɱ�
 *
 *  	ִ����ʱ:		232 ms, ������ C++ �ύ�л�����26.06%���û�
 *  	�ڴ�����:		17.3 MB, ������ C++ �ύ�л�����20.81%���û�
 *
 */
class NumArray {
private:
	vector<int> m_nums;
public:
	NumArray(vector<int>& nums)
	{
		m_nums = nums;
	}

	int sumRange(int i, int j)
	{
		int res = 0;
		while (i <= j)
			res += m_nums[i++];
		return res;
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */