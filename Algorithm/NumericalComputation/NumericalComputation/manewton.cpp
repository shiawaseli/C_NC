#include "Func.h"

void manewton()
{
	int n;
	cout << "�����뷽�̵�����:> ";
	cin >> n;
	Func f, k;

	while (n--)
	{
		f.add();
	}
	f.show();
	Func m(f);
	f.derivative();
	f.show();
	k = f;
	k.show();
	m.show();
	m.add(k);
	m.show();
}
