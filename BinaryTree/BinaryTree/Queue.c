#define _CRT_SECURE_NO_WARNINGS
#include"Queue.h"

//��ʼ������
void Queueinit(PQ*p)
{
	p->phead = p->ptail = NULL;
}

//��β�����
void Queuepush(PQ*p,QDatatype x)
{
	assert(p);
	Qn* newnode = (Qn*)malloc(sizeof(Qn));
	assert(newnode);
	newnode->data = x;
	newnode->next = NULL;
	if (!Queueempty(p))
	{
		p->phead = p->ptail = newnode;
	}
	else
	{
		p->ptail->next = newnode;
		p->ptail = newnode;
	}
}

//��ͷ������
void Queuepop(PQ*p)
{
	assert(p);
	assert(Queueempty(p));
	Qn* next = p->phead->next;
	free(p->phead);
	p->phead = next;
}

//��ȡ����ͷ��Ԫ��
QDatatype Queuefront(PQ*p)
{
	assert(p);
	assert(p->phead);
	return p->phead->data;
}

//��ȡ����β��Ԫ��
QDatatype Queueback(PQ*p)
{
	assert(p);
	assert(Queueempty(p));
	return p->ptail->data;
}

//��ȡ��������ЧԪ�ظ���
int Queuesize(PQ*p)
{
	assert(p);
	Qn* cur = p->phead;
	int n = 0;
	while (cur)
	{
		n++;
		cur = cur->next;
	}
	return n;
}

//�������Ƿ�Ϊ�գ���Ϊ�գ�����false
bool Queueempty(PQ*p)
{
	assert(p);
	return p->phead;
}

//���ٶ���
void Queuedestroy(PQ*p)
{
	//����ѭ���������д�ͷ��β�Ľ���ͷ��ڴ�ռ�
	Qn* cur = p->phead;
	while (cur)
	{
		Qn* next = cur->next;
		free(cur);
		cur = next;
	}
	p->phead = p->ptail = NULL;
}