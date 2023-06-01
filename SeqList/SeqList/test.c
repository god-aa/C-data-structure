#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"

void test()
{
	SL s;
	SLinit(&s);
	SLback(&s, 2);
	SLback(&s, 3);
	SLback(&s, 4);
	SLback(&s, 5);
	SLback(&s, 7);
	SLback(&s, 2);
	SLback(&s, 2);
	SLfornt(&s, 1);
	SLpos(&s, 3, 6);
	SLdelpos(&s, 1);
	print(&s);
	SLdestory(&s);
}
int main() 
{
	test();
	return 0;
}