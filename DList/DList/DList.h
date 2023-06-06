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

//��ʼ��
DList* DListinit();

//β��
void DListpushback(DList* phead, Datatype x);

//βɾ
void DListdelback(DList* phead);

//ͷ��
void DListpushfront(DList* phead, Datatype x);

//ͷɾ
void DListdelfront(DList* phead);

//����
DList* DListcheck(DList* phead, Datatype x);

//ɾ��ָ��λ�õ�ֵ
void DListdelpos(DList* phead, DList* pos);

//��posλ��ǰ�����
void DListpushposfront(DList* pos, Datatype x);


//��ӡ
void DListprint(DList* phead);
