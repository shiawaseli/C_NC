#include "handle_1.h"
#include <iostream>
using namespace std;
using namespace lb;

int main()
{
	PointHandle ph;
	cout << ph.count() << " ";
	ph.show();
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

	return 0;
}