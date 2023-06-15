#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int Datatype;

typedef struct BinaryTreeNode
{
	Datatype data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

BTNode* BuyNode(Datatype x);

BTNode* CreatBinaryTree();

void PreOrder(BTNode* root);
void InOrder(BTNode* root);
void postOrder(BTNode* root);

void BinaryTreedestory(BTNode* root);


//�������
void BinaryTreeLevelOrder(BTNode* root);

//�ж��Ƿ�Ϊ��ȫ������
bool BinaryTreeComplete(BTNode* root);



//��������1��
void BinartSize(BTNode* root, int* pn);

//��������2��
int BinaryTreeSize(BTNode* root);

//����Ҷ�ӽڵ�ĸ���
int BinaryTreeLeafsize(BTNode* root);

//�����k��Ľڵ����
int BinaryTreeLevelKSize(BTNode* root, int k);

//������������
int BinaryTreeDepth(BTNode* root);

//����ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, Datatype x);


