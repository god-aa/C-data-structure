#define _CRT_SECURE_NO_WARNINGS
#include"Queue.h"

void test()
{
	PQ s;
	Queueinit(&s);
	Queuepush(&s, 1);
	Queuepush(&s, 2);
	Queuepush(&s, 3);
	Queuepush(&s, 4);
	Queuepush(&s, 5);
	Queuepush(&s, 6);
	printf("%d ", Queuefront(&s));
	printf("%d \n", Queueback(&s));
	printf("%d \n", Queuesize(&s));
	while (Queueempty(&s))
	{
		printf("%d ", Queuefront(&s));
		Queuepop(&s);
	}
	Queuedestroy(&s);

}

int main()
{
	test();
	return 0;
}