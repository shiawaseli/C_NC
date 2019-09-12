#pragma once

#include <iostream>
#include <string>

class bad_hmean
{
private:
	double m_v1;
	double m_v2;
public:
	bad_hmean(double a, double b) : m_v1(a), m_v2(b) {}
	void mesg() { std::cout << "hmean(" << m_v1 << ", " << m_v2 << "): " << "����a = -b!!\n"; }
};


class bad_gmean
{
public:
	double m_v1;
	double m_v2;
	bad_gmean(double a, double b) : m_v1(a), m_v2(b) {}
	const char* mesg() { return "gmean() �����������Ǹ�����\n"; }
};


class Demo
{
private:
	std::string m_str;
public:
	Demo(const std::string& str) : m_str(str) { std::cout << "���� demo " << m_str << std::endl; }
	~Demo() { std::cout << "���� demo " << m_str << std::endl; }
	void Show() { std::cout << "��ʾ demo " << m_str << std::endl; }
};



// case1
double hmean1(double a, double b);
// case2
bool hmean2(double a, double b, double* ans);
// case3
double hmean3(double a, double b);
// case4
#pragma warning (disable:4290)
double hmean4(double a, double b) throw(bad_hmean);
double gmean4(double a, double b) throw(bad_gmean);
double means5(double a, double b) throw(bad_hmean, bad_gmean);
