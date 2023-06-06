#define _CRT_SECURE_NO_WARNINGS
#include"DList.h"



void test()
{
	
	
	//plist为哨兵位，不存储有效数据
	DList* plist =DListinit();
	DListpushback(plist, 1);
	DListpushback(plist, 2);
	DListpushback(plist, 3);
	DListpushback(plist, 4);
	DListpushback(plist, 5);
	DListprint(plist);
	DListdelback(plist);
	DListprint(plist);
	DListpushfront(plist, 6);
	DListprint(plist);
	DListdelfront(plist);
	DListprint(plist);
	printf("phead: %p\n", plist);
	DList* n=DListcheck(plist, 3);
	if (n)
		printf("%d %p %p \n", n->data, n->next, n->prev);
	DList*pos= DListcheck(plist, 1);
	if(pos)
		DListdelpos(plist, pos);
	DListprint(plist);
	DList* p = DListcheck(plist, 2);
	if (p)
		DListpushposfront(p, 7);
	DListprint(plist);
	DList* po = DListcheck(plist, 2);
	if (po)
		po->data = 0;
	DListprint(plist);

}

void test1()
{
	DList* plist = DListinit();
	DListpushfront(plist, 6);
	DListprint(plist);
}
int main()
{
	test();
	//test1();
	return 0;
}