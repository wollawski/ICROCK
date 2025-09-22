/*
    �ļ���BiTree.h
    ˵�������ļ������Զ��������ʾ�Ķ��������͡�
 */

#pragma once

#include "./Data_Structure.h"
#include <iostream>
#include <string>
using namespace std;

//��������
typedef struct BiNode {//һ���ַ���Ԫ�أ�����ָ��ָ�������ӽڵ�
	string data;
	struct BiNode* lchild, * rchild;
}BiNode, *BiTree;

// ���������������ĺ���ԭ��
void CreateBiTree_PreOrder(BiTree& T);
void PreOrderTraversing(BiTree& T);
void InOrderTraversing(BiTree& T);
void PostOrderTraversing(BiTree& T);
void LevelOrderTraversing(BiTree T);

/*void PreOrderTraversing(BiTree& T, void (*visit)(BiTree));
void InOrderTraversing(BiTree& T, void(*visit)(BiTree));
void PostOrderTraversing(BiTree& T, void (*visit)(BiTree));
void LevelOrderTraversing(BiTree T, void (*visit)(BiTree));*/

int CountNode(BiTree& T);
int CountLeaf(BiTree& T);
int BiTreeDepth(BiTree&);
void ShowBiTree(BiTree&);
