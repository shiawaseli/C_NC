#include "Leetcode.h"

/*
 *
 *	97. �����ַ���
 *
 *  	ִ����ʱ:		176 ms, ������ C++ �ύ�л�����5.10%���û�
 *  	�ڴ�����:		120 MB, ������ C++ �ύ�л�����5.26%���û�
 *		��һ�����ӳ����Ӵ���Ϊ�ݹ��������ͨ������
 *		"bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa"
 *		"babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab"
 *		"babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab"
 *
 */
bool isInterleave(string s1, string s2, string s3)
{
	int i, j, k;
	for (i = j = k = 0; i < s1.size() && j < s2.size() && s1[i] != s2[j]; ++k)
	{
		if (s1[i] == s3[k])
			++i;
		else if (s2[j] == s3[k])
			++j;
		else
			return false;
	}
	if (i == s1.size())
		return s2.substr(j) == s3.substr(k);
	else if (j == s2.size())
		return s1.substr(i) == s3.substr(k);
	if (s1[i] == s2[j] && s1[i] != s3[k])
		return false;
	return isInterleave(s1.substr(i + 1), s2.substr(j), s3.substr(k + 1)) || isInterleave(s1.substr(i), s2.substr(j + 1), s3.substr(k + 1));
}