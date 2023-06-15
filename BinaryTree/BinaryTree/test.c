#define _CRT_SECURE_NO_WARNINGS
#include"BinaryTree.h"
#include"Queue.h"


void test()
{
	BTNode* root = CreatBinaryTree();
	PreOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	postOrder(root);
	int n = 0;
	printf("\n");
	BinartSize(root, &n);
	printf("Treesize: %d \n", n);

	printf("Treesize: %d \n", BinaryTreeSize(root));

	printf("%d \n", BinaryTreeLeafsize(root));

	printf("%d \n", BinaryTreeLevelKSize(root, 3));

	printf("%d \n", BinaryTreeDepth(root));

	BinaryTreeLevelOrder(root);

	printf("%d ", BinaryTreeComplete(root));

	BinaryTreedestory(root);
}

int main()
{
	test();
	return 0;
}