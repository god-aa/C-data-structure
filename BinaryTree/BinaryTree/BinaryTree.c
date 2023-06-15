#define _CRT_SECURE_NO_WARNINGS
#include"BinaryTree.h"
#include"Queue.h"

BTNode* BuyNode(Datatype x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	assert(node);
	node->data = x;
	node->right = node->left = NULL;
	return node;
}

BTNode* CreatBinaryTree()
{
	BTNode* nodeA = BuyNode('A');
	BTNode* nodeB = BuyNode('B');
	BTNode* nodeC = BuyNode('C');
	BTNode* nodeD = BuyNode('D');
	BTNode* nodeE = BuyNode('E');
	BTNode* nodeF = BuyNode('F');

	nodeA->left = nodeB;
	nodeA->right = nodeC;
	nodeB->left = nodeD;
	nodeC->left = nodeE;
	nodeC->right = nodeF;

	//返回根节点
	return nodeA;
}

//二叉树的销毁
void BinaryTreedestory(BTNode* root)
{
	if (root==NULL)
	{
		return;
	}

	BinaryTreedestory(root->left);
	BinaryTreedestory(root->right);
	free(root);
}

//前序遍历
void PreOrder(BTNode* root)
{
	if (root==NULL)
	{
		printf("NULL ");
		return;
	}

	printf("%c ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

//中序遍历
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
}

//后序遍历
void postOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	postOrder(root->left);
	postOrder(root->right);
	printf("%c ", root->data);

}

//层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	PQ q;
	Queueinit(&q);
	Queuepush(&q, root);
	while (Queueempty(&q))
	{
		BTNode* front = Queuefront(&q);
		Queuepop(&q);
		printf("%c ", front->data);

		if (front->left)
		{
			Queuepush(&q, front->left);
		}
		if (front->right)
		{
			Queuepush(&q, front->right);
		}

	}

	//队列里面放数据的时候不能只放节点的值，
	//这样会找不到该节点的孩子节点
	//故应该放节点或节点的地址
	// 这里放节点的地址
	//所以队列存储的数据类型就要是节点的地址数据类型
	//所以需将队列项目中的 typedef int Datatype 中的int 改为 BTnode* 


	Queuedestroy(&q);
}

//判断二叉树是否为完全二叉树
bool BinaryTreeComplete(BTNode* root)
{
	PQ q;
	Queueinit(&q);
	Queuepush(&q, root);
	while (Queueempty(&q))
	{
		BTNode* front = Queuefront(&q);
		Queuepop(&q);
		if (front==NULL)
		{
			break;
		}
		else
		{
			Queuepush(&q, front->left);
			Queuepush(&q, front->right);
		}
	}
	//遇到空后，检查后面的节点
	//若全为空，则是完全二叉树
	//若存在非空，则不是完全二叉树
	while (Queueempty(&q))
	{
		BTNode* front = Queuefront(&q);
		Queuepop(&q);
		if (front)
		{
			Queuedestroy(&q);
			return false;
		}
	}
	Queuedestroy(&q);
	return true;
}

//计数方法1：
void BinartSize(BTNode* root, int* pn)
{
	if (root==NULL)
	{
		return;
	}
	++(*pn);
	BinartSize(root->left, pn);
	BinartSize(root->right, pn);
}

//计数方法2：
int BinaryTreeSize(BTNode* root)
{
	return root == NULL ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

//叶子节点的个数
//叶子节点的左右子树都为NULL,故递归的条件可以设置为  
//当一个节点的左右子树都为NULL时，返回1，
//总的叶子节点的个数  就等于根节点的左孩子的叶子节点数加右孩子的叶子节点数
int BinaryTreeLeafsize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left==NULL&&root->right==NULL)
	{
		return 1;
	}
	return	 BinaryTreeLeafsize(root->left) + BinaryTreeLeafsize(root->right);
}


//求第k层的节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	assert(k >= 1);
	//root为NULL时，没有节点
	if (root==NULL)
	{
		return 0;
	}

	//当程序走到这里时，就表示root不为空，这时k等于几就是第几层
	//k等于1时，表示第一层，即根节点，有且只有一个节点，返回1
	if (k==1)
	{
		return 1;
	}

	//当程序走到了这里，说明root不为空，且k!=1
	//说明root这棵树的第k层的节点在子树里面，
	// 但是在子树里面的第k层的节点数是未知的 第一层的节点数有且只有一个
	//转换成求root这棵树的左右子树的第k-1层的节点数
	return	BinaryTreeLevelKSize(root->left, k - 1)+BinaryTreeLevelKSize(root->right,k-1);
	//例如
	//求A的第三层的节点数，就转换为求A的左子树的第二层节点数和右子树的第二层的节点数之和
	//又可以转换成求  A的左子树  的左子树的第一层的节点数 和 右子树的第一层的节点数 之和
	//加上
	//A的右子树  的  左子树的第一层的节点数 和 右子树的第一层的节点数 之和
}

//求树的深度
//当前树的深度等于左子树和右子树比较，大的加一
int BinaryTreeDepth(BTNode* root)
{
	if (root==NULL)
	{
		return 0;
	}

	//设置两个变量保存结果，防止返回时重复遍历
	int leftdepth = BinaryTreeDepth(root->left);
	int rightdepth = BinaryTreeDepth(root->right);

	//当leftdepth 等于rightdepth 时，也就是访问到最后一个节点时，
	//leftdepth ==0  rightdepth==0  返回值就是他俩随便一个加1返回

	return leftdepth > rightdepth ? leftdepth + 1 : rightdepth + 1;
}

BTNode* BinaryTreeFind(BTNode* root, Datatype x)
{
	if (root==NULL)
	{
		return NULL;
	}
	if (root->data==x)
	{
		//如果找到了，就直接返回
		return root;
	}

	//程序走到这儿，说明还没找到，那就去根节点的左树去找
	//若是找到了，则直接返回，没有找到返回NULL
	//保存结果，防止重复遍历
	BTNode* left = BinaryTreeFind(root->left, x);
	if (left)
	{
		return left;
	}
	//左子树没找到，那就直接去右子树找，
	//若是找到了，则直接返回，没有找到返回NULL
	//保存结果，防止重复遍历
	BTNode* right = BinaryTreeFind(root->right, x);
	if (right)
	{
		return right;
	}
	//左右子树都没找到，说明该节点不存在
	return NULL;
}