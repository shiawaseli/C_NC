#include "Leetcode.h"

/*
 *
 *	121. ������Ʊ�����ʱ��
 *
 *  	ִ����ʱ:		852 ms, ������ C++ �ύ�л�����18.03%���û�
 *  	�ڴ�����:		9.6 MB, ������ C++ �ύ�л�����8.93%���û�
 *
 */
int maxProfit1(vector<int>& prices)
{
	int i, j, tmp, max = 0;
	for (i = 0; i < prices.size(); ++i)
	{
		tmp = prices[i];
		for (j = i + 1; j < prices.size(); ++j)
		{
			if (prices[j] - prices[i] > max)
			{
				max = prices[j] - prices[i];
			}
		}
	}
	return max;
}

/*
 *
 *	121. ������Ʊ�����ʱ��
 *
 *  	ִ����ʱ:		4 ms, ������ C++ �ύ�л�����98.35%���û�
 *  	�ڴ�����:		9.3 MB, ������ C++ �ύ�л�����89.85%���û�
 *
 */
int maxProfit2(vector<int>& prices)
{
	int i, before, max = 0;
	if (!prices.empty())
	{
		before = prices[0];
		for (i = 1; i < prices.size(); ++i)
		{
			if (prices[i] - before > max)
				max = prices[i] - before;
			else if (prices[i] < before)
				before = prices[i];
		}
	}
	return max;
}

int maxProfit(vector<int>& prices)
{
	return maxProfit2(prices);
}