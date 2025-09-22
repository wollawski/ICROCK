/*
    文件：LinkQueue.cpp
    说明：此文件实现链队列的基本操作函数。
 */

#include <cstddef>
#include "LinkQueue.h"

//初始化队列
Status InitQueue(LinkQueue &Q)
{
	Q.front = Q.rear = new QNode;
	if (!Q.front) return ERROR;
	Q.front->next = NULL;
	Q.length = 0;
	return OK;
}

//销毁队列
Status DestroyQueue(LinkQueue &Q)
{
	Link p;
	while (Q.front) {
		p = Q.front->next;
		delete Q.front;
		Q.front = p;
	}
	Q.length = 0;
	return OK;
}

//入队
Status EnQueue(LinkQueue &Q, NodeType e)
{
	Link p = new QNode;
	if (!p) return ERROR;

	p->data = e;
	p->next = NULL;

	Q.rear->next = p;
	Q.rear = p;

	Q.length++;

	return OK;
}

//出队
Status DeQueue(LinkQueue &Q, NodeType &e)
{
	if (Q.length <= 0) return ERROR;

	Link p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;

	if(Q.rear == p) Q.rear = Q.front;
	delete p;

	Q.length--;

	return OK;
}

//判断队列是否为空
Status QueueEmpty(LinkQueue &Q){
	return (Q.length == 0);
}