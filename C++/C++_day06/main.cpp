#include <iostream>
#include <cstdlib>
#include "BadClass.h"

using namespace std;

enum
{
	CASE1,
	CASE2,
	CASE3,
	CASE4,
	CASE5,
};
#define SET CASE5

int main()
{
	int set = SET;
	double x, y, z;
	Demo d1("���� main()");

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
		case CASE4:
			try
			{
				z = hmean4(x, y);
				cout << x << "��" << y << "�ĵ���ƽ����Ϊ��" << z << endl;
				cout << x << "��" << y << "�ļ���ƽ����Ϊ��" << gmean4(x, y) << endl;
			}
			catch (bad_hmean& bg)
			{
				bg.mesg();
			}
			catch (bad_gmean& hg)
			{
				cout << hg.mesg();
				cout << "(x = " << x << ", y = " << y << ")" << endl;
			}
			break;
		case CASE5:
			try
			{
				z = means5(x, y);
				cout << "means5(" << x << ", " << y << ")��" << z << endl;
			}
			catch (bad_hmean& bg)
			{
				bg.mesg();
				cout << "�����������µ�����";
				continue;
			}
			catch (bad_gmean& hg)
			{
				cout << "(x = " << x << ", y = " << y << ")" << endl;
				cout << hg.mesg();
				cout << "�����������µ�����";
				continue;
			}
			d1.Show();
			break;
		default:
			break;
		}
		
		cout << "�����������µ�����";
	}
	system("pause");
	return 0;
}
