#define _CRT_SECURE_NO_WARNINGS
#include"SeqStack.h"

//栈的初始化
void Stackinit(ST* p)
{
	p->arr = NULL;
	p->capacity = p->top = 0;
}

//进栈
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

//出栈
void Stackpop(ST*p)
{
	assert(p);
	assert(Stackempty(p));
	p->top--;
}

//取栈顶元素
DataType Stacktop(ST*p)
{
	assert(p);
	assert(Stackempty(p));
	return p->arr[p->top-1];
}

//栈判空
bool Stackempty(ST*p)
{
	return p->top;
}

//取栈的元素个数
int Stacksize(ST*p)
{
	assert(p);
	return p->top;
}

//销毁栈
void Stackdestory(ST*p)
{
	free(p->arr);
	p->capacity = p->top = 0;
}
