#define _CRT_SECURE_NO_WARNINGS
#include"DList.h"


//双链表的初始化
DList* DListinit()
{
	//创建哨兵位
	DList* phead = (DList*)malloc(sizeof(DList));
	assert(phead);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}



//双链表的尾插
void DListpushback(DList* phead, Datatype x)
{
	assert(phead);
	DList* tail = phead->prev;
	DList* newnode = (DList*)malloc(sizeof(DList));
	assert(newnode);
	newnode->data = x;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
}
	
//双链表的尾删
void DListdelback(DList* phead)
{
	assert(phead);
	assert(phead->next != phead);
	DList* tail = phead->prev;
	DList* tailprev = tail->prev;
	free(tail);
	tailprev->next = phead;
	phead->prev = tailprev;
	
}

//头插
void DListpushfront(DList* phead, Datatype x)
{
	assert(phead);
	DList* cur = phead->next;
	DList* newnode = (DList*)malloc(sizeof(DList));
	assert(newnode);
	newnode->data = x;
	if (cur == phead)
	{
		phead->next = newnode;
		phead->prev = newnode;
		newnode->next = phead;
		newnode->prev = phead;
	}
	else
	{
		cur->prev = newnode;
		newnode->next = cur;
		newnode->prev = phead;
		phead->next = newnode;
	}
}

//头删
void DListdelfront(DList* phead)
{
	assert(phead);
	assert(phead->next);
	DList* head = phead->next;
	phead->next = head->next;
	head->next->prev = phead;
	free(head);
}

//查找
DList* DListcheck(DList* phead,Datatype x)
{
	assert(phead);
	assert(phead->next);
	DList* cur = phead->next;
	while (cur!=phead)
	{
		if (cur->data == x)
			return cur;
		else
			cur = cur->next;
	}
	return NULL;
}

//删除指定位置pos的值
void DListdelpos(DList*phead,DList* pos)
{
	assert(pos);
	assert(phead);
	assert(phead->next);
	DList* post = pos;
	post->prev->next = post->next;
	post->next->prev = post->prev;
	free(post);
}
//在pos位置前面插入
void DListpushposfront(DList* pos, Datatype x)
{
	assert(pos);
	DList* newnode = (DList*)malloc(sizeof(DList));
	assert(newnode);
	newnode->data = x;
	pos->prev->next = newnode;
	newnode->prev = pos->prev;
	newnode->next = pos;
	pos->prev = newnode;
}

//打印双链表
void DListprint(DList* phead)
{
	DList* cur = phead->next;
	while (cur!=phead)
	{
		printf("%d ",cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}