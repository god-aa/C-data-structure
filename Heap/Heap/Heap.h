#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int Datatype;

typedef struct Headnode
{
	Datatype* arr;
	int size;
	int capacity;
}Hd;

void Adjustdown(Datatype* pa, int sz, int parent);
void Adjustup(Datatype* pa, int sz);
void TOPK(int* arr, int n, int k);
void Heapsort(int* a, int sz);
void Heapsort1(int* a, int n);




void Hdinit(Hd*p);
void Hddestory(Hd* p);
void Hdpush(Hd* p, Datatype x);
void Hdpop(Hd* p);
int Hdsize(Hd* p);
bool Hdempty(Hd* p);
void Hdprint(Hd* p);
Datatype Hdtop(Hd* p);






