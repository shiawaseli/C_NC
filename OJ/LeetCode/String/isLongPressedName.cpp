#include "Leetcode.h"

/*
 *
 *	925. ��������
 *
 *  	ִ����ʱ:		0 ms, ������ C++ �ύ�л�����39.23%���û�
 *  	�ڴ�����:		8.5 MB, ������ C++ �ύ�л�����40.94%���û�
 *
 */
bool isLongPressedName(string name, string typed)
{
	int i = 0, j = 0;
	while (i < name.size())
	{
		if (i < name.size() && j < typed.size() && name[i] == typed[j])
		{
			++i;
			++j;
		}
		else if (i - 1 >= 0 && j < typed.size() && name[i - 1] == typed[j])
			++j;
		else
			return false;
	}
	return true;
}