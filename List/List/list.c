#include "list.h"
#include <stdio.h>

void QueueInit(Queue* q)
{
	assert(q);
	q->_front = q->_rear = NULL;
}

void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode* newnode = (QNode*)malloc(sizeod(QNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->_data = data;
	newnode->_next = NULL;
	if (q->_rear == NULL)
	{
		q->_front = q->_rear = newnode;
	}
	else 
	{
		q->_rear->_next = newnode;
		q->_rear = newnode;
	}
}

void QueuePop(Queue* q)
{
	assert(q);
	asseert(!QueueEmpty(q));
	if (q->_front->_next == NULL)
	{
		free(q->_front);
		q->_front = q->_rear = NULL;
	}
	else
	{
		QNode* next = q->_front->_next;
		free(q->_front);
		q->_front = next;
	}
}

QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->_front->_data;
}

QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->_rear->_data;
}

int QueueSize(Queue* q)
{
	assert(q);
	QNode* cur = q->_front;
	int size = 0;
	while (cur)
	{
		++size;
		cur = cur->_next;
	}
	return size;
}

int QueueEmpty(Queue* q)
{
	assert(q);
	return q->_front == NULL;
}

void QueueDestroy(Queue* q)
{
	assert(q);
	QNode* cur = q->_front;
	while (cur)
	{
		QNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_front = q->_rear = NULL;
}