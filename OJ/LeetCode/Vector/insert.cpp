#include "Leetcode.h"

/*
 *
 *	57. ��������
 *
 *  	ִ����ʱ:		1332 ms, ������ C++ �ύ�л�����6.04%���û�
 *  	�ڴ�����:		12.5 MB, ������ C++ �ύ�л�����5.23%���û�
 *
 */
vector< vector<int> > insert(vector< vector<int> >& intervals, vector<int>& newInterval)
{
	if (intervals.size() < 1 || newInterval[0] > intervals[intervals.size() - 1][1])
	{
		intervals.push_back(newInterval);
		return intervals;
	}
	else if (intervals[0][0] > newInterval[1])
	{
		intervals.insert(intervals.begin(), newInterval);
		return intervals;
	}
	if (intervals[0][0] == newInterval[1])
	{
		intervals[0][0] = newInterval[0];
		return intervals;
	}
	intervals[0][0] = min(intervals[0][0], newInterval[0]);
	for (int i = 0; i < intervals.size(); ++i)
	{
		if (newInterval[0] <= intervals[i][1])
		{
			intervals[i][0] = min(intervals[i][0], newInterval[0]);
			intervals[i][1] = max(intervals[i][1], newInterval[1]);
			while (i + 1 < intervals.size() && intervals[i][1] >= intervals[i + 1][0])
			{
				intervals[i][1] = max(intervals[i][1], intervals[i + 1][1]);
				intervals.erase(intervals.begin() + i + 1);
			}
			break;
		}
		if (newInterval[0] > intervals[i][1] && newInterval[1] < intervals[i + 1][0])
		{
			intervals.insert(intervals.begin() + i + 1, newInterval);
			break;
		}
	}
	return intervals;
}