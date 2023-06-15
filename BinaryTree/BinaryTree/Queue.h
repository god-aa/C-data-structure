#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

//前置声明不能用typedef的那个类型，只能用原类型
struct BinaryTreeNode;

typedef struct BinaryTreeNode* QDatatype;
//文件会在包含他的地方展开
//也就是Queue.h文件会在test.c  BinaryTree.c中展开
//文件展开后，编译器会向上去找 重命名的那个类型
//由于int是内置类型，故编译器不会报错
//但当重命名的类型是程序员自定义的类型时，若前面没有该类型的声明
//那就会报错

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











