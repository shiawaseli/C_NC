#include"func.h"

int Menu()
{
	int input;

	printf("\t\t\t0���˳�\n");
	printf("\t\t\t1��������Ϣ\n");
	printf("\t\t\t2��ɾ����Ϣ\n");
	printf("\t\t\t3��������Ϣ\n");
	printf("\t\t\t4���޸���Ϣ\n");
	printf("\t\t\t5����ʾ��ǰ���е���Ϣ\n");
	while (!scanf("%d", &input))
	{
		getchar();
	}

	return input;
}

void PrintTitle()
{
	printf("   ����   �Ա�    ����   ��ϵ��ʽ    סַ\n");
}
void PrintMSG(int id)
{
	printf("  %-8s %3s    %3d  %11s  %-10s\n", g_mail.man[id].name, g_mail.man[id].sex, g_mail.man[id].age, g_mail.man[id].tele, g_mail.man[id].addr);
}

void InputMSG(MailMSG **p)
{
	printf("����������:>");
	scanf("%50s", (*p)->name);
	printf("�������Ա�:>");
	scanf("%3s", (*p)->sex);
	printf("����������:>");
	scanf("%d", &(*p)->age);
	printf("��������ϵ��ʽ:>");
	scanf("%11s", (*p)->tele);
	printf("������סַ:>");
	scanf("%50s", (*p)->addr);
}

void InsertMail()
{
	int i;
	MailMSG input, *p = &input;

	InputMSG(&p);
	for (i = g_mail.num; i > 0 && strcmp(g_mail.man[i - 1].name, input.name) > 0; i++)
	{
		if (i < MANNUM)
		{
			g_mail.man[i] = g_mail.man[i - 1];
		}
	}
	g_mail.man[i] = input;
	g_mail.num++;
}

void DeleteMail()
{
	printf("DeleteMail()\n");
}

void SearchMail()
{
	printf("SearchMail()\n");
}

void ChangeMail()
{
	printf("ChangeMail()\n");
}

void OutputMail()
{
	int i;

	PrintTitle();
	for (i = 0; i < g_mail.num; i++)
	{
		PrintMSG(i);
	}
}