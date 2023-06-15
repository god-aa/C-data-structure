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

	//���ظ��ڵ�
	return nodeA;
}

//������������
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

//ǰ�����
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

//�������
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

//�������
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

//�������
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

	//������������ݵ�ʱ����ֻ�Žڵ��ֵ��
	//�������Ҳ����ýڵ�ĺ��ӽڵ�
	//��Ӧ�÷Žڵ��ڵ�ĵ�ַ
	// ����Žڵ�ĵ�ַ
	//���Զ��д洢���������;�Ҫ�ǽڵ�ĵ�ַ��������
	//�����轫������Ŀ�е� typedef int Datatype �е�int ��Ϊ BTnode* 


	Queuedestroy(&q);
}

//�ж϶������Ƿ�Ϊ��ȫ������
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
	//�����պ󣬼�����Ľڵ�
	//��ȫΪ�գ�������ȫ������
	//�����ڷǿգ�������ȫ������
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

//��������1��
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

//��������2��
int BinaryTreeSize(BTNode* root)
{
	return root == NULL ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

//Ҷ�ӽڵ�ĸ���
//Ҷ�ӽڵ������������ΪNULL,�ʵݹ��������������Ϊ  
//��һ���ڵ������������ΪNULLʱ������1��
//�ܵ�Ҷ�ӽڵ�ĸ���  �͵��ڸ��ڵ�����ӵ�Ҷ�ӽڵ������Һ��ӵ�Ҷ�ӽڵ���
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


//���k��Ľڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	assert(k >= 1);
	//rootΪNULLʱ��û�нڵ�
	if (root==NULL)
	{
		return 0;
	}

	//�������ߵ�����ʱ���ͱ�ʾroot��Ϊ�գ���ʱk���ڼ����ǵڼ���
	//k����1ʱ����ʾ��һ�㣬�����ڵ㣬����ֻ��һ���ڵ㣬����1
	if (k==1)
	{
		return 1;
	}

	//�������ߵ������˵��root��Ϊ�գ���k!=1
	//˵��root������ĵ�k��Ľڵ����������棬
	// ��������������ĵ�k��Ľڵ�����δ֪�� ��һ��Ľڵ�������ֻ��һ��
	//ת������root����������������ĵ�k-1��Ľڵ���
	return	BinaryTreeLevelKSize(root->left, k - 1)+BinaryTreeLevelKSize(root->right,k-1);
	//����
	//��A�ĵ�����Ľڵ�������ת��Ϊ��A���������ĵڶ���ڵ������������ĵڶ���Ľڵ���֮��
	//�ֿ���ת������  A��������  ���������ĵ�һ��Ľڵ��� �� �������ĵ�һ��Ľڵ��� ֮��
	//����
	//A��������  ��  �������ĵ�һ��Ľڵ��� �� �������ĵ�һ��Ľڵ��� ֮��
}

//���������
//��ǰ������ȵ������������������Ƚϣ���ļ�һ
int BinaryTreeDepth(BTNode* root)
{
	if (root==NULL)
	{
		return 0;
	}

	//����������������������ֹ����ʱ�ظ�����
	int leftdepth = BinaryTreeDepth(root->left);
	int rightdepth = BinaryTreeDepth(root->right);

	//��leftdepth ����rightdepth ʱ��Ҳ���Ƿ��ʵ����һ���ڵ�ʱ��
	//leftdepth ==0  rightdepth==0  ����ֵ�����������һ����1����

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
		//����ҵ��ˣ���ֱ�ӷ���
		return root;
	}

	//�����ߵ������˵����û�ҵ����Ǿ�ȥ���ڵ������ȥ��
	//�����ҵ��ˣ���ֱ�ӷ��أ�û���ҵ�����NULL
	//����������ֹ�ظ�����
	BTNode* left = BinaryTreeFind(root->left, x);
	if (left)
	{
		return left;
	}
	//������û�ҵ����Ǿ�ֱ��ȥ�������ң�
	//�����ҵ��ˣ���ֱ�ӷ��أ�û���ҵ�����NULL
	//����������ֹ�ظ�����
	BTNode* right = BinaryTreeFind(root->right, x);
	if (right)
	{
		return right;
	}
	//����������û�ҵ���˵���ýڵ㲻����
	return NULL;
}