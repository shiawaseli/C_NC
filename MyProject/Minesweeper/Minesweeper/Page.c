#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"Control.h"
#include"Page.h"
#include"Map.h"

extern char saveList[100][37];

void WelcomePage(int flag)
{
	int set = 41 * 6 + 12;
	char page[1024] = { 0 };

	strcat(page, "����������������������������������������\n"); // һ�� 41 ���ַ����������з���
	strcat(page, "����������������������������������������\n");
	strcat(page, "����������������������������������������\n");
	strcat(page, "��������������ɨ���������ס�������������\n");
	strcat(page, "����������������������������������������\n");
	strcat(page, "����������������������������������������\n");
	strcat(page, "����������������������������������������\n");
	strcat(page, "���������������� ����Ϸ ����������������\n");
	strcat(page, "������������������Ϸ���á���������������\n");
	strcat(page, "�������������������˳�������������������\n");
	strcat(page, "����������������������������������������\n");
	strcat(page, "����������������������������������������\n");
	strcat(page, "������   �����ѡ�񡡻س���ȷ��\n");

	switch (flag)
	{
	case WELCOMECONTINUE:
		strcat(page, "����������������������Ϸ\n\n");
		break;
	case WELCOMENEWGAME:
		set += 41;
		strcat(page, "������������������ʼ��Ϸ\n\n");
		break;
	case WELCOMESET:
		set += 41 * 2;
		strcat(page, "��������������������Ϸ�Ѷ�\n\n");
		break;
	case WELCOMEEXIT:
		set += 41 * 3;
		strcat(page, "�����������������˳���Ϸ\n\n");
		break;
	default:
		break;
	}
	page[set] = 0xa1;
	page[set + 1] = 0xf4;
	system("cls");
	printf(page);
	page[set] = ' ';
	page[set + 1] = ' ';
}

void SetPage(int flag)
{
	int set = 37 * 6 + 10;
	char page[1024] = { 0 };

	strcat(page, "������������������������������������\n");  // һ�� 37 ���ַ����������з���
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
	strcat(page, "������������ Esc-��ҳ\n\n");

	switch (flag)
	{
	case LEVEL1:
		break;
	case LEVEL2:
		set += 37;
		break;
	case LEVEL3:
		set += 37 * 2;
		break;
	case FREE:
		set += 37 * 3;
	default:
		break;
	}
	page[set] = 0xa1;
	page[set + 1] = 0xf4;
	system("cls");
	printf(page);
	page[set] = ' ';
	page[set + 1] = ' ';
}

void DefinePage(int row, int col, int mine, int flag)
{
	int set = 37 * 7 + 10;
	char page[1024] = { 0 };

	strcat(page, "������������������������������������\n"); // һ�� 37 ���ַ����������з���
	strcat(page, "������������������������������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������������ ɨ      �� ������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "��������������  �ȣ�%3d ������������\n");
	strcat(page, "��������������  �ȣ�%3d���� ��������\n");
	strcat(page, "��������  ����  ����%3d     ��������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������������������������������������\n");
	strcat(page, "������ �����ѡ�񡡻س���ȷ��\n");
	switch (flag)
	{
	case DEFINEHEIGHT:
		strcat(page, "������  ���ø߶ȣ���Χ9-24��\n\n");
		break;
	case DEFINEWIDTH:
		set += 37;
		strcat(page, "������  ���ÿ�ȣ���Χ9-30��\n\n");
		break;
	case DEFINEMINE:
		set += 37 * 2;
		strcat(page, "������  ������������Χ10-%d��\n\n");
		break;
	default:
		break;
	}
	page[set] = 0xa1;
	page[set + 1] = 0xf4;
	system("cls");
	if (flag != DEFINEMINE)
	{
		printf(page, row, col, mine);
	}
	else
	{
		printf(page, row, col, mine, MAXMINE(row, col));
	}
	page[set] = ' ';
	page[set + 1] = ' ';
}

void SavePage(int flag)
{
	char page[1024] = { 0 };

	if (flag != TMP)
	{
		saveList[flag][1] = 0xa1;
		saveList[flag][2] = 0xf4;
	}
	else
	{
		flag++;
	}
	strcat(page, "����������������������������������������\n");
	//strcat(page, "�� �� �Զ��� Tue Aug 20 15:42:11 2019 ��\n"); // ��������
	//strcat(page, "��    δ�浵 NNN NNN NN NN:NN:NN NNNN ��\n"); // ��������
	for (int i = flag / 10 * 10; i < flag / 10 * 10 + 10; i++)
	{
		strcat(page, "��");
		strcat(page, saveList[i]);
		strcat(page, "��\n");
	}
	strcat(page, "������������������������������������%2dҳ\n");
	strcat(page, "������   �����ѡ�񡡻س���ȷ��\n");
	strcat(page, "����������  C-�����ϴ���Ϸ\n\n");
	saveList[flag][1] = ' ';
	saveList[flag][2] = ' ';

	system("cls");
	printf(page, flag / 10 + 1);
}