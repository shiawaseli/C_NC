#include"func.h"

void MailSystem()
{
	int flag;

	g_mail.num = 0;
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
			DeleteMail();
			break;
		case SEARCH_MSG:
			SearchMail();
			break;
		case CHANGE_MSG:
			ChangeMail();
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
	printf("���˳�!\n");

	system("pause");
	return 0;
}