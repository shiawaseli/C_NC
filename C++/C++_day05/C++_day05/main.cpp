#include"Tv.h"

int main()
{
	using std::cout;
	using std::endl;

	Tv tv1;
	cout << "��ʼ���ã�" << endl;
	tv1.Settings();
	tv1.OnOff();
	tv1.ChannelUp();
	cout << "������" << endl;
	tv1.Settings();

	Remote grey;
	grey.ChannelUp(tv1);
	grey.ChannelUp(tv1);
	grey.SetChannel(tv1, 19);
	cout << "ң�ز�����" << endl;
	tv1.Settings();

	Tv tv2(Tv::On);
	tv2.SetMode();
	grey.SetChannel(tv2, 8);
	cout << "���ã�" << endl;
	tv2.Settings();

	system("pause");
	return 0;
}