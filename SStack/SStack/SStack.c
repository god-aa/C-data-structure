#define _CRT_SECURE_NO_WARNINGS
#include"SStack.h"

//初始化栈
Sp* SStackinit()
{	
	Sp* p = (Sp*)malloc(sizeof(Sp));
	assert(p);
	p->ptop = NULL;
	p->size =0;
	return p;
}

//进栈
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

//出栈
void SStackpop(Sp**p)
{
	assert(p);
	assert(SStackempty(*p));
	SN* tem = (*p)->ptop->next;
	free((*p)->ptop);
	(*p)->ptop = tem;
	(*p)->size--;

}

//返回栈顶元素
DataType SStacktop(Sp*p)
{
	assert(SStackempty(p));
	return p->ptop->data;
}

//栈判空
bool SStackempty(Sp*p)
{
	return p->size; 
}

//栈中元素数目
int SStacksize(Sp*p)
{
	return p->size;
}

//销毁栈
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