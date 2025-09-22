/*
    �ļ���LinkQueue.cpp
    ˵�������ļ�ʵ�������еĻ�������������
 */

#include <cstddef>
#include "LinkQueue.h"

//��ʼ������
Status InitQueue(LinkQueue &Q)
{
	Q.front = Q.rear = new QNode;
	if (!Q.front) return ERROR;
	Q.front->next = NULL;
	Q.length = 0;
	return OK;
}

//���ٶ���
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

//���
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

//����
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

//�ж϶����Ƿ�Ϊ��
Status QueueEmpty(LinkQueue &Q){
	return (Q.length == 0);
}