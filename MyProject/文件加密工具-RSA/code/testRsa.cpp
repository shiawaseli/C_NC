#include "rsa.h"
#include "BigInt.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
using namespace lb;

// ����һ����Կ
int test1()
{
	Rsa rsa;
	RsaKey key = rsa.getRsaKey();
	rsa.show();

	ofstream fileout;
	fileout.open("D:/WorkFile/����/�ļ����ܹ���-RSA/�ļ����ܹ���-RSA/rsa.txt");
	fileout << key.m_eKey << ' ' << key.m_dKey << ' ' << key.m_pKey << endl;
	fileout.close();

	rsaDataType data = 2;
	rsaDataType num1 = rsa.ecrept(data);
	rsaDataType num2 = rsa.decrept(num1);

	while (cin >> data)
	{
		cout << "data: " << data << endl;

		num1 = rsa.ecrept(data);
		cout << "ecrept: " << num1 << endl;

		num2 = rsa.decrept(num1);
		cout << "decrept: " << num2 << endl;
	}

	return 0;
}

// ������Կ����
int test2()
{
	wifstream filein;
	filein.open("./rsa.txt");

	RsaKey key;
	filein >> key.m_eKey >> key.m_dKey >> key.m_pKey;
	Rsa rsa(key);

	cout << "����: " << endl;
	string filename("D:/WorkFile/����/�ļ����ܹ���-RSA/�ļ����ܹ���-RSA/signal.txt");
	string filename2(filename);
	if (filename2.rfind("/") < filename2.size())
		filename2.insert(filename2.rfind("/") + 1, "e_");
	else
		filename2.insert(0, "e_");
	cout << filename << endl;
	cout << filename2 << endl;
	rsa.ecreptFile(filename, filename2);

	cout << "����: " << endl;
	string filename3(filename2);
	if (filename3.rfind("/e_") < filename3.size())
		filename3[filename3.rfind("/e_") + 1] = 'd';
	else if (filename3.rfind("/") < filename3.size())
		filename3.insert(filename3.rfind("/") + 1, "d_");
	else if (filename3.find("e_") < filename3.size())
		filename3[filename3.find("e_")] = 'd';
	else
		filename3.insert(0, "d_");
	cout << filename2 << endl;
	cout << filename3 << endl;
	rsa.decreptFile(filename2, filename3);

	return 0;
}

// ��Ҫ����
int main()
{
	int flag = 1, input;
	string filename, filename2;
	ifstream filein;
	ofstream fileout;

	RsaKey key;
	filein.open("D:/WorkFile/����/�ļ����ܹ���-RSA/�ļ����ܹ���-RSA/rsa.txt");
	filein >> key.m_eKey >> key.m_dKey >> key.m_pKey;
	Rsa rsa(key);

	while (flag)
	{
		cout << "������Ҫ���еĲ���(1.���� 2.���� 0.�˳�): " << endl;
		cin >> input;
		cin.get(); // ��������Ļ��з�
		switch (input)
		{
		case 0:
			flag = 0;
			break;
		case 1:
			cout << "������Ҫ���м��ܵ��ļ���: " << endl;
			getline(cin, filename);

			filename2 = filename; // �Զ���ü��ܺ���ļ���
			if (filename2.rfind("/") < filename2.size())
				filename2.insert(filename2.rfind("/") + 1, "e_");
			else
				filename2.insert(0, "e_");

			if (rsa.ecreptFile(filename, filename2)) // ����
				cout << "���ܳɹ�! ���ܺ���ļ���Ϊ " << filename2 << endl;
			break;
		case 2:
			cout << "������Ҫ���н��ܵ��ļ���(��e_��ͷ): " << endl;
			getline(cin, filename);

			filename2 = filename; // �Զ���ý��ܺ���ļ���
			if (filename2.rfind("/e_") < filename2.size())
				filename2[filename2.rfind("/e_") + 1] = 'd';
			else if (filename2.rfind("/") < filename2.size())
				filename2.insert(filename2.rfind("/") + 1, "d_");
			else if (filename2.find("e_") < filename2.size())
				filename2[filename2.find("e_")] = 'd';
			else
				filename2.insert(0, "d_");

			if (rsa.decreptFile(filename, filename2)) // ����
				cout << "���ܳɹ�! ���ܺ���ļ���Ϊ " << filename2 << endl;
			break;
		default:
			break;
		}
	}

	return 0;
}