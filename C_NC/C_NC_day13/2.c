#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

#define N 3

int main()
{
	int i = 0, j = N - 1, value;
	int a[N][N] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

	scanf("%d", &value);
	while (i < N && j >= 0)
	{
		if (a[i][j] == value)
		{
			printf("�ҵ��ˣ���%d�У���%d��\n", i + 1, j + 1);
			break;
		}
		if (a[i][j] < value)
		{
			i++;
		}
		if (a[i][j] > value)
		{
			j--;
		}
	}
	if (i == N || j < 0)
	{
		printf("û�ҵ�\n");
	}

	system("pause");
	return 0;
}
