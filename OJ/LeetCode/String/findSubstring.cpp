#include "Leetcode.h"

/*
 *
 *	30. �������е��ʵ��Ӵ�
 *
 *  	ִ����ʱ:		1672 ms, ������ C++ �ύ�л�����5.97%���û�
 *  	�ڴ�����:		458.1 MB, ������ C++ �ύ�л�����5.20%���û�
 *
 */
vector<int> findSubstring(string s, vector<string>& words)
{
	vector<int> res;
	if (words.empty() || s.empty())
		return res;
	int i, j, wordSize = words[0].size(), wordsNum = words.size(), strSize = s.size();
	sort(words.begin(), words.end());
	for (i = 0; i <= strSize - wordSize * wordsNum; i++)
	{
		vector<string> tmpVec;
		for (j = 0; j < wordSize * wordsNum; j += wordSize)
		{
			tmpVec.push_back(s.substr(i + j, wordSize));
		}
		sort(tmpVec.begin(), tmpVec.end());
		if (tmpVec == words)
			res.push_back(i);
	}
	return res;
}