#define _CRT_SECURE_NO_WARNINGS
#include"SList.h"

void SLprint(SLnode* head)
{
	assert(head);
	SLnode* cur = head;
	while (cur!=NULL)
	{	
		//输出当前指针cur指向的结点的数据域
		printf("%d", cur->data);

		//当前指针的指针域存放的是下一个结点的地址
		//把下一个结点的地址赋值给指向当前结点的指针cur
		//也就是让结点指针cur从头结点的位置移动到下一个结点的位置
		cur = cur->next;
	}
	printf("\n");
}
//打印单链表只要传一级指针的原因：
//一级指针head是形参，也是变量，类型是SLnode*，
// 而实参的类型也是SLnode* 实参和形参的类型一样，属于传值调用
// 

//建立新结点
SLnode* newnode(SLTdatatype x)
{
	SLnode* node = (SLnode*)malloc(sizeof(SLnode));
	assert(node);
	node->data = x;
	node->next = NULL;
	return node;
}

//修改链表需要传二级指针的原因
//若形参是一级指针，而单个结点的类型也是一级指针类型，
//也就是说形参和实参的类型一样，这样就是传值调用了
//若是传值调用，形参只是实参的一份临时拷贝，
//对形参进行修改，不会对实参有任何改变
//因为形参根本就没有访问到实参的那块内存空间，只是复制了一份跟实参一样的数据
//若要改变实参，那就必须将实参的地址传给形参
//那这个时候，形参就有实参的地址了，就可以访问实参的那块内存空间
//对实参的地址进行解引用可以访问到实参的那块内存空间所存放的数据
//而此时形参也有实参那块内存空间的地址，对这块地址进行解引用也能访问到实参的那块内存空间的数据
//既然可以访问到数据，那就必然可以修改了

//尾插
void SListpushback(SLnode** head,SLTdatatype x)
{
	//为插入的数据创建一个结点
	SLnode* node = (SLnode*)malloc(sizeof(SLnode));
	assert(node);
	SLnode* tem = *head;

	//将插入的数据赋值给插入结点的数据域
	node->data = x;
	//将插入的结点的指针域赋值NULL，这样新插入的结点就变成了尾结点了
	node->next = NULL;
	if (*head==NULL)
	{
		//判断头结点是否为NULL
		//若不判断，当头结点为NULL时，不满足下面进入循环的条件，插入失败
		// 
		//若为NULL，则直接将新创建的结点赋值给头结点
		*head = node;
	}
	else
	{
		//尾结点的特征为 指针域的值为NULL
		//所以 只要找到指针域为NULL的结点就是尾结点
		while (tem->next != NULL)
		{
			tem = tem->next;
		}
		//将插入的结点的地址赋值给尾结点的指针域
		tem->next = node;
	}
	
}

//头插
void SListpushfront(SLnode** head, SLTdatatype x)
{
	SLnode* node = newnode(x);
	node->next = *head;
	*head = node;
	//头插不需要判断头结点是否为NULL，因为最后头结点指针会移动到新的头结点上

	//if (*head==NULL)
	//{
	//	//将新的头结点赋值给*head
	//	*head = node;
	//}
	//else
	//{
	//	node->next = *head;
	//	//将新的头结点赋值给*head
	//	*head = node;
	//}

}

//尾删
void SListdelback(SLnode** head)
{
	assert(*head);
	//方法1
	if ((*head)->next==NULL)
	{
		//只有一个结点
		free(*head);
		*head = NULL;
	}
	else
	{
		//有多个结点
		SLnode* tempre = NULL;
		SLnode* tem = *head;
		while (tem->next != NULL)
		{
			tempre = tem;
			tem = tem->next;
		}
		free(tem);
		tempre->next = NULL;
	}

	//方法2
	/*SLnode* tem = *head;
	while (tem->next->next!= NULL)
	{
		tem = tem->next;
	}

	free(tem->next);
	tem->next = NULL;*/

}

//头删
void SListdelfront(SLnode** head)
{
	assert(*head);
	SLnode* delnode = (*head)->next;
	free(*head);
	*head = delnode;

}

//查找
SLnode* SListfind(SLnode* head,SLTdatatype x)
{
	while (head)
	{
		if (head->data==x)
		{
			return head;
		}
		head = head->next;
	}
	return NULL;
}

//在pos位置之前插入
void SListpushpos(SLnode** head,SLnode*pos,SLTdatatype x)
{
	assert(pos);
	assert(head);
	SLnode* node = newnode(x);
	SLnode* tem = *head;
	if (pos==*head)
	{
		SListpushfront(head, x);
	}
	else
	{
		while (tem->next!=pos)
		{
			tem = tem->next;
		}
		node->next = tem->next;
		tem->next = node;
	}
	
}

//在pos位置之前删除
void SListdelpos(SLnode**head,SLnode* pos)
{
	assert(pos);
	assert(head);
	SLnode* tem = *head;
	SLnode* temprev = NULL;
	if (pos==*head)
	{
		return;
	}
	else
	{
		while (tem->next!=pos)
		{
			temprev = tem;
			tem = tem->next;
		}
		temprev->next = pos;
		free(tem);
		tem = NULL;
	}

}