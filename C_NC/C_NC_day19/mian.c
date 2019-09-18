#include"func.h"

void MailSystem()
{
	int id, ret, flag;
	char aim[50] = { 0 };

	g_mail.num = 0;
	g_mail.man = (MailMSG*)calloc(MANNUM, sizeof(MailMSG));
	LoadMail();
	while (flag = Menu())
	{
		switch (flag)
		{
		case EXIT_SYS:
			printf("�˳��С�����\n");
			return;
		case ADD_MSG:
			InsertMail();
			break;
		case DELETE_MSG:
			printf("������Ҫɾ����Ϣ�˵ı��:>");
			scanf("%d", &id);
			if (DeleteMail(id - 1))
			{
				printf("ɾ���ɹ�!\n");
			}
			else
			{
				printf("����Ϣ������!\n");
			}
			break;
		case SEARCH_MSG:
			printf("������Ҫ���ҵ���Ϣ:>");
			scanf("%s", aim);
			printf("���ҿ�ʼ��\n");
			ret = SearchMail(aim);
			if (ret)
			{
				printf("���ҽ�����\n");
				printf("�����ҵ���Ϣ%d��\n", ret);
			}
			else
			{
				printf("�����ڷ�����������Ϣ\n");
				printf("���ҽ�����\n");
			}
			break;
		case CHANGE_MSG:
			printf("������Ҫ�޸���Ϣ�˵ı��:>");
			scanf("%d", &id);
			if (ChangeMail(id - 1))
			{
				printf("�޸ĳɹ�!\n");
			}
			else
			{
				printf("����Ϣ������!\n");
			}
			break;
		case OUTPUT_MSG:
			OutputMail();
			break;
		
		default:
			printf("ERROR!\n");
			break;
		}
	}
}

int main()
{
	MailSystem();
	SaveMail();
	printf("���˳�!\n");

	system("pause");
	return 0;
}