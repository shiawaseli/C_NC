#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

int main1()
{
	int num[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int i, tmp;

	for (i = 0; i + 1 < SIZE; i++)
	{
		if (num[i] % 2 == 0 && num[i + 1] % 2 == 1)
		{
			tmp = num[i];
			num[i] = num[i + 1];
			num[i + 1] = tmp;
			if (i > 0)//只要当前不是首元素，就向前移动两位，随后i++又向右移动一位，即再次检验前一位是否需要后移
			{
				i = i - 2;
			}
		}
	}
	for (i = 0; i < SIZE; i++)
	{
		printf("%d ", num[i]);
	}
	putchar('\n');

	system("pause");
	return 0;
}
