#include"Student.h"
#include"StudentPrivate.h"

using std::endl;
using std::cout;
using std::cin;

void Set(Student & s, int n);
void Set(StudentPrivate & s, int n);

const int pupils = 3;
const int quizzes = 5;

void TestStudent()
{
	Student stu[pupils] = { Student(quizzes), Student(quizzes), Student(quizzes) };

	int i;
	for (i = 0; i < pupils; ++i)
	{
		Set(stu[i], quizzes);
	}
	cout << "ѧ���б�:\n";
	for (i = 0; i < pupils; i++)
	{
		cout << stu[i].Name() << endl;
	}
	cout << "�ɼ��б�:\n";
	for (i = 0; i < pupils; i++)
	{
		cout << stu[i];
		cout << "ƽ���֣�" << stu[i].Average() << endl;
	}
}

void TestStudentPrivate()
{
	StudentPrivate stu[pupils] = { StudentPrivate(quizzes), StudentPrivate(quizzes), StudentPrivate(quizzes) };

	int i;
	for (i = 0; i < pupils; ++i)
	{
		Set(stu[i], quizzes);
	}
	cout << "ѧ���б�:\n";
	for (i = 0; i < pupils; i++)
	{
		cout << stu[i].Name() << endl;
	}
	cout << "�ɼ��б�:\n";
	for (i = 0; i < pupils; i++)
	{
		cout << stu[i];
		cout << "ƽ���֣�" << stu[i].Average() << endl;
	}
}

int main()
{
	TestStudentPrivate();

	system("pause");
	return 0;
}

void Set(Student & s, int n)
{
	cout << "������ѧ����������";
	getline(cin, s);
	cout << "������" << n << "���ɼ���";
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	while (cin.get() != '\n');
}

void Set(StudentPrivate & s, int n)
{
	cout << "������ѧ����������";
	getline(cin, s);
	cout << "������" << n << "���ɼ���";
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	while (cin.get() != '\n');
}