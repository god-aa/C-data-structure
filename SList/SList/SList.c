#define _CRT_SECURE_NO_WARNINGS
#include"SList.h"

void SLprint(SLnode* head)
{
	assert(head);
	SLnode* cur = head;
	while (cur!=NULL)
	{	
		//�����ǰָ��curָ��Ľ���������
		printf("%d", cur->data);

		//��ǰָ���ָ�����ŵ�����һ�����ĵ�ַ
		//����һ�����ĵ�ַ��ֵ��ָ��ǰ����ָ��cur
		//Ҳ�����ý��ָ��cur��ͷ����λ���ƶ�����һ������λ��
		cur = cur->next;
	}
	printf("\n");
}
//��ӡ������ֻҪ��һ��ָ���ԭ��
//һ��ָ��head���βΣ�Ҳ�Ǳ�����������SLnode*��
// ��ʵ�ε�����Ҳ��SLnode* ʵ�κ��βε�����һ�������ڴ�ֵ����
// 

//�����½��
SLnode* newnode(SLTdatatype x)
{
	SLnode* node = (SLnode*)malloc(sizeof(SLnode));
	assert(node);
	node->data = x;
	node->next = NULL;
	return node;
}

//�޸�������Ҫ������ָ���ԭ��
//���β���һ��ָ�룬��������������Ҳ��һ��ָ�����ͣ�
//Ҳ����˵�βκ�ʵ�ε�����һ�����������Ǵ�ֵ������
//���Ǵ�ֵ���ã��β�ֻ��ʵ�ε�һ����ʱ������
//���βν����޸ģ������ʵ�����κθı�
//��Ϊ�βθ�����û�з��ʵ�ʵ�ε��ǿ��ڴ�ռ䣬ֻ�Ǹ�����һ�ݸ�ʵ��һ��������
//��Ҫ�ı�ʵ�Σ��Ǿͱ��뽫ʵ�εĵ�ַ�����β�
//�����ʱ���βξ���ʵ�εĵ�ַ�ˣ��Ϳ��Է���ʵ�ε��ǿ��ڴ�ռ�
//��ʵ�εĵ�ַ���н����ÿ��Է��ʵ�ʵ�ε��ǿ��ڴ�ռ�����ŵ�����
//����ʱ�β�Ҳ��ʵ���ǿ��ڴ�ռ�ĵ�ַ��������ַ���н�����Ҳ�ܷ��ʵ�ʵ�ε��ǿ��ڴ�ռ������
//��Ȼ���Է��ʵ����ݣ��Ǿͱ�Ȼ�����޸���

//β��
void SListpushback(SLnode** head,SLTdatatype x)
{
	//Ϊ��������ݴ���һ�����
	SLnode* node = (SLnode*)malloc(sizeof(SLnode));
	assert(node);
	SLnode* tem = *head;

	//����������ݸ�ֵ���������������
	node->data = x;
	//������Ľ���ָ����ֵNULL�������²���Ľ��ͱ����β�����
	node->next = NULL;
	if (*head==NULL)
	{
		//�ж�ͷ����Ƿ�ΪNULL
		//�����жϣ���ͷ���ΪNULLʱ���������������ѭ��������������ʧ��
		// 
		//��ΪNULL����ֱ�ӽ��´����Ľ�㸳ֵ��ͷ���
		*head = node;
	}
	else
	{
		//β��������Ϊ ָ�����ֵΪNULL
		//���� ֻҪ�ҵ�ָ����ΪNULL�Ľ�����β���
		while (tem->next != NULL)
		{
			tem = tem->next;
		}
		//������Ľ��ĵ�ַ��ֵ��β����ָ����
		tem->next = node;
	}
	
}

//ͷ��
void SListpushfront(SLnode** head, SLTdatatype x)
{
	SLnode* node = newnode(x);
	node->next = *head;
	*head = node;
	//ͷ�岻��Ҫ�ж�ͷ����Ƿ�ΪNULL����Ϊ���ͷ���ָ����ƶ����µ�ͷ�����

	//if (*head==NULL)
	//{
	//	//���µ�ͷ��㸳ֵ��*head
	//	*head = node;
	//}
	//else
	//{
	//	node->next = *head;
	//	//���µ�ͷ��㸳ֵ��*head
	//	*head = node;
	//}

}

//βɾ
void SListdelback(SLnode** head)
{
	assert(*head);
	//����1
	if ((*head)->next==NULL)
	{
		//ֻ��һ�����
		free(*head);
		*head = NULL;
	}
	else
	{
		//�ж�����
		SLnode* tempre = NULL;
		SLnode* tem = *head;
		while (tem->next != NULL)
		{
			tempre = tem;
			tem = tem->next;
		}
		free(tem);
		tempre->next = NULL;
	}

	//����2
	/*SLnode* tem = *head;
	while (tem->next->next!= NULL)
	{
		tem = tem->next;
	}

	free(tem->next);
	tem->next = NULL;*/

}

//ͷɾ
void SListdelfront(SLnode** head)
{
	assert(*head);
	SLnode* delnode = (*head)->next;
	free(*head);
	*head = delnode;

}

//����
SLnode* SListfind(SLnode* head,SLTdatatype x)
{
	while (head)
	{
		if (head->data==x)
		{
			return head;
		}
		head = head->next;
	}
	return NULL;
}

//��posλ��֮ǰ����
void SListpushpos(SLnode** head,SLnode*pos,SLTdatatype x)
{
	assert(pos);
	assert(head);
	SLnode* node = newnode(x);
	SLnode* tem = *head;
	if (pos==*head)
	{
		SListpushfront(head, x);
	}
	else
	{
		while (tem->next!=pos)
		{
			tem = tem->next;
		}
		node->next = tem->next;
		tem->next = node;
	}
	
}

//��posλ��֮ǰɾ��
void SListdelpos(SLnode**head,SLnode* pos)
{
	assert(pos);
	assert(head);
	SLnode* tem = *head;
	SLnode* temprev = NULL;
	if (pos==*head)
	{
		return;
	}
	else
	{
		while (tem->next!=pos)
		{
			temprev = tem;
			tem = tem->next;
		}
		temprev->next = pos;
		free(tem);
		tem = NULL;
	}

}