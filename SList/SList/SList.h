#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


typedef int SLTdatatype;
//�����ڵ�
typedef struct SListnode
{
	SLTdatatype data;//����������
	struct SListnode* next;//����ָ���򣬱�����һ���ڵ�ĵ�ַ

	//�Խṹ�������������󣬲������������������ֶԽṹ�����������

}SLnode;

void SLprint(SLnode* head);

void SListpushback(SLnode** back, SLTdatatype x);

void SListpushfront(SLnode** head, SLTdatatype x);

void SListdelback(SLnode** head);
SLnode* SListfind(SLnode* head, SLTdatatype x);

void SListpushpos(SLnode** head, SLnode* pos, SLTdatatype x);

void SListdelpos(SLnode** head, SLnode* pos);