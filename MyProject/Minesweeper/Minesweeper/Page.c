#include"Page.h"

char g_nullList[LISTLINES][SAVECOLS - BOUNDARY_SIZE_CHAR + 1];
extern char g_saveList[MAXSAVENUM][SAVECOLS - BOUNDARY_SIZE_CHAR + 1];
int lastFlag = 0;

void WelcomePage(int flag)
{
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

	system("cls");
	printf(page);
}

void SetPage(int flag)
{
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
	strcat(page, "������ ����Esc-������ҳ\n");

	system("cls");
	printf(page);
}

void DefinePage(int row, int col, int mine, int flag)
{
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
	strcat(page, "������     �Զ�����Ϸ����\n");
	strcat(page, "������ �����ѡ�񡡻س���ȷ��\n");
	system("cls");
	printf(page, row, col, mine);
}

void SavePage(int flag)
{
	char page[PAGESIZE_COMMOM] = { 0 };

	if (flag / LISTLINES + 1 == lastFlag && lastFlag != -99 && lastFlag != -101)
	{
		Gotoxy(3, 1 + flag % LISTLINES);
		printf("��");
		return;
	}
	SetConsoleSize(SAVECOLS, SAVELINES);

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
	strcat(page, "����������     Esc������ҳ");
	
	system("cls");
	if (flag >= FIRSTSAVE || flag == TMP)
	{
		printf(page, flag / LISTLINES + 1);
		lastFlag = flag / LISTLINES + 1;
	}
	else
	{
		printf(page, flag / LISTLINES);
		lastFlag = flag / LISTLINES;
	}
	Gotoxy(3, 1 + flag % LISTLINES);
	printf("��");
}