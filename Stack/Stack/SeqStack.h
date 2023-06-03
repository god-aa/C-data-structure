#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int DataType;

typedef struct Stack
{
	DataType* arr;
	int top;
	int capacity;
}ST;

void Stackinit(ST* p);
void Stackpush(ST* p, DataType x);
void Stackpop(ST* p);
DataType Stacktop(ST* p);
bool Stackempty(ST* p);
int Stacksize(ST* p);
void Stackdestory(ST* p);
