#define _CRT_SECURE_NO_WARNINGS
#include"SStack.h"

//��ʼ��ջ
Sp* SStackinit()
{	
	Sp* p = (Sp*)malloc(sizeof(Sp));
	assert(p);
	p->ptop = NULL;
	p->size =0;
	return p;
}

//��ջ
void SStackpush(Sp**p,DataType x)
{
	assert(p);
	SN* tem = (SN*)malloc(sizeof(SN));
	assert(tem);
	tem->data = x;
	tem->next = NULL;
	if (!SStackempty(*p))
	{
		(*p)->ptop = tem;
		(*p)->size++;
	}
	else
	{
		tem->next = (*p)->ptop;
		(*p)->ptop = tem;
		(*p)->size++;
	}
}

//��ջ
void SStackpop(Sp**p)
{
	assert(p);
	assert(SStackempty(*p));
	SN* tem = (*p)->ptop->next;
	free((*p)->ptop);
	(*p)->ptop = tem;
	(*p)->size--;

}

//����ջ��Ԫ��
DataType SStacktop(Sp*p)
{
	assert(SStackempty(p));
	return p->ptop->data;
}

//ջ�п�
bool SStackempty(Sp*p)
{
	return p->size; 
}

//ջ��Ԫ����Ŀ
int SStacksize(Sp*p)
{
	return p->size;
}

//����ջ
void SStackdestory(Sp*p)
{
	p->size = 0;
	SN* cur = p->ptop;
	while (cur)
	{
		SN* next = cur->next;
		free(cur);
		cur = next;
	}
	free(p);
}