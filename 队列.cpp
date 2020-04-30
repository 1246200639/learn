#include<iostream>
using namespace std;
const int MaxSize = 100;
//顺序队类型定义
typedef struct SqQueue
{
	char data[MaxSize];
	int front, rear;//front队首，rear队尾
};
//初始化队列
void InitQueue(SqQueue*& q)
{
	q = (SqQueue*)malloc(sizeof(SqQueue));
	q->front = q->rear = -1;
}
//销毁队列
void DestoryQueue(SqQueue*& q)
{
	free(q);
}
//判断队列是否为空
bool QueueEmpty(SqQueue* q)
{
	return(q->front == q->rear);
}
//进队列
bool enQueue(SqQueue*& q, char e)
{
	if (q->rear == MaxSize - 1)
		return false;
	q->rear++;
	q->data[q->rear] = e;
	return true;
}
//出队列
bool deQueue(SqQueue*& q, char e)
{
	if (q->front = q->rear)
		return false;
	q->front++;
	e = q->data[q->front];
	return true;
}
//上述可能会出现“假溢出”状态，
//使用环形队列解决
//环形队列的实现方法：
//将rear++改为rear=(rear+1)%MaxSize
//将front++改为front=(front+1)%MaxSize
//约定rear==front为队空条件
//(rear+1)%MaxSize==front为队满条件
/*已知front，rear，求队中元素个数count：
count=(rear-front+MaxSize)%MaxSize */
/*已知front，count，求rear
rear=(front+count)%MaxSize */
/*已知rear，count，求front
front=(rear-count+MaxSize)%MaxSize */

//仅使用front和count定义环形队列
typedef struct QuType
{
	char data[MaxSize];
	int front, count;
};
//初始化
void InitQueue(QuType*& qu)
{
	qu = (QuType*)malloc(sizeof(QuType));
	qu->front = 0;
	qu->count = 0;
}
//进队算法
bool EnQueue(QuType*& qu, char x)
{
	int rear;
	if (qu->count == MaxSize)
		return false;
	else
	{
		rear = (qu->front + qu->count) % MaxSize;
		rear = (rear + 1) % MaxSize;
		qu->data[rear] = x;
		qu->count++;
		return true;
	}
}
//出队算法
bool DeQueue(QuType*& qu, char& x)
{
	if (qu->count == 0)
		return false;
	else
	{
		qu->front = (qu->front + 1) % MaxSize;
		x = qu->data[qu->front];
		qu->count--;
		return true;
	}
}
//判断队空
bool QueueEmpty(QuType* qu)
{
	return(qu->count == 0);
}

//链队
//数据节点类型定义
typedef struct qnode
{
	char data;
	struct qnode* next;
}DataNode;
//头节点类型定义
typedef struct LinkQuNode
{
	DataNode* front;
	DataNode* rear;
};
//初始化队列
void InitQueue(LinkQuNode*& q)
{
	q = (LinkQuNode*)malloc(sizeof(LinkQuNode));
	q->front = q->rear = NULL;
}
//销毁队列
void DestroyQueue(LinkQuNode*& q)
{
	DataNode* p = q->front, * r;
	if (p != NULL)
	{
		r = p->next;
		while (r != NULL)
		{
			free(p);
			p = r;
			r = p->next;
		}
	}
	free(p);
	free(q);
}
//判断队列是否为空
bool QueueEmpty(LinkQuNode* q)
{
	return(q->rear == NULL);
}
//进队
void enQueue(LinkQuNode*& q, char e)
{
	DataNode* p;
	p = (DataNode*)malloc(sizeof(DataNode));
	p->data = e;
	p->next = NULL;
	if (q->rear == NULL)
		q->front = q->rear = p;
	else
	{
		q->rear->next = p;
		q->rear = p;
	}
}
//出队
bool deQueue(LinkQuNode*& q, char e)
{
	DataNode* t;
	if (q->rear == NULL)
		return false;
	t = q->front;
	if (q->front == q->rear)
		q->front = q->rear = NULL;
	else
		q->front = q->front->next;
	e = t->data;
	free(t);
	return true;
}
//只有尾结点的循环单链表存储队列
//初始化队运算算法
typedef struct LinkList
{
	char data;
	LinkList* next;
};
void initQueue(LinkList*& rear)
{
	rear = NULL;
}
//判队空运算算法
bool queueEmpty(LinkList* rear)
{
	return (rear == NULL);
}
//进队运算算法
void enQueue(LinkList*& rear, char x)
{
	LinkList* p;
	p = (LinkList*)malloc(sizeof(LinkList));
	p->data = x;
	if (rear == NULL)
	{
		p->next = p;
		rear = p;
	}
	else
	{
		p->next = rear->next;
		rear->next = p;
		rear = p;
	}
}
//出队运算算法
bool deQueue(LinkList*& rear, char& x)
{
	LinkList* q;
	if (rear == NULL)
		return false;
	else
		if (rear->next == rear)
		{
			x = rear->data;
			free(rear);
			rear = NULL;
		}
		else
		{
			q = rear->next;
			x = q->data;
			rear->next = q->next;
			free(q);
		}
	return true;
}