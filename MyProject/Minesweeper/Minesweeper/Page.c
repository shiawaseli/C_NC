#include"Page.h"

char g_nullList[LISTLINES][SAVECOLS - BOUNDARY_SIZE_CHAR + 1];
extern char g_saveList[MAXSAVENUM][SAVECOLS - BOUNDARY_SIZE_CHAR + 1];

void WelcomePage(int flag)
{
	int set = WELCOMECOLS * 6 + 12;
	char page[PAGESIZE_COMMOM] = { 0 };

	SetConsoleSize(WELCOMECOLS, WELCOMELINES);
	strcat(page, "����������������������������������������"); // һ�� 40 ���ַ�
	strcat(page, "����������������������������������������");
	strcat(page, "����������������������������������������");
	strcat(page, "��������������ɨ���������ס�������������");
	strcat(page, "����������������������������������������");
	strcat(page, "����������������������������������������");
	strcat(page, "����������������������������������������");
	strcat(page, "���������������� ����Ϸ ����������������");
	strcat(page, "������������������Ϸ���á���������������");
	strcat(page, "�������������������˳�������������������");
	strcat(page, "����������������������������������������");
	strcat(page, "����������������������������������������");
	strcat(page, "������   �����ѡ�񡡻س���ȷ��\n");

	switch (flag)
	{
	case WELCOMECONTINUE:
		strcat(page, "����������������������Ϸ");
		break;
	case WELCOMENEWGAME:
		set += WELCOMECOLS;
		strcat(page, "������������������ʼ��Ϸ");
		break;
	case WELCOMESET:
		set += WELCOMECOLS * 2;
		strcat(page, "��������������������Ϸ�Ѷ�");
		break;
	case WELCOMEEXIT:
		set += WELCOMECOLS * 3;
		strcat(page, "�����������������˳���Ϸ");
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
	int set = SETCOLS * 6 + 10;
	char page[PAGESIZE_COMMOM] = { 0 };

	SetConsoleSize(SETCOLS, SETLINES);
	strcat(page, "������������������������������������");  // һ�� 36 ���ַ�
	strcat(page, "������������������������������������");
	strcat(page, "������������������������������������");
	strcat(page, "������������ ɨ      �� ������������");
	strcat(page, "������������������������������������");
	strcat(page, "������������������������������������");
	strcat(page, "������������������������������������");
	strcat(page, "���������������С�������������������");
	strcat(page, "������������  �ߡ�������������������");
	strcat(page, "���������������� �� �塡������������");
	strcat(page, "������������������������������������");
	strcat(page, "������������������������������������");
	strcat(page, "������ �����ѡ�񡡻س���ȷ��\n");
	strcat(page, "������������  Esc-��ҳ");

	switch (flag)
	{
	case LEVEL1:
		break;
	case LEVEL2:
		set += SETCOLS;
		break;
	case LEVEL3:
		set += SETCOLS * 2;
		break;
	case FREE:
		set += SETCOLS * 3;
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
	int set = SETCOLS * 7 + 8;
	char page[PAGESIZE_COMMOM] = { 0 };

	SetConsoleSize(SETCOLS, SETLINES);
	strcat(page, "������������������������������������"); // һ�� 37 ���ַ����������з���
	strcat(page, "������������������������������������");
	strcat(page, "������������������������������������");
	strcat(page, "������������ ɨ      �� ������������");
	strcat(page, "������������������������������������");
	strcat(page, "������������������������������������");
	strcat(page, "������������������������������������");
	strcat(page, "��������������  �ȣ�%3d ������������");
	strcat(page, "��������������  �ȣ�%3d���� ��������");
	strcat(page, "��������  ����  ����%3d     ��������");
	strcat(page, "������������������������������������");
	strcat(page, "������������������������������������");
	strcat(page, "������ �����ѡ�񡡻س���ȷ��\n");
	switch (flag)
	{
	case DEFINEHEIGHT:
		strcat(page, "������  ���ø߶ȣ���Χ9-24��");
		break;
	case DEFINEWIDTH:
		set += SETCOLS;
		strcat(page, "������  ���ÿ�ȣ���Χ9-30��");
		break;
	case DEFINEMINE:
		set += SETCOLS * 2;
		strcat(page, "������  ������������Χ10-%d��");
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
	char page[PAGESIZE_COMMOM] = { 0 };

	SetConsoleSize(SAVECOLS, SAVELINES);
	if (flag >= FIRSTSAVE && flag <= LASTSAVE)
	{
		g_saveList[flag][1] = 0xa1;
		g_saveList[flag][2] = 0xf4;
	}
	strcat(page, "����������������������������������������");
	//strcat(page, "�� �� �Զ��� Tue Aug 20 15:42:11 2019 ��"); // ��������
	//strcat(page, "��    δ�浵 NNN NNN NN NN:NN:NN NNNN ��"); // ��������
	for (int i = flag / LISTLINES * LISTLINES; i < flag / LISTLINES * LISTLINES + LISTLINES; i++)
	{
		strcat(page, "��");
		if (flag >= FIRSTSAVE && flag <= LASTSAVE || flag == TMP)
		{
			strcat(page, g_saveList[i]);
		}
		else
		{
			strcat(page, g_nullList[abs(i % 10)]);
		}
		strcat(page, "��");
	}
	strcat(page, "������������������������������������%2dҳ");
	strcat(page, "����������      Esc-�˳�");
	if (flag >= FIRSTSAVE && flag <= LASTSAVE)
	{
		g_saveList[flag][1] = ' ';
		g_saveList[flag][2] = ' ';
	}

	system("cls");
	if (flag >= FIRSTSAVE || flag == TMP)
	{
		printf(page, flag / LISTLINES + 1);
	}
	else
	{
		printf(page, flag / LISTLINES);
	}
}