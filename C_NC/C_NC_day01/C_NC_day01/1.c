#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//��ӡ100~200֮������� 
int main1()
{
	int num, i;
	for (num = 100; num <= 200; num++)
	{
		for (i = 2; i <= sqrt(num); i++)
		{
			//�������������������������
			if (num%i == 0)
			{
				break;
			}
		}
		//�ж��ڲ�ѭ���Ƿ���������
		if (i <= sqrt(num))
		{
			continue;
		}
		else
		{
			printf("%d\n", num);
		}
	}
	system("pause");
	return 0;
}