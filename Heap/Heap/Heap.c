#define _CRT_SECURE_NO_WARNINGS
#include"Heap.h"


//初始化
void Hdinit(Hd*p)
{
	p->arr = NULL;
	p->size = p->capacity = 0;
}

//销毁
void Hddestory(Hd* p)
{
	assert(p);
	free(p->arr);
	p->capacity = p->size = 0;
}

//堆排序问题
void Heapsort(int*a,int sz)
{
	Hd h;
	Hdinit(&h);
	for (int i = 0; i < sz; i++)
	{
		Hdpush(&h, a[i]);
	}
	//堆顶就是最小数，将堆顶赋值给a
	//再pop掉，新的堆顶就是第二小的数
	for (int i = 0; i < sz; i++)
	{
		a[i] = Hdtop(&h);
		Hdpop(&h);
	}
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void Heapsort1(int* a, int n)
{
	//采用向上调整，建小堆
	//每选出一个最小的数都要再重新建堆
	//整体的时间复杂度为O(N^2)，不推荐

	/*for (int i = 0; i <n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			Adjustup(a, j);
		}
		int tmp = a[0];
		a[0] = a[n-1-i];
		a[n-1-i] = tmp;
	}*/

	//建大堆  时间复杂度为O(N)
	for (int i = (n-1-1)/2; i >=0; i--)
	{
		Adjustdown(a, n, i);
	}

	//选一个堆顶，用了logN  n个数，所以时间复杂度为  N*logN
	for (int i = n-1; i >=0; i--)
	{
		int tem = a[0];
		a[0] = a[i];
		a[i] = tem;
		Adjustdown(a, i, 0);
	}

	for (int i = 0; i <n; i++)
	{
		printf("%d ", a[i]);
	}

}

//TOPK问题
//求N个数中最大的前k个数  或 求k个数中最小的前k个数
void TOPK(int* arr, int n, int k)
{
	assert(arr);
	//建立一个长度为k的堆，并初始化，用于保存arr数组中的k个数据
	Hd s;
	Hdinit(&s);
	for (int i = 0; i < k; i++)
	{
		Hdpush(&s, arr[i]);
	}
	//将堆顶的数跟剩下的n-k个数比较，小于就替换
	//然后再采用向下调整，保证堆顶是最小值
	for (int j = k; j < n; j++)
	{
		if (Hdtop(&s)<arr[j])
		{
			s.arr[0] = arr[j];
			Adjustdown(s.arr, k,0);
		}
	}
	//打印
	for (int i = 0; i < k; i++)
	{
		printf("%d ", s.arr[i]);
	}
	Hddestory(&s);
}

//向上调整
void Adjustup(Datatype* pa, int sz)
{
	int child = sz;
	int parent = (child - 1) / 2;
	while (child)
	{
		if (pa[child]>pa[parent])
		{
			int tmp = pa[child];
			pa[child] = pa[parent];
			pa[parent] = tmp;
		}
		else
		{
			break;
		}
		child = parent;
		parent = (child - 1) / 2;
	}
}

//向下调整
void Adjustdown(Datatype* pa, int sz,int parent)
{
	//找左孩子的下标
	int child = parent * 2 + 1;
	while (child<sz)
	{
		//child+1为右孩子的下标，要考虑右孩子是否存在的情况
		//选出值小的孩子
		// > 选出值小的孩子   <  选出值大的孩子
		//再根据下面父节点和子节点的比较，决定是大堆还是小堆
		//不能选出 值大的孩子，再去排小堆
		if (child+1<sz&&pa[child]<pa[child+1])
		{
			child++;
		}
		//判断孩子节点是否大于父节点
		//大于则不交换，小于则交换
		// > 建小堆   <  建大堆
		if (pa[parent]>pa[child])
		{
			int tmp = pa[child];
			pa[child] = pa[parent];
			pa[parent] = tmp;
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//插入
void Hdpush(Hd* p,Datatype x)
{
	assert(p);
	if (p->capacity==p->size)
	{
		int newcapacity = p->capacity == 0 ? 4 : sizeof(p->arr) * 2;
		Datatype* tmp = (Datatype*)realloc(p->arr, sizeof(Datatype) * newcapacity);
		assert(tmp);
		p->arr = tmp;
		p->capacity = newcapacity;
	}
	p->arr[p->size] = x;
	p->size++;
	Adjustup(p->arr,p->size-1);
}

//删除---删除堆顶的数据
void Hdpop(Hd* p)
{
	assert(p);
	assert(!Hdempty(p));
	Datatype tmp = p->arr[p->size - 1];
	p->arr[p->size - 1] = p->arr[0];
	p->arr[0] = tmp;
	p->size--;
	Adjustdown(p->arr,p->size-1,0);
}

//堆中元素个数
int Hdsize(Hd* p)
{
	assert(p);
	return p->size;
}

//取堆顶的元素
Datatype Hdtop(Hd* p)
{
	assert(p);
	assert(!Hdempty(p));
	return p->arr[0];
}

//判空
bool Hdempty(Hd* p)
{
	assert(p);
	return p->size==0;
}

//打印
void Hdprint(Hd* p)
{
	for (int i = 0; i < p->size; i++)
	{
		printf("%d ",p->arr[i]);
	}
}

