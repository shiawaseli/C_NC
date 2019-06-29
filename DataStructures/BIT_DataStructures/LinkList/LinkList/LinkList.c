#include"LinkList.h"
//�����ʼ��
void SListInit(SList* plist)
{
	assert(plist);

	plist->_head = NULL;
}
//��������
void SListDestory(SList* plist)
{
	assert(plist);

	SListNode *tmp;

	while (plist->_head)
	{
		tmp = plist->_head;
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}

//�����ݷ���һ�����
SListNode* BuySListNode(SLTDataType x)
{
	SListNode *cur = (SListNode*)malloc(sizeof(SListNode));

	assert(cur);

	cur->_data = x;
	cur->_next = NULL;

	return cur;
}
// ͷ�巨��������
void SListPushFront(SList* plist, SLTDataType x)
{
	assert(plist);

	SListNode *cur = (SListNode*)malloc(sizeof(SListNode));

	assert(cur);

	cur->_data = x;
	cur->_next = plist->_head;
	plist->_head = cur;
}
//ͷɾ��ɾ������
void SListPopFront(SList* plist)
{
	assert(plist);

	SListNode *tmp = plist->_head;

	if (plist->_head)
	{
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}
//�������в�������
SListNode* SListFind(SList* plist, SLTDataType x)
{
	assert(plist);

	SListNode *cur;

	for (cur = plist->_head; cur; cur = cur->_next)
	{
		if (cur->_data == x)
		{
			return cur;
		}
	}

	return NULL;
}
// ��pos�ĺ�����в��� 
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	assert(pos);

	SListNode *tmp = (SListNode*)malloc(sizeof(SListNode));

	assert(tmp);

	tmp->_data = x;
	tmp->_next = pos->_next;
	pos->_next = tmp;
}
// ��pos��ǰ����в��� 
void SListInsertFront(SList* plist, SListNode* pos, SLTDataType x)
{
	assert(plist);

	SListNode *tmp = (SListNode*)malloc(sizeof(SListNode));
	SListNode *cur;

	assert(tmp);

	tmp->_data = x;
	if (plist->_head == pos)
	{
		tmp->_next = plist->_head;
		plist->_head = tmp;
		return;
	}
	for (cur = plist->_head; cur->_next; cur = cur->_next)
	{
		if (cur->_next == pos)
		{
			tmp->_next = cur->_next;
			cur->_next = tmp;
			return;
		}
	}
}
//ɾ��pos��һ��λ�õ�����
void SListEraseAfter(SListNode* pos)
{
	assert(pos);

	SListNode *tmp = pos->_next;

	if (pos->_next)
	{
		pos->_next = pos->_next->_next;
		free(tmp);
	}
}
//ɾ�����ȳ��ֵ�ָ������
void SListRemove(SList* plist, SLTDataType x)
{
	assert(plist);

	SListNode *cur, *tmp;

	for (cur = plist->_head; cur->_next; cur = cur->_next)
	{
		if (cur->_next->_data == x)
		{
			tmp = cur->_next;
			cur->_next = cur->_next->_next;
			free(tmp);
			return;
		}
	}
}

//��ӡ����
void SListPrint(SList* plist)
{
	assert(plist);

	SListNode *cur;

	for (cur = plist->_head; cur; cur = cur->_next)
	{
		printf("%d->", cur->_data);
	}
	printf("NULL\n");
}
void TestSList()
{

}