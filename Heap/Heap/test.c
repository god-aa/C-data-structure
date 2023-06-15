#define _CRT_SECURE_NO_WARNINGS
#include"Heap.h"

void test()
{
	Hd s;
	Hdinit(&s);
	int a[] = { 8,9,3,4,2,6,4,1,0,5,6 };
	for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
	{
		Hdpush(&s, a[i]);
	}
	Hdprint(&s);
	printf("\n");
	/*printf("%d \n", Hdtop(&s));
	Hdprint(&s);*/
	//Heapsort(a, sizeof(a) / sizeof(a[0]));
	Heapsort1(a, sizeof(a) / sizeof(a[0]));
	Hddestory(&s);
}

void TestTopk()
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int) * n);
	srand(time(0));
	for (size_t i = 0; i < n; ++i)
	{
		a[i] = rand() % 1000000;
	}
	//
	a[5] = 1000000 + 1;
	a[1231] = 1000000 + 2;
	a[531] = 1000000 + 3;
	a[5121] = 1000000 + 4;
	a[115] = 1000000 + 5;
	a[2335] = 1000000 + 6;
	a[9999] = 1000000 + 7;
	a[76] = 1000000 + 8;
	a[423] = 1000000 + 9;
	a[3144] = 1000000 + 10;

	TOPK(a, n, 10);
	
}

int main()
{
	test();
	//TestTopk();
	return 0;
}