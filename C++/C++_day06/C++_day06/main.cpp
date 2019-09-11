#include <iostream>
#include <cstdlib>

using namespace std;

#define CASE1 1
#define CASE2 2
#define CASE3 3
#define SET CASE1

double hmean1(double a, double b);
bool hmean2(double a, double b, double* ans);
double hmean3(double a, double b);

int main()
{
	int set = CASE3;
	double x, y, z;

	cout << "��������������";
	while (cin >> x >> y)
	{
		switch (set)
		{
		case CASE1:
			z = hmean1(x, y);
			cout << x << "��" << y << "�ĵ���ƽ����Ϊ��" << z << endl;
			break;
		case CASE2:
			if (hmean2(x, y, &z))
			{
				cout << x << "��" << y << "�ĵ���ƽ����Ϊ��" << z << endl;
			}
			else
			{
				cout << "�������������෴�����������ƽ���������⣡\n";
			}
			break;
		case CASE3:
			try
			{
				z = hmean3(x, y);
			}
			catch (const char *err)
			{
				cout << err << "�����������µ�����";
				continue;
			}
			cout << x << "��" << y << "�ĵ���ƽ����Ϊ��" << z << endl;
			break;
		default:
			break;
		}
		
		cout << "�����������µ�����";
	}
	system("pause");
	return 0;
}

double hmean1(double a, double b)
{
	if (a == -b)
	{
		cout << "�������������෴�����������ƽ���������⣡\n";
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