#include"Stack.h"
// ջ��ʼ��
void StackInit(Stack* ps)
{
	assert(ps);

	ps->_data = (STDataType*)malloc(N * sizeof(STDataType));
	ps->_capacity = N;
	ps->_top = 0;
}
// ջ����
void StackDestory(Stack* ps)
{
	assert(ps);

	ps->_top = 0;
	ps->_capacity = 0;
	free(ps->_data);
}
// ������ջ
void StackPush(Stack* ps, STDataType val)
{
	assert(ps);

	StackSize(ps);

	ps->_data[ps->_top++] = val;
}
// ���ݳ�ջ
STDataType StackPop(Stack* ps)
{
	assert(ps);

	return ps->_data[--ps->_top];
}
// �õ�ջ������(����ջ)
STDataType StackTop(Stack* ps)
{
	assert(ps);

	return ps->_data[ps->_top - 1];
}
// �ж�ջ�Ƿ�Ϊ��ջ
int StackEmpty(Stack* ps)
{
	assert(ps);

	return !ps->_top;
}
// ��ջ����ʱ����������Ϊ����������ջ��Ԫ�صĸ�����
int StackSize(Stack* ps)
{
	assert(ps);

	if (ps->_top == ps->_capacity)
	{
		ps->_data = (STDataType*)realloc(ps->_data, ps->_capacity * 2 * sizeof(STDataType));
		ps->_capacity *= 2;
	}

	return ps->_top;
}
// ��ӡ��ǰջ��Ԫ��
void StackPrint(Stack* ps)
{
	assert(ps);

	int i;

	for (i = 0; i < ps->_top; i++)
	{
		PRINTSTACK(ps->_data[i]);
	}
	putchar('\n');
}

// �ж������Ƿ�ƥ��
int IsValid(char *str)
{
	int ret = 1;
	Stack S, *ps = &S;
	STDataType val = (STDataType)0;

	StackInit(ps);
	while (*str != '\0')
	{
		val = StackTop(ps);
		switch (*str)
		{
		case '[':
		case '{':
		case '(':
			StackPush(ps, *str);
			break;
		case ']':
			if (val == '[')
			{
				StackPop(ps);
			}
			else
			{
				ret = 0;
			}
			break;
		case '}':
			if (val == '{')
			{
				StackPop(ps);
			}
			else
			{
				ret = 0;
			}
			break;
		case ')':
			if (val == '(')
			{
				StackPop(ps);
			}
			else
			{
				ret = 0;
			}
			break;
		default:
			break;
		}
		str++;
		//StackPrint(ps);
	}
	if (!StackEmpty(ps))
	{
		ret = 0;
	}
	StackDestory(ps);

	return ret;
}

// ���г�ʼ��
void QueueInit(QueueByStack* pq)
{
	assert(pq);

	pq->queue = (Stack*)malloc(sizeof(Stack));
	pq->tmp = (Stack*)malloc(sizeof(Stack));
	StackInit(pq->queue);
}
// ��������
void QueueDestory(QueueByStack* pq)
{
	assert(pq);

	StackDestory(pq->queue);
}
// �������
void QueuePush(QueueByStack* pq, STDataType val)
{
	assert(pq);

	STDataType x;

	StackSize(pq->queue);
	StackInit(pq->tmp);

	while (!StackEmpty(pq->queue))
	{
		x = StackPop(pq->queue);
		StackPush(pq->tmp, x);
	}
	StackPush(pq->queue, val);
	while (!StackEmpty(pq->tmp))
	{
		x = StackPop(pq->tmp);
		StackPush(pq->queue, x);
	}

	StackDestory(pq->tmp);
}
// ���ݳ���
STDataType QueuePop(QueueByStack* pq)
{
	assert(pq);

	return StackPop(pq->queue);
}
// �õ���������(������)
STDataType QueueTop(QueueByStack* pq)
{
	assert(pq);

	return StackTop(pq->queue);
}
// �ж϶����Ƿ�Ϊ�ն�
int QueueEmpty(QueueByStack* pq)
{
	assert(pq);

	return StackEmpty(pq->queue);
}
// ��ӡ��ǰ������Ԫ��
void QueuePrint(QueueByStack* pq)
{
	assert(pq);

	int i;

	for (i = pq->queue->_top - 1; i >= 0; i--)
	{
		PRINTQUEUE(pq->queue->_data[i]);
	}
	putchar('\n');
}

//�����������еĺ���
void TestStack()
{
	int i;
	char *str = "{[{abcd}{ef}]{gh}}";
	char *str2 = "int main()\n{ \n	TestStack();\n	system(\"pause\");\n	return 0;\n}";
	Stack S, *ps = &S;
	STDataType val;

	StackInit(ps);

	srand((unsigned int)time(NULL));
	for (i = 0; i < 10; i++)
	{
		val = rand() % 10 + PLUS;
		StackPush(ps, val);
	}
	while (!StackEmpty(ps)) //�����ڴ�ӡջ������������һ�ߴ�ӡһ�߳�ջ
	{
		StackPrint(ps);
		val = StackPop(ps);
		if (val == 5 + PLUS)
		{
			val = rand() % 10 + PLUS;
			StackPush(ps, val);
			printf("\n��ջ����Ϊ5����ʱ��ջ%d\n", val - PLUS);
		}
	}
	putchar('\n');
	printf("�ַ���\n\n%s\n\n������ƥ�����? ", str);
	if (IsValid(str))
	{
		printf("Yes!\n");
	}
	else
	{
		printf("No!\n");
	}

	StackDestory(ps);
}

void TestQueueByStack()
{
	int i;
	QueueByStack Q, *pq = &Q;
	STDataType val;

	QueueInit(pq);

	srand((unsigned int)time(NULL));
	for (i = 0; i < 10; i++)
	{
		val = rand() % 10 + PLUS;
		QueuePush(pq, val);
	}
	while (!QueueEmpty(pq)) //�����ڴ�ӡ���У�����������һ�ߴ�ӡһ�߳���
	{
		QueuePrint(pq);
		val = QueuePop(pq);
		if (val == 5 + PLUS)
		{
			val = rand() % 10 + PLUS;
			QueuePush(pq, val);
			printf("\n��������Ϊ5����ʱ���%d\n", val - PLUS);
		}
	}
	putchar('\n');

	QueueDestory(pq);
}