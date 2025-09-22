/*
    �ļ���LinkQueue.h
    ˵�������ļ������ͷ���������нṹ��
 */

#pragma once

#include "BiTree.h"

typedef BiTree NodeType;	// �����е�Ԫ������ΪBiTree

typedef struct QNode {      // ���н�������֣�һ������һ��ָ��ָ�������һ���ڵ�
	NodeType data;
	struct QNode* next;
} QNode, *Link;

typedef struct {            // ������
	Link front;             // ����ָ��
	Link rear;              // ��βָ��
	int  length;            // ���г���    
}LinkQueue;

// �����л��������ĺ���ԭ��
Status InitQueue(LinkQueue &);
Status DestroyQueue(LinkQueue &);
Status EnQueue(LinkQueue &, NodeType);
Status DeQueue(LinkQueue &, NodeType &);
Status QueueEmpty(LinkQueue &);