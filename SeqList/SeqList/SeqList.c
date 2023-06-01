#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"


//��ʼ��
void SLinit(SL* ps)
{
	ps->data = NULL;
	ps->capacity = ps->sz = 0;
}

//����
void SLdestory(SL* ps)
{
	if (ps->data)
	{
		free(ps->data);
		ps->data = NULL;
		ps->capacity = ps->sz = 0;
	}
}

//����
SLtype* Addmemory(SL*p)
{
	SLtype* tem = (SLtype*)realloc(p->data, (p->capacity + CADD)*sizeof(SLtype));
	if (tem == NULL)
	{
		perror("realloc");
		exit(-1);
	}
	return tem;
}

//��ӡ
void print(SL* ps)
{
	for (int i = 0; i < ps->sz; i++)
	{
		printf("%d\n", ps->data[i]);
	}
}
//ͷ��
void SLfornt(SL* ps, SLtype x)
{
	assert(ps);
	if (ps->capacity == ps->sz)
	{
		SLtype* tem = Addmemory(ps);
		ps->data = tem;
		ps->capacity += CADD;
	}
	else
	{
		for (int i = ps->sz; i > 0; i--)
		{
			ps->data[i] = ps->data[i - 1];
		}
		ps->data[0] = x;
		ps->sz++;
	}
}

//β��
void SLback(SL* ps,SLtype x)
{
	assert(ps);
	if (ps->capacity == ps->sz)
	{
		SLtype* tem = Addmemory(ps);
		ps->data = tem;
		ps->capacity += CADD;
	}
	ps->data[ps->sz] = x;
	ps->sz++;
}

//��ָ��λ�ò���
void SLpos(SL*ps,int pos,SLtype x)
{
	assert(ps!=NULL&&pos > 0 && pos < ps->sz);
	if (pos == 0)
		SLfornt(ps, x);
	if(pos==ps->sz)
		SLback(ps, x);
	if (ps->capacity == ps->sz)
	{
		SLtype* tem = Addmemory(ps);
		ps->data = tem;
		ps->capacity += CADD;
	}
	else
	{
		for (int i = ps->sz; i >pos; i--)
		{
			ps->data[i] = ps->data[i - 1];
		}
		ps->data[pos] = x;
		ps->sz++;
	}

}

//��ָ��λ��ɾ��
void SLdelpos(SL*ps,int pos)
{
	assert(ps!=NULL&& pos < ps->sz && pos >= 0);
	for (int i = pos; i < ps->sz-1; i++)
	{
		ps->data[i] = ps->data[i + 1];
	}
	ps->sz--;
}

//ͷɾ
void DeleteFront(SL*ps)
{
	SLdelpos(ps, 0);
}


//βɾ
void DeleteBack(SL* ps)
{
	if(ps->sz!=0)
		ps->sz--;
	else
	{
		return;
	}
}

//����
void SLcheck(SL*ps,SLtype x)
{	
	int tem = 0;
	for (int i = 0; i < ps->sz; i++)
	{
		if (ps->data[i] == x)
		{
			tem = i;
			break;
		}
	}
	printf("����Ԫ�ص��±�Ϊ��%d", tem);
}


