#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"Control.h"
#include"Show.h"

void(*welcome[3])() = { WelcomeStart, WelcomeSet, WelcomeExit };

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


int WelcomePage()
{
	int flag;
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