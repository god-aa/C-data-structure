#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int DataType;

typedef struct SNode
{
	DataType data;
	struct SNode* next;
}SN;

typedef struct SStackp
{
	SN* ptop;
	int size;
	int capacity;
}Sp;

Sp* SStackinit();
void SStackpush(Sp* p, DataType x);
void SStackpop(Sp* p);
DataType SStacktop(Sp* p);
bool SStackempty(Sp* p);
int SStacksize(Sp* p);
void SStackdestory(Sp* p);
