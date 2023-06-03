#define _CRT_SECURE_NO_WARNINGS
#include"SeqStack.h"


void test()
{
	ST s;
	Stackinit(&s);
	Stackpush(&s, 1);
	Stackpush(&s, 2);
	Stackpush(&s, 3);
	Stackpush(&s, 4);
	Stackpush(&s, 5);
	Stackpush(&s, 6);
	printf("%d ", Stacksize(&s));
	while (Stackempty(&s))
	{
		printf("%d ", Stacktop(&s));
		Stackpop(&s);
	}
	Stackdestory(&s);
}

int main()
{
	test();
	return 0;
}