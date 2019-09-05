#include<string>
#include<ctime>
#include"ArrayTP.h"
#include"StackTP.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

void Test1();
void Test2();
void ArrayTPHelp();

int main()
{
	char choice;

	while (1)
	{
		cout << "1: ����1\t2: ����2\t3: ģ��˵��\tq: �˳�\n";
		cout << "��ѡ��";
		cin >> choice;
		while (strchr("123q", choice) == NULL)
		{
			cin >> choice;
		}
		if (choice == 'q')
		{
			break;
		}
		while (cin.get() != '\n');
		switch (choice)
		{
		case '1':
			Test1();
			break;
		case '2':
			Test2();
			break;
		case '3':
			ArrayTPHelp();
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}

void Test1()
{
	char ch;
	string str;
	StackTP<string> s;

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
}

void Test2()
{
	const int NUM = 10;
	std::srand(unsigned(std::time(NULL)));
	cout << "������Ҫ����ջ��������";
	int capacity;
	while (!(cin >> capacity));
	StackTP<const char*> s(capacity);

	const char* input[NUM] = { "1  haha", "2  heihei", "3  hehe", "4  keek", "5  haia",
		"6  keai", "7  iaae", "8  fiau", "9  funa", "10 kese" };
	const char* output[NUM];
	int in = 0, out = 0;

	while (out < NUM)
	{
		if (s.IsEmpty())
		{
			s.Push(input[in++]);
		}
		else if (s.IsFull())
		{
			s.Pop(output[out++]);
		}
		else if (in < NUM && std::rand() % 2)
		{
			s.Push(input[in++]);
		}
		else
		{
			s.Pop(output[out++]);
		}
	}
	for (int i = 0; i < NUM; i++)
	{
		cout << "# " << output[i] << endl;
	}
}

void ArrayTPHelp()
{
	cout << endl;
	cout << "ArrayTP<double, Size1> arr1;\n"
		<< "ArrayTP<double, Size2> arr2;\n"
		<< "ע��arr1 �� arr2 �����ֲ�ͬ����\n\n";

	cout << "ArrayTP< StackTP<int> > arr3;\n"
		<< "1�������Ͳ���������Ĭ�ϲ���\n"
		<< "2�����Ͳ���Ҳ������ģ���ൣ��\n"
		<< "3��ע��ʹ��ģ������Ϊ���Ͳ���ʱ����Ҫ�� ' ' ������ '>' �ָ�����"
		<< "������ \">>\"\n\n";
	
	cout << "ArrayTP< ArrayTP<int, Size1>, Size2 > arr4; \n"
		<< "1��ģ����ĵݹ�ʹ��\n"
		<< "2���ȼ��� int arr4[Size2][Size1];\n\n";

	cout << "ʵ������\n"
		<< "��ʽʵ������ֻ����ʵ��ʹ����ʱ�Ż����ɽ�����ʽʵ����������������ָ��ʱ���������̽���ʵ����\n\n"
		<< "��ʽʵ������template class ArrayTP<double, 10>;\n"
		<< "\t\tͬʱ�����������Ͷ���"
		<< "��ʽ���廯��template <> class ArrayTP<double, 10> {} \n\t\t�����滻ģ���е�ͨ������\n\n"
		<< "���־��廯������� template <class T1, class T2> class A {} \n"
		<< "\t\t��ô������ template <class T1> class A<T1, int> {} ���в��־��廯\n\n";
}