#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"Control.h"
#include"Show.h"

void (*welcome[3])() = { WelcomeStart, WelcomeSet, WelcomeExit };

void WelcomeStart()
{
	char page[1024] = { 0 };

	strcat(page, "������������������������������������\n");
	strcat(page, "��                                ��\n");
	strcat(page, "��                                ��\n");
	strcat(page, "������������ ɨ      �� ������������\n");
	strcat(page, "��                                ��\n");
	strcat(page, "��                                ��\n");
	strcat(page, "��                                ��\n");
	strcat(page, "������������ Game Start ������������\n");
	strcat(page, "������������  Game Set��������������\n");
	strcat(page, "��������������  Exit����������������\n");
	strcat(page, "��                                ��\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������ �����ѡ�񡡻س���ȷ��\n");
	strcat(page, "������������ ��ʼ��Ϸ\n");

	system("cls");
	puts(page);
}

void WelcomeSet()
{
	char page[1024] = { 0 };

	strcat(page, "������������������������������������\n");
	strcat(page, "��                                ��\n");
	strcat(page, "��                                ��\n");
	strcat(page, "������������ ɨ      �� ������������\n");
	strcat(page, "��                                ��\n");
	strcat(page, "��                                ��\n");
	strcat(page, "��                                ��\n");
	strcat(page, "����������   Game Start ������������\n");
	strcat(page, "������������  Game Set��������������\n");
	strcat(page, "����������  ��  Exit����������������\n");
	strcat(page, "��                                ��\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������ �����ѡ�񡡻س���ȷ��\n");
	strcat(page, "�������� �����õ�ͼ��С\n");

	system("cls");
	puts(page);
}

void WelcomeExit()
{
	char page[1024] = { 0 };

	strcat(page, "������������������������������������\n");
	strcat(page, "��                                ��\n");
	strcat(page, "��                                ��\n");
	strcat(page, "������������ ɨ      �� ������������\n");
	strcat(page, "��                                ��\n");
	strcat(page, "��                                ��\n");
	strcat(page, "��                                ��\n");
	strcat(page, "����������   Game Start ������������\n");
	strcat(page, "��������      Game Set��������������\n");
	strcat(page, "��������������  Exit����������������\n");
	strcat(page, "��                                ��\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������ �����ѡ�񡡻س���ȷ��\n");
	strcat(page, "������������ �˳���Ϸ\n");

	system("cls");
	puts(page);
}

void SetPrimary()
{
	char page[1024] = { 0 };

	strcat(page, "������������������������������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������������ ɨ      �� ������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "���������������С�������������������\n");
	strcat(page, "������������  �ߡ�������������������\n");
	strcat(page, "���������������� �� �塡������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������ �����ѡ�񡡻س���ȷ��\n");
	strcat(page, "������������ �˳���Ϸ\n");

	system("cls");
	puts(page);
}

void SetIntermediate()
{
	char page[1024] = { 0 };

	strcat(page, "������������������������������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������������ ɨ      �� ������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "����������  ������������������������\n");
	strcat(page, "���������������С�������������������\n");
	strcat(page, "������������  �ߡ�������������������\n");
	strcat(page, "���������������� �� �塡������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������ �����ѡ�񡡻س���ȷ��\n");
	strcat(page, "������������ �˳���Ϸ\n");

	system("cls");
	puts(page);
}

void SetExpert()
{
	char page[1024] = { 0 };

	strcat(page, "������������������������������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������������ ɨ      �� ������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������������  ����������������������\n");
	strcat(page, "���������������С�������������������\n");
	strcat(page, "������������  �ߡ�������������������\n");
	strcat(page, "���������������� �� �塡������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������ �����ѡ�񡡻س���ȷ��\n");
	strcat(page, "������������ �˳���Ϸ\n");

	system("cls");
	puts(page);
}

void SetFree()
{
	char page[1024] = { 0 };

	strcat(page, "������������������������������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������������ ɨ      �� ������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������������  ����������������������\n");
	strcat(page, "���������������С�������������������\n");
	strcat(page, "����������    �ߡ�������������������\n");
	strcat(page, "���������������� �� �塡������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������ �����ѡ�񡡻س���ȷ��\n");
	strcat(page, "������������ �˳���Ϸ\n");

	system("cls");
	puts(page);
}

void DefineHeight(int *row, int *col, int *mine)
{
	char page[1024] = { 0 };

	strcat(page, "������������������������������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������������ ɨ      �� ������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "��������������  �ȣ�%3d ������������\n");
	strcat(page, "��������������  �ȣ�%3d���� ��������\n");
	strcat(page, "��������    ��  ����%3d     ��������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������ �����ѡ�񡡻س���ȷ��\n");
	strcat(page, "������  ���ø߶ȣ���Χ9-24��\n");

	system("cls");
	printf(page, *row, *col, *mine);
}

void DefineWidth(int *row, int *col, int *mine)
{
	char page[1024] = { 0 };

	strcat(page, "������������������������������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������������ ɨ      �� ������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "����������  ��  �ȣ�%3d ������������\n");
	strcat(page, "��������������  �ȣ�%3d���� ��������\n");
	strcat(page, "��������    ��  ����%3d     ��������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������ �����ѡ�񡡻س���ȷ��\n");
	strcat(page, "������  ���ÿ�ȣ���Χ9-30��\n");

	system("cls");
	printf(page, *row, *col, *mine);
}

void DefineMine(int *row, int *col, int *mine)
{
	char page[1024] = { 0 };

	strcat(page, "������������������������������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������������ ɨ      �� ������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "����������  ��  �ȣ�%3d ������������\n");
	strcat(page, "����������  ��  �ȣ�%3d���� ��������\n");
	strcat(page, "��������  ����  ����%3d     ��������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������ �����ѡ�񡡻س���ȷ��\n");
	strcat(page, "������  ������������Χ10-%3d��\n");

	system("cls");
	printf(page, *row, *col, *mine, *row * *col * 9 / 10);
}

int WelcomePage()
{
	int x = 0;

	while (1)
	{
		welcome[x]();
		switch (GetKeyBoard())
		{
		case ARROW_UP:
			x--;
			if (x == -1)
			{
				x = 2;
			}
			break;
		case ARROW_DOWN:
			x++;
			if (x == 3)
			{
				x = 0;
			}
			break;
		case ENTER:
			return x;
		default:
			break;
		}
	}
}
//
//int DefinePage(int *row, int *col, int *mine)
//{
//	int x = 0;
//
//	while (1)
//	{
//		define[x](row, col, mine);
//		switch (GetKeyBoard())
//		{
//		case ARROW_UP:
//			x--;
//			if (x == -1)
//			{
//				x = 2;
//			}
//			break;
//		case ARROW_DOWN:
//			x++;
//			if (x == 3)
//			{
//				x = 0;
//			}
//			break;
//		case ENTER:
//			return x;
//		default:
//			break;
//		}
//	}
//}

