#include"DataStructures.h"

void StackTest_1()
{
	int i, len;
	char input[100];
	STACK s;

	s.top = -1;
	scanf("%s", input);
	len = strlen(input);
	for (i = 0; i < len / 2; i++)
	{
		s.top++;
		s.arr[s.top] = input[i];
	}
	if (len % 2)
	{
		i++;
	}
	while (i < len)
	{
		if (s.arr[s.top] != input[i])
		{
			break;
		}
		s.top--;
		i++;
	}
	if (i < len)
	{
		printf("���ǻ���\n");
	}
	else
	{
		printf("�ǻ���\n");
	}
}