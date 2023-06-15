#define _CRT_SECURE_NO_WARNINGS
#include"Queue.h"

//初始化队列
void Queueinit(PQ*p)
{
	p->phead = p->ptail = NULL;
}

//队尾入队列
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

//队头出队列
void Queuepop(PQ*p)
{
	assert(p);
	assert(Queueempty(p));
	Qn* next = p->phead->next;
	free(p->phead);
	p->phead = next;
}

//获取队列头部元素
QDatatype Queuefront(PQ*p)
{
	assert(p);
	assert(p->phead);
	return p->phead->data;
}

//获取队列尾部元素
QDatatype Queueback(PQ*p)
{
	assert(p);
	assert(Queueempty(p));
	return p->ptail->data;
}

//获取队列中有效元素个数
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

//检测队列是否为空，若为空，返回false
bool Queueempty(PQ*p)
{
	assert(p);
	return p->phead;
}

//销毁队列
void Queuedestroy(PQ*p)
{
	//需用循环将队列中从头到尾的结点释放内存空间
	Qn* cur = p->phead;
	while (cur)
	{
		Qn* next = cur->next;
		free(cur);
		cur = next;
	}
	p->phead = p->ptail = NULL;
}