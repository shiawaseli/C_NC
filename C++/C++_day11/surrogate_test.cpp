#include <iostream>
#include "surrogate.h"
using namespace std;
using namespace lb;

int main()
{
	AutoMobile x(364);
	int num_vehicles = 0;

	//Vehicle parking_port1[100]; // ���ɹ���1���������޷���������
	//parking_port1[num_vehicles++] = x; // 2������������ำֵֻ�ǶԻ�����ڵĳ�Ա��ֵ

	Vehicle *parking_port2[100]; // ��ͳ�Ľ���취���ṩһ����Ӳ㣬��ʹ�û����ָ��
	//parking_port2[num_vehicles++] = &x; // ��ʱ�������ָ��,���xһ��ʱ���û�˻����
	parking_port2[num_vehicles++] = new AutoMobile(x); //��ʱ�������x�ĸ���,x����Ƿ�����޹�;����Ҫע�⶯̬�ڴ�Ĺ���:
	//if (p != q)
	//{
	//	delete parking_port2[p];
	//	parking_port2[p] = parking_port2[q]; // ��������ָ��ָ��ͬһ���ڴ�,�ͷ�ʱ���������
	//}
	//if (p != q)
	//{
	//	delete parking_port2[p];
	//	parking_port2[p] = new Vehicle(parking_port2[q]); // ��ȷ��Ӧ��new�ĸ�����
	//}
	// Ӧ��ʹ���鸴�ƺ���copy()���������һ������,ע�⶯̬�ڴ�Ĺ���

	// ������: ʹ��һ������������ʾ�ش����ڴ����,����Vehicle������ʱ�󶨵�����
	// ÿ��Vehicle��������һ���̳���Vehicle��Ķ���ֻҪ�ô��������������󣬸ö���Ϳ϶�����
	// ���ƴ���ͻḴ�ƶ�Ӧ�Ķ��󣬶���������ֵҲ����ɾ���ɶ�����ٸ�ֵ�¶���
	VehicleSurrogate parking_port3[2];
	parking_port3[num_vehicles++] = x; // �ȼ���parking_port3[num_vehicles++] = VehicleSurrogate(x);
	// ������һ������x�ĸ���,����VehicleSurrogate����󶨵��ø���,Ȼ��������󸳸�parking_port3��һ��Ԫ��
	// ������parking_port3����ʱ,���еĸ�������������

	// ����
	RoadVehicle a(2356);
	a.start();
	cout << a.weight() << endl;

	AutoMobile b(25.5);
	b.start();
	cout << b.weight() << endl;

	Aircraft c(84);
	c.start();
	c.weight();
	c.fly();

	Helicopter d(73);
	d.start();
	d.weight();
	d.hover();

	return 0;
}