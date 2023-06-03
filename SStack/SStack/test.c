#define _CRT_SECURE_NO_WARNINGS
#include"SStack.h"

void test()
{
	Sp* s= SStackinit();
	SStackpush(&s, 1);
	SStackpush(&s, 2);
	SStackpush(&s, 3);
	SStackpush(&s, 4);
	SStackpush(&s, 5);
	SStackpush(&s, 6);
	

	while (SStackempty(s))
	{
		printf("%d ", SStacktop(s));
		SStackpop(&s);
	}


	SStackdestory(s);


}
int main()
{	
	test();
	return 0;
}