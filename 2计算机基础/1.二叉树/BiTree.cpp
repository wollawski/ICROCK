/*
	�ļ���BiTree.cpp
	˵�������ļ�ʵ�ֶ������Ļ�������������
 */

#include <iostream>
#include <cstring>
#include <sstream>
#include <iomanip>
#include "BiTree.h"
#include "LinkQueue.h"
using namespace std;

// ������ʽ�������������ӱ�׼�����豸����ÿ������ֵ
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

// �ݹ��������
//void PreOrderTraversing(BiTree& T, void (*visit)(BiTree))
void PreOrderTraversing(BiTree &T)
{
	
	if (T) {
		cout << T->data;
		PreOrderTraversing(T->lchild);
		PreOrderTraversing(T->rchild);
	}
}

// �ݹ��������
//void InOrderTraversing(BiTree& T, void(*visit)(BiTree));
void InOrderTraversing(BiTree &T)
{
	if (T) {
		InOrderTraversing(T->lchild);
		cout << T->data;
		InOrderTraversing(T->rchild);
	}
}

// �ݹ�������
//void PostOrderTraversing(BiTree &T, void (*visit)(BiTree))
void PostOrderTraversing(BiTree &T)
{
	if (T) {
		PostOrderTraversing(T->lchild);
		PostOrderTraversing(T->rchild);
		cout << T->data;
	}
}

// �ö���ʵ�ֲ������
void LevelOrderTraversing(BiTree T)
{
	LinkQueue q; InitQueue(q); 
	if (T == NULL) return; // �����Ϊ�գ�ֱ�ӷ���
	EnQueue(q,T); // �����ڵ����

	while (!QueueEmpty(q)) {
		BiTree current;
		DeQueue(q, current);

		cout << current->data;

		// ����ǰ�ڵ���������
		if (current->lchild != NULL) {
			EnQueue(q, current->lchild);
		}

		// ����ǰ�ڵ���Һ������
		if (current->rchild != NULL) {
			EnQueue(q, current->rchild);
		}
	}
}

// ���ض�����T�еĽ��������ʹ�����������
int CountNode(BiTree &T)
{
	int count = 0;
	if (T == NULL)return 0;
	else return CountNode(T->lchild) + CountNode(T->rchild) + 1;
	//return count;
}

// ���ض�����T��Ҷ������Ŀ��ʹ�����������
int CountLeaf(BiTree &T)
{
	int count = 0;
	if (T == 0) return 0;
	else if (!T->lchild && !T->rchild) return 1;
	else return CountLeaf(T->lchild) + CountLeaf(T->rchild);
	
	//return count;
}

// ���ض�����T�����
int BiTreeDepth(BiTree &T)
{
	if (T == NULL) return 0;
	int m, n;
	m = BiTreeDepth(T->lchild);
	n =	BiTreeDepth(T->rchild);
	if (m > n) return m + 1;
	return n + 1;
	
}

// ����charArray�������ݵĵݹ麯����
// �����T������д��charArray[row][co]��������treeDepth��ֵ�����ӽڵ������λ�á�
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

// ���ϵ��´�ӡ�ַ�������
// ʹ��һ����ά�ַ�����charArray[][]��ʾ��ʾ�Ľ����
void ShowBiTree(BiTree &T)
{
	if (T)
	{
		int treeDepth = BiTreeDepth(T);

		int num_max_leaves = 1 << (treeDepth - 1);							// ������Ҷ������������Ŀ
		int charArrayHeight = treeDepth * 2 - 1;							// ��ά�ַ����������
		int charArrayWidth = num_max_leaves + (num_max_leaves - 1) * 3 + 1; // ��ά�ַ����������

		string **charArray = new string *[charArrayHeight];
		for (int i = 0; i < charArrayHeight; i++) // ��ʼ����ά�ַ�����
		{
			charArray[i] = new string[charArrayWidth + 1];
			memset(charArray[i], ' ', charArrayWidth);
			charArray[i][charArrayWidth] = '\0';
		}

		WriteArray(T, 0, charArrayWidth / 2, charArray, treeDepth); // �Ӹ���㿪ʼ���������ַ����������

		cout << endl;
		for (int i = 0; i < charArrayHeight; i++) // ��ʾ
			cout << charArray[i] << endl;
		cout << endl;
	}
}