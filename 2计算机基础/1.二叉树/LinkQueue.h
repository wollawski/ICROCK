/*
    文件：LinkQueue.h
    说明：此文件定义带头结点的链队列结构。
 */

#pragma once

#include "BiTree.h"

typedef BiTree NodeType;	// 队列中的元素类型为BiTree

typedef struct QNode {      // 队列结点两部分，一个数据一个指针指向队列下一个节点
	NodeType data;
	struct QNode* next;
} QNode, *Link;

typedef struct {            // 链队列
	Link front;             // 队首指针
	Link rear;              // 队尾指针
	int  length;            // 队列长度    
}LinkQueue;

// 链队列基本操作的函数原型
Status InitQueue(LinkQueue &);
Status DestroyQueue(LinkQueue &);
Status EnQueue(LinkQueue &, NodeType);
Status DeQueue(LinkQueue &, NodeType &);
Status QueueEmpty(LinkQueue &);