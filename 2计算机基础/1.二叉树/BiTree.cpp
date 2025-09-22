/*
	文件：BiTree.cpp
	说明：此文件实现二叉树的基本操作函数。
 */

#include <iostream>
#include <cstring>
#include <sstream>
#include <iomanip>
#include "BiTree.h"
#include "LinkQueue.h"
using namespace std;

// 以先序方式建立二叉树，从标准输入设备输入每个结点的值
void CreateBiTree_PreOrder(BiTree &T)
{
	string ch;
	cin >> ch;
	if (ch.compare("#") == 0)T = NULL;
	else {
		T = new BiNode;
		T->data = ch;
		T->lchild = NULL;
		T->rchild = NULL;
		CreateBiTree_PreOrder(T->lchild);
		CreateBiTree_PreOrder(T->rchild);
	}
}

// 递归先序遍历
//void PreOrderTraversing(BiTree& T, void (*visit)(BiTree))
void PreOrderTraversing(BiTree &T)
{
	
	if (T) {
		cout << T->data;
		PreOrderTraversing(T->lchild);
		PreOrderTraversing(T->rchild);
	}
}

// 递归中序遍历
//void InOrderTraversing(BiTree& T, void(*visit)(BiTree));
void InOrderTraversing(BiTree &T)
{
	if (T) {
		InOrderTraversing(T->lchild);
		cout << T->data;
		InOrderTraversing(T->rchild);
	}
}

// 递归后序遍历
//void PostOrderTraversing(BiTree &T, void (*visit)(BiTree))
void PostOrderTraversing(BiTree &T)
{
	if (T) {
		PostOrderTraversing(T->lchild);
		PostOrderTraversing(T->rchild);
		cout << T->data;
	}
}

// 用队列实现层序遍历
void LevelOrderTraversing(BiTree T)
{
	LinkQueue q; InitQueue(q); 
	if (T == NULL) return; // 如果树为空，直接返回
	EnQueue(q,T); // 将根节点入队

	while (!QueueEmpty(q)) {
		BiTree current;
		DeQueue(q, current);

		cout << current->data;

		// 将当前节点的左孩子入队
		if (current->lchild != NULL) {
			EnQueue(q, current->lchild);
		}

		// 将当前节点的右孩子入队
		if (current->rchild != NULL) {
			EnQueue(q, current->rchild);
		}
	}
}

// 返回二叉树T中的结点总数，使用先序遍历。
int CountNode(BiTree &T)
{
	int count = 0;
	if (T == NULL)return 0;
	else return CountNode(T->lchild) + CountNode(T->rchild) + 1;
	//return count;
}

// 返回二叉树T中叶结点的数目，使用先序遍历。
int CountLeaf(BiTree &T)
{
	int count = 0;
	if (T == 0) return 0;
	else if (!T->lchild && !T->rchild) return 1;
	else return CountLeaf(T->lchild) + CountLeaf(T->rchild);
	
	//return count;
}

// 返回二叉树T的深度
int BiTreeDepth(BiTree &T)
{
	if (T == NULL) return 0;
	int m, n;
	m = BiTreeDepth(T->lchild);
	n =	BiTreeDepth(T->rchild);
	if (m > n) return m + 1;
	return n + 1;
	
}

// 计算charArray数组内容的递归函数。
// 将结点T的数据写入charArray[row][co]，并根据treeDepth的值计算子节点的行列位置。
void WriteArray(BiTree &T, int row, int col, string **charArray, int treeDepth)
{
	if (T)
	{
		charArray[row][col] = T->data;

		int level = (row + 1) / 2;
		if (level == treeDepth)
			return;
		int gap = 1 << (treeDepth - level - 1);

		// cout << "level = " << level << ", gap = " << gap << endl;

		if (T->lchild)
		{
			charArray[row + 1][col - gap / 2] = '/';
			WriteArray(T->lchild, row + 2, col - gap, charArray, treeDepth);
		}
		if (T->rchild)
		{
			charArray[row + 1][col + gap / 2] = '\\';
			WriteArray(T->rchild, row + 2, col + gap, charArray, treeDepth);
		}
	}
}

// 从上到下打印字符二叉树
// 使用一个二维字符数组charArray[][]表示显示的结果。
void ShowBiTree(BiTree &T)
{
	if (T)
	{
		int treeDepth = BiTreeDepth(T);

		int num_max_leaves = 1 << (treeDepth - 1);							// 最深层的叶结点的最大可能数目
		int charArrayHeight = treeDepth * 2 - 1;							// 二维字符数组的行数
		int charArrayWidth = num_max_leaves + (num_max_leaves - 1) * 3 + 1; // 二维字符数组的列数

		string **charArray = new string *[charArrayHeight];
		for (int i = 0; i < charArrayHeight; i++) // 初始化二维字符数组
		{
			charArray[i] = new string[charArrayWidth + 1];
			memset(charArray[i], ' ', charArrayWidth);
			charArray[i][charArrayWidth] = '\0';
		}

		WriteArray(T, 0, charArrayWidth / 2, charArray, treeDepth); // 从根结点开始，逐层计算字符数组的内容

		cout << endl;
		for (int i = 0; i < charArrayHeight; i++) // 显示
			cout << charArray[i] << endl;
		cout << endl;
	}
}