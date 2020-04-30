#include<iostream>
using namespace std;
const int MaxSize = 100;
//˳������Ͷ���
typedef struct SqQueue
{
	char data[MaxSize];
	int front, rear;//front���ף�rear��β
};
//��ʼ������
void InitQueue(SqQueue*& q)
{
	q = (SqQueue*)malloc(sizeof(SqQueue));
	q->front = q->rear = -1;
}
//���ٶ���
void DestoryQueue(SqQueue*& q)
{
	free(q);
}
//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(SqQueue* q)
{
	return(q->front == q->rear);
}
//������
bool enQueue(SqQueue*& q, char e)
{
	if (q->rear == MaxSize - 1)
		return false;
	q->rear++;
	q->data[q->rear] = e;
	return true;
}
//������
bool deQueue(SqQueue*& q, char e)
{
	if (q->front = q->rear)
		return false;
	q->front++;
	e = q->data[q->front];
	return true;
}
//�������ܻ���֡��������״̬��
//ʹ�û��ζ��н��
//���ζ��е�ʵ�ַ�����
//��rear++��Ϊrear=(rear+1)%MaxSize
//��front++��Ϊfront=(front+1)%MaxSize
//Լ��rear==frontΪ�ӿ�����
//(rear+1)%MaxSize==frontΪ��������
/*��֪front��rear�������Ԫ�ظ���count��
count=(rear-front+MaxSize)%MaxSize */
/*��֪front��count����rear
rear=(front+count)%MaxSize */
/*��֪rear��count����front
front=(rear-count+MaxSize)%MaxSize */

//��ʹ��front��count���廷�ζ���
typedef struct QuType
{
	char data[MaxSize];
	int front, count;
};
//��ʼ��
void InitQueue(QuType*& qu)
{
	qu = (QuType*)malloc(sizeof(QuType));
	qu->front = 0;
	qu->count = 0;
}
//�����㷨
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
//�����㷨
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
//�ж϶ӿ�
bool QueueEmpty(QuType* qu)
{
	return(qu->count == 0);
}

//����
//���ݽڵ����Ͷ���
typedef struct qnode
{
	char data;
	struct qnode* next;
}DataNode;
//ͷ�ڵ����Ͷ���
typedef struct LinkQuNode
{
	DataNode* front;
	DataNode* rear;
};
//��ʼ������
void InitQueue(LinkQuNode*& q)
{
	q = (LinkQuNode*)malloc(sizeof(LinkQuNode));
	q->front = q->rear = NULL;
}
//���ٶ���
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
//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(LinkQuNode* q)
{
	return(q->rear == NULL);
}
//����
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
//����
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
//ֻ��β����ѭ��������洢����
//��ʼ���������㷨
typedef struct LinkList
{
	char data;
	LinkList* next;
};
void initQueue(LinkList*& rear)
{
	rear = NULL;
}
//�жӿ������㷨
bool queueEmpty(LinkList* rear)
{
	return (rear == NULL);
}
//���������㷨
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
//���������㷨
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