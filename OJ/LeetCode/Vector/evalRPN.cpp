#include "Leetcode.h"

/*
 *
 *	150. �沨�����ʽ��ֵ
 *
 *  	ִ����ʱ:		16 ms, ������ C++ �ύ�л�����74.96%���û�
 *  	�ڴ�����:		13.2 MB, ������ C++ �ύ�л�����5.03%���û�
 *
 */
int evalRPN(vector<string>& tokens)
{
	int op1, op2, ret = 0;
	string tmp = tokens[tokens.size() - 1];
	if (tmp != "+" && tmp != "-" && tmp != "*" && tmp != "/")
		return atoi(tmp.c_str());
	else
	{
		tokens.pop_back();
		op2 = evalRPN(tokens);
		tokens.pop_back();
		op1 = evalRPN(tokens);
	}
	if (tmp == "+")
		return op1 + op2;
	else if (tmp == "-")
		return op1 - op2;
	else if (tmp == "*")
		return op1 * op2;
	else
		return op1 / op2;
}