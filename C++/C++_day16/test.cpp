#include "TextQuery.hpp"
using namespace std;
using namespace lb;

void runQueries(ifstream & fin)
{
	TextQuery test(fin); // �����ļ���������ѯmap
	string word;
	// ��ʾ�û����룬���в�ѯ�����
	while (true)
	{
		cout << "������Ҫ���ҵĵ���(q �˳�): ";
		if (!(cin >> word) || word == "q")
			break;
		QueryResult res = test.query(word);
		print(cout, res) << endl;
	}
}

int main()
{
	ifstream fin("input.txt");
	runQueries(fin);

	return 0;
}