#define _CRT_SECURE_NO_WARNINGS
#include"SList.h"



void test01()
{
	//������ĳ������
	// 
	//Ϊһ���������ڴ�ռ�
	SLnode* n1 = (SLnode*)malloc(sizeof(SLnode));
	//����n1 �Ŀռ�  ��ֹn1���ٿռ�ʧ�ܣ����ؿ�ָ��
	assert(n1);

	SLnode* n2 = (SLnode*)malloc(sizeof(SLnode));
	assert(n2);

	SLnode* n3 = (SLnode*)malloc(sizeof(SLnode));
	assert(n3);

	SLnode* n4 = (SLnode*)malloc(sizeof(SLnode));
	assert(n4);

	//��ÿ������������ֵ
	// -> �� '.'�����ö��ǶԽṹ���Ա���з���
	// n1->data  �ȼ��� (*n1).data
	//n1 ��n4 ��Щ����ָ�ĵ������ĵ�ַ��Ҳ����ָ�������
	n1->data = 1;
	n2->data = 2;
	n3->data = 3;
	n4->data = 4;

	//��ÿ������ָ����ֵ
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	//n4Ϊ���һ����㣬�ڵ������У����һ����㸳NULL
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
	//����ֵΪ5�Ľ��ĵ�ַ
	SLnode*tem=SListfind(n1, 5);
	printf("%d  %p\n", tem->data, tem);

	//��ֵΪ4�Ľ��ǰ�����һ����6
	SLnode* pos = SListfind(n1, 4);
	if (pos)
	{
		SListpushpos(&n1, pos, 6);
	}
	SLprint(n1);

	//ɾ��ֵΪ3�Ľ���ǰһ�����
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
	//��ͷ���ΪNULLʱ��Ҫ������Ľ��ֱ�Ӹ�ֵ��ͷ���
	//ֱ�Ӵ�p �Ǵ�ֵ���ã�����ʵ�ʸı�p 
	//���Ա��봫p�ĵ�ַ��Ȼ���������ã��ٽ�����Ľ�㸳ֵ��p
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

