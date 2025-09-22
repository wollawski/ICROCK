/*
    文件：ex3.cpp
    说明：此文件实现主函数，测试二叉树的操作功能。
 */

#include <iostream>
#include "BiTree.h"
using namespace std;

//打印结点的数据
void PrintNode(BiNode* N)
{
	cout << N->data << " ";
}

int main()
{
	BiTree T = NULL;
	
	cout << "请以先序方式输入树的结点数据('#'表示空结点)：";
	CreateBiTree_PreOrder(T);
	//ShowBiTree(T);

	cout << "\n先序遍历：";
	PreOrderTraversing(T);

	cout << "\n中序遍历：";
	InOrderTraversing(T);

	cout << "\n后序遍历：";
	PostOrderTraversing(T);

	cout << "\n层序遍历：";
	LevelOrderTraversing(T);

	cout << "\n树的深度：" << BiTreeDepth(T);
	cout << "\n结点总数：" << CountNode(T);
	cout << "\n叶结点数：" << CountLeaf(T)<<endl;
	
	return 0;
}
