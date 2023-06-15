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


//层序遍历
void BinaryTreeLevelOrder(BTNode* root);

//判断是否为完全二叉树
bool BinaryTreeComplete(BTNode* root);



//计数方法1：
void BinartSize(BTNode* root, int* pn);

//计数方法2：
int BinaryTreeSize(BTNode* root);

//计算叶子节点的个数
int BinaryTreeLeafsize(BTNode* root);

//计算第k层的节点个数
int BinaryTreeLevelKSize(BTNode* root, int k);

//求二叉树的深度
int BinaryTreeDepth(BTNode* root);

//查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, Datatype x);


