#include"SeqList.h"

int main()
{
	int i;
	SeqList test;
	//��ʼ��
	SeqListInit(&test, 10);

	for (i = 0; i < 7; i++)
	{
		SeqListPushBack(&test, i);
	}
	SeqListPushBack(&test, 3);
	SeqListPushBack(&test, 5);
	SeqListPushBack(&test, 3);
	SeqListPushBack(&test, 3);
	SeqListPrint(&test);
	SeqListRemoveAll(&test, 3);
	SeqListPrint(&test);

	//ɾ��
	SeqListDestory(&test);
	system("pause");
	return 0;
}