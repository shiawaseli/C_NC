#include"game.h"

int main()
{
	int input = START;

	while (input)
	{
		Menu();
		printf("��ѡ����Ҫ���еĲ���:>");
		if (!scanf("%d", &input))
		{
			input = ERROR;
			getchar();
		}
		system("cls");

		switch(input)
		{
		case END:
			printf("��Ϸ������\n");
			break;
		case START:
			printf("��Ϸ��ʼ��\n");
			Play();
			break;
		default:
			printf("��������������ѡ��\n");
			break;
		}
	}

	system("pause");
	return 0;
}