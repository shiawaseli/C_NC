#include<stdio.h>
#include<stdlib.h>
//�ж�1000��---2000��֮�������
int main()
{
	int year;
	for (year = 1000; year <= 2000; year += 4)
	{
		//�ܱ�100��400ͬʱ���������ҲΪ����
		if (year % 100 == 0 && year % 400 != 0)
		{
			continue;
		}
		printf("%d\n", year);
	}
	system("pause");
	return 0;
}