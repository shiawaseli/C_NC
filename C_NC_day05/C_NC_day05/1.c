#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void menu()
{
	printf("************************************\n");
	printf("*******        0.end         *******\n");
	printf("*******        1.play        *******\n");
	printf("************************************\n");
}

void play()
{
	int target = 0;
	int guess = 0;

	target = rand() % 100 + 1;
	while (1)
	{
		printf("��������µ�����(1-100):>");
		scanf("%d", &guess);
		if (guess > target)
		{
			printf("�´��ˣ�\n\n");
		}
		else if (guess < target)
		{
			printf("��С�ˣ�\n\n");
		}
		else
		{
			printf("��ϲ�㣬�¶��ˣ���\n\n");
			break;
		}
	}
}

int main()
{
	int input;
	srand((unsigned int)time(NULL));

	do
	{
		menu();
		printf("���������ѡ��:>");
		scanf("%d", &input);

		switch (input)
		{
		case 0:
			printf("��Ϸ������\n");
			break;
		case 1:
			play();
			break;
		default:
			printf("ѡ��������������룡\n");
			break;
		}
	} while (input != 0);

	system("pause");
	return 0;
}