#include"game.h"

int main()
{
	int input = -1;
	srand((unsigned int)time(NULL));
	while (input)
	{
		Menu();
		printf("��������Ҫ���еĲ���:>");
		if (!scanf("%d", &input))
		{
			getchar();
		}
		switch (input)
		{
		case 1:
			Play();
			break;
		case 0:
			printf("��Ϸ����\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	}

	return 0;
}