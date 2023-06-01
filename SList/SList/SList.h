#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


typedef int SLTdatatype;
//创建节点
typedef struct SListnode
{
	SLTdatatype data;//创建数据域
	struct SListnode* next;//创建指针域，保存下一个节点的地址

	//对结构体类型重命名后，不能用重新命名的名字对结构体进行自引用

}SLnode;

void SLprint(SLnode* head);

void SListpushback(SLnode** back, SLTdatatype x);

void SListpushfront(SLnode** head, SLTdatatype x);

void SListdelback(SLnode** head);
SLnode* SListfind(SLnode* head, SLTdatatype x);

void SListpushpos(SLnode** head, SLnode* pos, SLTdatatype x);

void SListdelpos(SLnode** head, SLnode* pos);