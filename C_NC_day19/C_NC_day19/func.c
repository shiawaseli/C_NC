#include"func.h"

int Menu()
{
	int input;

	putchar('\n');
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
	printf("���   ����   �Ա�    ����   ��ϵ��ʽ    סַ\n");
}
void PrintMSG(int id)
{
	printf(" %d   %-8s %3s    %3d  %11s  %-10s\n", id + 1, g_mail.man[id].name, g_mail.man[id].sex, g_mail.man[id].age, g_mail.man[id].tele, g_mail.man[id].addr);
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
	if (g_mail.num == MANNUM - 1)
	{
		printf("ͨѶ¼����,���ʧ��!\n");
		return;
	}
	for (i = g_mail.num; i - 1 >= 0 && strcmp(g_mail.man[i - 1].name, input.name) > 0; i--)
	{
		g_mail.man[i] = g_mail.man[i - 1];
	}
	g_mail.man[i] = input;
	g_mail.num++;
}

int DeleteMail(int id)
{
	int i = id;

	if (id >= g_mail.num)
	{
		return ERROR;
	}
	while (i < g_mail.num)
	{
		if (i + 1 < MANNUM)
		{
			g_mail.man[i] = g_mail.man[i + 1];
		}
		i++;
	}
	g_mail.num--;

	return TRUE;
}

int SearchMail(char *p)
{
	int i, flag, count = 0;
	char *t, age[5] = { 0 };

	for (i = 0; i < g_mail.num; i++)
	{
		do
		{
			flag = 1;
			t = strstr(g_mail.man[i].name, p);//�������в���
			if (t)
			{
				break;
			}
			t = strstr(g_mail.man[i].addr, p);//�ڵ�ַ�в���
			if (t)
			{
				break;
			}
			t = strstr(g_mail.man[i].sex, p);//���Ա��в���
			if (t)
			{
				break;
			}
			t = strstr(g_mail.man[i].tele, p);//����ϵ��ʽ�в���
			if (t)
			{
				break;
			}
			sprintf(age, "%d", g_mail.man[i].age);
			t = strstr(age, p);//�������в���
			if (t)
			{
				break;
			}
			flag = 0;
		} while (0);
		if (flag)
		{
			PrintMSG(i);
			count++;
		}
	}

	return count;
}

int ChangeMail(int id)
{
	char input[50] = { 0 };
	if (id >= g_mail.num)
	{
		return ERROR;
	}
	printf("�����Ƿ�Ҫ�޸ģ�(y/n)");
	scanf("%s", input);
	if (!strcmp(input, "y") || !strcmp(input, "Y"))
	{
		printf("�������µ�����:>");
		scanf("%50s", g_mail.man[id].name);
	}
	printf("�Ա��Ƿ�Ҫ�޸ģ�(y/n)");
	scanf("%s", input);
	if (!strcmp(input, "y") || !strcmp(input, "Y"))
	{
		printf("�������µ��Ա�:>");
		scanf("%3s", g_mail.man[id].sex);
	}
	printf("�����Ƿ�Ҫ�޸ģ�(y/n)");
	scanf("%s", input);
	if (!strcmp(input, "y") || !strcmp(input, "Y"))
	{
		printf("�������µ�����:>");
		scanf("%d", &g_mail.man[id].age);
	}
	printf("��ϵ��ʽ�Ƿ�Ҫ�޸ģ�(y/n)");
	scanf("%s", input);
	if (!strcmp(input, "y") || !strcmp(input, "Y"))
	{
		printf("�������µ���ϵ��ʽ:>");
		scanf("%11s", g_mail.man[id].tele);
	}
	printf("סַ�Ƿ�Ҫ�޸ģ�(y/n)");
	scanf("%s", input);
	if (!strcmp(input, "y") || !strcmp(input, "Y"))
	{
		printf("�������µ�סַ:>");
		scanf("%50s", g_mail.man[id].addr);
	}

	return TRUE;
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