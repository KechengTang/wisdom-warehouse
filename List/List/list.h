typedef int QDataType;

typedef struct QListNode
{
	struct QListNode* _next;
	QDataType _data;
}QNode;

typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}Queue;

void QueueInit(Queue* q);

void QueuePush(Queue* q, QDataType data);

void QueuePop(Queue* q);

QDataType QueueFront(Queue* q);

QDataType QueueBack(Queue* q);

int QueueSize(Queue* q);

int QueueEmpty(Queue* q);

void QueueDestroy(Queue* q);