#define _CRT_SECURE_NO_WARNINGS
#include"SList.h"



void test01()
{
	//单链表的初步理解
	// 
	//为一个结点分配内存空间
	SLnode* n1 = (SLnode*)malloc(sizeof(SLnode));
	//断言n1 的空间  防止n1开辟空间失败，返回空指针
	assert(n1);

	SLnode* n2 = (SLnode*)malloc(sizeof(SLnode));
	assert(n2);

	SLnode* n3 = (SLnode*)malloc(sizeof(SLnode));
	assert(n3);

	SLnode* n4 = (SLnode*)malloc(sizeof(SLnode));
	assert(n4);

	//给每个结点的数据域赋值
	// -> 和 '.'的作用都是对结构体成员进行访问
	// n1->data  等价于 (*n1).data
	//n1 到n4 这些都是指的单个结点的地址（也就是指针变量）
	n1->data = 1;
	n2->data = 2;
	n3->data = 3;
	n4->data = 4;

	//给每个结点的指针域赋值
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	//n4为最后一个结点，在单链表中，最后一个结点赋NULL
	n4->next = NULL;

	SLprint(n1);
	SListpushback(&n1, 5);
	SLprint(n1);
	SListpushfront(&n1, 9);
	SLprint(n1);
	//SListdelback(n1);
	SLprint(n1);
	SListdelfront(&n1);
	SLprint(n1);
	//查找值为5的结点的地址
	SLnode*tem=SListfind(n1, 5);
	printf("%d  %p\n", tem->data, tem);

	//在值为4的结点前面插入一个数6
	SLnode* pos = SListfind(n1, 4);
	if (pos)
	{
		SListpushpos(&n1, pos, 6);
	}
	SLprint(n1);

	//删除值为3的结点的前一个结点
	SLnode* pos1 = SListfind(n1, 3);
	if (pos1)
	{
		SListdelpos(&n1, pos1);
	}
	SLprint(n1);
	SLnode* pos2 = SListfind(n1, 3);
	if (pos2)
	{
		pos2->data = 9;
	}
	SLprint(n1);
}

void test02()
{
	//当头结点为NULL时，要将插入的结点直接赋值给头结点
	//直接传p 是传值调用，不会实际改变p 
	//所以必须传p的地址，然后对其解引用，再将插入的结点赋值给p
	SLnode* p = NULL;

	SListpushback(&p, 5);
	SListpushback(&p, 6);
	SListpushback(&p, 7);
	SListpushback(&p, 8);
	SListpushback(&p, 9);
	SLprint(p);

	SListpushfront(&p, 7);
	SLprint(p);


}

int main()
{
	test01();
	//test02();
	return 0;
}

