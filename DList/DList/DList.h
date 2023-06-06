#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int Datatype;

typedef struct DListNode
{
	Datatype data;
	struct DListNode* next;
	struct DListNode* prev;
}DList;

//初始化
DList* DListinit();

//尾插
void DListpushback(DList* phead, Datatype x);

//尾删
void DListdelback(DList* phead);

//头插
void DListpushfront(DList* phead, Datatype x);

//头删
void DListdelfront(DList* phead);

//查找
DList* DListcheck(DList* phead, Datatype x);

//删除指定位置的值
void DListdelpos(DList* phead, DList* pos);

//在pos位置前面插入
void DListpushposfront(DList* pos, Datatype x);


//打印
void DListprint(DList* phead);
