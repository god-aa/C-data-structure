#define _CRT_SECURE_NO_WARNINGS
#include"Heap.h"


//��ʼ��
void Hdinit(Hd*p)
{
	p->arr = NULL;
	p->size = p->capacity = 0;
}

//����
void Hddestory(Hd* p)
{
	assert(p);
	free(p->arr);
	p->capacity = p->size = 0;
}

//����������
void Heapsort(int*a,int sz)
{
	Hd h;
	Hdinit(&h);
	for (int i = 0; i < sz; i++)
	{
		Hdpush(&h, a[i]);
	}
	//�Ѷ�������С�������Ѷ���ֵ��a
	//��pop�����µĶѶ����ǵڶ�С����
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
	//�������ϵ�������С��
	//ÿѡ��һ����С������Ҫ�����½���
	//�����ʱ�临�Ӷ�ΪO(N^2)�����Ƽ�

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

	//�����  ʱ�临�Ӷ�ΪO(N)
	for (int i = (n-1-1)/2; i >=0; i--)
	{
		Adjustdown(a, n, i);
	}

	//ѡһ���Ѷ�������logN  n����������ʱ�临�Ӷ�Ϊ  N*logN
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

//TOPK����
//��N����������ǰk����  �� ��k��������С��ǰk����
void TOPK(int* arr, int n, int k)
{
	assert(arr);
	//����һ������Ϊk�Ķѣ�����ʼ�������ڱ���arr�����е�k������
	Hd s;
	Hdinit(&s);
	for (int i = 0; i < k; i++)
	{
		Hdpush(&s, arr[i]);
	}
	//���Ѷ�������ʣ�µ�n-k�����Ƚϣ�С�ھ��滻
	//Ȼ���ٲ������µ�������֤�Ѷ�����Сֵ
	for (int j = k; j < n; j++)
	{
		if (Hdtop(&s)<arr[j])
		{
			s.arr[0] = arr[j];
			Adjustdown(s.arr, k,0);
		}
	}
	//��ӡ
	for (int i = 0; i < k; i++)
	{
		printf("%d ", s.arr[i]);
	}
	Hddestory(&s);
}

//���ϵ���
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

//���µ���
void Adjustdown(Datatype* pa, int sz,int parent)
{
	//�����ӵ��±�
	int child = parent * 2 + 1;
	while (child<sz)
	{
		//child+1Ϊ�Һ��ӵ��±꣬Ҫ�����Һ����Ƿ���ڵ����
		//ѡ��ֵС�ĺ���
		// > ѡ��ֵС�ĺ���   <  ѡ��ֵ��ĺ���
		//�ٸ������游�ڵ���ӽڵ�ıȽϣ������Ǵ�ѻ���С��
		//����ѡ�� ֵ��ĺ��ӣ���ȥ��С��
		if (child+1<sz&&pa[child]<pa[child+1])
		{
			child++;
		}
		//�жϺ��ӽڵ��Ƿ���ڸ��ڵ�
		//�����򲻽�����С���򽻻�
		// > ��С��   <  �����
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

//����
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

//ɾ��---ɾ���Ѷ�������
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

//����Ԫ�ظ���
int Hdsize(Hd* p)
{
	assert(p);
	return p->size;
}

//ȡ�Ѷ���Ԫ��
Datatype Hdtop(Hd* p)
{
	assert(p);
	assert(!Hdempty(p));
	return p->arr[0];
}

//�п�
bool Hdempty(Hd* p)
{
	assert(p);
	return p->size==0;
}

//��ӡ
void Hdprint(Hd* p)
{
	for (int i = 0; i < p->size; i++)
	{
		printf("%d ",p->arr[i]);
	}
}

