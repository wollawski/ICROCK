/*
    文件：BiTree.h
    说明：此文件定义以二叉链表表示的二叉树类型。
 */

#pragma once

#include "./Data_Structure.h"
#include <iostream>
#include <string>
using namespace std;

//二叉链表
typedef struct BiNode {//一个字符型元素，两个指针指向两个子节点
	string data;
	struct BiNode* lchild, * rchild;
}BiNode, *BiTree;

// 二叉树基本操作的函数原型
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
