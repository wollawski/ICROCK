/*
    �ļ���ex3.cpp
    ˵�������ļ�ʵ�������������Զ������Ĳ������ܡ�
 */

#include <iostream>
#include "BiTree.h"
using namespace std;

//��ӡ��������
void PrintNode(BiNode* N)
{
	cout << N->data << " ";
}

int main()
{
	BiTree T = NULL;
	
	cout << "��������ʽ�������Ľ������('#'��ʾ�ս��)��";
	CreateBiTree_PreOrder(T);
	//ShowBiTree(T);

	cout << "\n���������";
	PreOrderTraversing(T);

	cout << "\n���������";
	InOrderTraversing(T);

	cout << "\n���������";
	PostOrderTraversing(T);

	cout << "\n���������";
	LevelOrderTraversing(T);

	cout << "\n������ȣ�" << BiTreeDepth(T);
	cout << "\n���������" << CountNode(T);
	cout << "\nҶ�������" << CountLeaf(T)<<endl;
	
	return 0;
}
