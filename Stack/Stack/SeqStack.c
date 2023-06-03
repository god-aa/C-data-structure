#define _CRT_SECURE_NO_WARNINGS
#include"SeqStack.h"

//ջ�ĳ�ʼ��
void Stackinit(ST* p)
{
	p->arr = NULL;
	p->capacity = p->top = 0;
}

//��ջ
void Stackpush(ST*p,DataType x)
{
	assert(p);
	if (p->capacity==p->top)
	{
		int newcapacity = p->capacity == 0 ? 4 : sizeof(DataType) * 2;
		p->arr = (DataType*)realloc(p->arr, sizeof(DataType) * newcapacity);
		assert(p->arr);
		p->capacity = newcapacity;
	}
	p->arr[p->top++] = x;
}

//��ջ
void Stackpop(ST*p)
{
	assert(p);
	assert(Stackempty(p));
	p->top--;
}

//ȡջ��Ԫ��
DataType Stacktop(ST*p)
{
	assert(p);
	assert(Stackempty(p));
	return p->arr[p->top-1];
}

//ջ�п�
bool Stackempty(ST*p)
{
	return p->top;
}

//ȡջ��Ԫ�ظ���
int Stacksize(ST*p)
{
	assert(p);
	return p->top;
}

//����ջ
void Stackdestory(ST*p)
{
	free(p->arr);
	p->capacity = p->top = 0;
}
