#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int Datatype;

typedef struct Qnode
{
	Datatype data;
	struct Qnode* next;
}Qn;

typedef struct PQueue
{
	Qn* phead;
	Qn* ptail;
}PQ;

void Queueinit(PQ*p);
void Queuepush(PQ* p, Datatype x);
void Queuepop(PQ* p);
Datatype Queuefront(PQ* p);
Datatype Queueback(PQ* p);
int Queuesize(PQ* p);
bool Queueempty(PQ* p);
void Queuedestroy(PQ* p);











