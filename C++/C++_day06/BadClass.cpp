#include "BadClass.h"

double hmean1(double a, double b)
{
	if (a == -b)
	{
		std::cout << "�������������෴�����������ƽ���������⣡\n";
		abort();
	}
	return 2.0 * a * b / (a + b);
}

bool hmean2(double a, double b, double* ans)
{
	if (a == -b)
	{
		*ans = DBL_MAX;
		return false;
	}
	*ans = 2.0 * a * b / (a + b);
	return true;
}

double hmean3(double a, double b)
{
	if (a == -b)
	{
		throw "�������������෴�����������ƽ���������⣡\n";
	}
	return 2.0 * a * b / (a + b);
}

double hmean4(double a, double b) throw(bad_hmean)
{
	if (a == -b)
	{
		throw bad_hmean(a, b);
	}
	return 2.0 * a * b / (a + b);
}

double gmean4(double a, double b) throw(bad_gmean)
{
	if (a < 0 || b < 0)
	{
		throw bad_gmean(a, b);
	}
	return sqrt(a * b);
}

double means5(double a, double b) throw(bad_hmean, bad_gmean)
{
	double am, hm, gm;
	Demo d2("���� means5()");
	am = (a + b) / 2.0;
	try
	{
		hm = hmean4(a, b);
		gm = gmean4(a, b);
	}
	catch (bad_hmean& bg)
	{
		bg.mesg();
		throw;
	}
	d2.Show();
	return (am + hm + gm) / 3.0;
}