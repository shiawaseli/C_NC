#include<string>
#include"StackTP.h"

int main()
{
	using std::cout;
	using std::endl;
	using std::cin;
	StackTP<std::string> s;
	char ch;
	std::string str;

	while (1)
	{
		cout << "a: ���\tp:ɾ��\tq:�˳�\n";
		cout << "��ѡ��";
		cin >> ch;
		while (strchr("apq", ch) == NULL)
		{
			cin >> ch;
		}
		if (ch == 'q')
		{
			cout << "�˳���\n";
			break;
		}
		while (cin.get() != '\n');
		switch (ch)
		{
		case 'a':
			cout << "�������ַ�����";
			cin >> str;
			if (!s.Push(str))
			{
				cout << "������\n";
			}
			break;
		case 'p':
			if (s.Pop(str))
			{
				cout << "# " << str << endl;
			}
			else
			{
				cout << "Ϊ�գ�\n";
			}
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}