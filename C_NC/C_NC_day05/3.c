#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main3()
{
	int i;
	char input[20];

	for (i = 3; i > 0; i--)
	{
		printf("����������:>");
		scanf("%s", input);
		if (strcmp(input, "123456") == 0)
		{
			printf("������ȷ��\n");
			break;
		}
		else
		{
			printf("����������������룡(����%d��)\n", i-1);
		}
	}
	if (i == 0)
	{
		printf("����ȫ�������˳�ϵͳ����\n");
	}

	system("pause");
	return 0;
}