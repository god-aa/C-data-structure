#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

#define CADD 5
typedef int SLtype;

typedef struct SeqList {
	SLtype* data;
	int sz;
	int capacity;
}SL;

void SLinit(SL* ps);

void SLback(SL* ps,SLtype x);

void SLfornt(SL* ps, SLtype x);

void SLpos(SL* ps, int pos, SLtype x);

void SLdelpos(SL* ps, int pos);