#include"Stack.h"
//ջ��ʼ��
void StackInit(Stack* ps)
{
	assert(ps);

	ps->_a = (STDataType*)malloc(N * sizeof(STDataType));
	ps->_capacity = N;
	ps->_top = 0;
}
//ջ����
void StackDestory(Stack* ps)
{
	assert(ps);

	ps->_top = 0;
	free(ps->_a);
}
//������ջ
void StackPush(Stack* ps, STDataType x)
{
	assert(ps);

	StackSize(ps);

	ps->_a[ps->_top] = x;
	ps->_top++;
}
//���ݳ�ջ
void StackPop(Stack* ps)
{
	assert(ps);

	ps->_top--;
}
//�õ�ջ������(����ջ)
STDataType StackTop(Stack* ps)
{
	assert(ps);

	return ps->_a[ps->_top - 1];
}
//�ж�ջ�Ƿ�Ϊ��ջ
int StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->_top;
}
//��ջ����ʱ����������Ϊ����������ջ��Ԫ�صĸ�����
int StackSize(Stack* ps)
{
	assert(ps);

	if (ps->_top == ps->_capacity)
	{
		ps->_a = (STDataType*)realloc(ps->_a, ps->_capacity * 2 * sizeof(STDataType));
		ps->_capacity *= 2;
	}

	return ps->_top;
}
//��ӡ��ǰջ��Ԫ��
void StackPrint(Stack* ps)
{
	assert(ps);

	int i;

	for (i = ps->_top - 1; i >= 0; i--)
	{
		printf("%2d || ", ps->_a[i]);
	}
	putchar('\n');
}
//�����������еĺ���
void TestStack()
{
	int i, j;
	Stack S, *ps = &S;

	StackInit(ps);

	for (i = 0; i < 10; i += 4)
	{
		for (j = 1; j < 10; j += 3)
		{
			StackPush(ps, i + j);
		}
	}
	while (StackEmpty(ps)) //�����ڴ�ӡջ������������һ�ߴ�ӡһ�߳�ջ
	{
		StackPrint(ps);
		StackPop(ps);
	}
	putchar('\n');

	StackDestory(ps);
}