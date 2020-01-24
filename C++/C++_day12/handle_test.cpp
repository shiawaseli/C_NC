#include "handle.h"
#include <iostream>
using namespace std;
using namespace lb;

void test1()
{
	PointHandle ph;
	cout << ph.count() << " " << ph << endl;
	ph.x(25);
	ph.y(52);

	PointHandle ph2 = ph, ph3(ph2);
	PointHandle ph4(33, 6);
	ph3 = ph4;
	cout << ph.count() << " ";
	ph.show();

	Point p1(89, 67);
	PointHandle ph5(p1);
	ph4 = ph5;
	ph4.x(100); // дʱ����,�޸�ʱ���п���
	//ph4 = PointHandle(100, ph5.y()); // ����������ָ������ʱ��дʱ����
}

void test2()
{
	PointHandle2 ph;
	cout << ph.count() << " " << ph << endl;
	ph.x(25);
	ph.y(52);

	PointHandle2 ph2 = ph, ph3(ph2);
	PointHandle2 ph4(33, 6);
	ph3 = ph4;
	cout << ph.count() << " ";
	ph.show();

	Point p1(89, 67);
	PointHandle2 ph5(p1);
	ph4 = ph5;
	ph4.x(100);
}

int main()
{
	test1();
	test2();
	return 0;
}