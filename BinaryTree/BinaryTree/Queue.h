#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

//ǰ������������typedef���Ǹ����ͣ�ֻ����ԭ����
struct BinaryTreeNode;

typedef struct BinaryTreeNode* QDatatype;
//�ļ����ڰ������ĵط�չ��
//Ҳ����Queue.h�ļ�����test.c  BinaryTree.c��չ��
//�ļ�չ���󣬱�����������ȥ�� ���������Ǹ�����
//����int���������ͣ��ʱ��������ᱨ��
//�����������������ǳ���Ա�Զ��������ʱ����ǰ��û�и����͵�����
//�Ǿͻᱨ��

typedef struct Qnode
{
	QDatatype data;
	struct Qnode* next;
}Qn;

typedef struct PQueue
{
	Qn* phead;
	Qn* ptail;
}PQ;

void Queueinit(PQ*p);
void Queuepush(PQ* p, QDatatype x);
void Queuepop(PQ* p);
QDatatype Queuefront(PQ* p);
QDatatype Queueback(PQ* p);
int Queuesize(PQ* p);
bool Queueempty(PQ* p);
void Queuedestroy(PQ* p);











