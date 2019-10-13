#include "Leetcode.h"

/*
 *
 *	56. �ϲ�����
 *
 *  	ִ����ʱ:		24 ms, ������ C++ �ύ�л�����88.11%���û�
 *  	�ڴ�����:		12.4 MB, ������ C++ �ύ�л�����5.08%���û�
 *
 */
vector< vector<int> > merge1(vector< vector<int> >& intervals)
{
	if (intervals.size() < 2)
		return intervals;
	int i, cnt = 0;
	sort(intervals.begin(), intervals.end());
	for (i = 0; i < intervals.size(); ++i)
	{
		if (intervals[cnt][1] < intervals[i][0])
			intervals[++cnt] = intervals[i];
		else
			intervals[cnt][1] = intervals[cnt][1] > intervals[i][1] ? intervals[cnt][1] : intervals[i][1];
	}
	intervals.erase(intervals.begin() + cnt + 1, intervals.end());
	return intervals;
}

/*
 *
 *	56. �ϲ�����
 *
 *  	ִ����ʱ:		32 ms, ������ C++ �ύ�л�����61.86%���û�
 *  	�ڴ�����:		12.5 MB, ������ C++ �ύ�л�����5.08%���û�
 *
 */
vector< vector<int> > merge2(vector< vector<int> >& intervals)
{
	int i, j;
	vector< vector<int> > res;
	sort(intervals.begin(), intervals.end());
	for (i = 0; i < intervals.size(); i = j + 1)
	{
		vector<int> tmp;
		tmp.push_back(intervals[i][0]);
		for (j = i; j + 1 < intervals.size(); ++j)
		{
			if (intervals[j][1] < intervals[j + 1][0])
				break;
			else
				intervals[j + 1][1] = intervals[j][1] > intervals[j + 1][1] ? intervals[j][1] : intervals[j + 1][1];
		}
		tmp.push_back(intervals[j][1]);
		res.push_back(tmp);
	}
	return res;
}

vector< vector<int> > merge(vector< vector<int> >& intervals)
{
	return merge1(intervals);
}