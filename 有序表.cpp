#include<iostream>
using namespace std;

typedef struct SList
{
	char data[100];
	int length;
}SqList;
typedef struct LNode
{
	char data;
	struct LNode* next;
}LinkNode;
//以顺序表存储有序表，代码只有插入算法有差异，如下：
void ListInsert(SqList*& L, char e)
{
	int i = 0, j;
	while (i < L->length && L->data[i] < e)
	{
		i++;
	}
	for (j = L->length; j < i; j--)
	{
		L->data[j] = L->data[j - 1];
	}
	L->data[i] = e;
	L->length++;
}
//链表插入算法
void ListInsert(LinkNode*& L, char e)
{
	LinkNode* pre = L, * p;
	while (pre->next != NULL && pre->next->data < e)
	{
		pre = pre->next;
	}
	p = (LinkNode*)malloc(sizeof(LinkNode));
	p->data = e;
	p->next = pre->next;
	pre->next = p;
} 
//两有序单链表求公共元素放在单链表中。
//二路并归尾插法建表
void InterSect(LinkNode* ha, LinkNode* hb, LinkNode*& hc)
{
	LinkNode* pa = ha->next, * pb = hb->next, * s, * r;
	hc = (LinkNode*)malloc(sizeof(LinkNode));
	r = hc;
	while (pa != NULL && pb != NULL)
	{
		if (pa->data < pb->data)pa = pa->next;
		if (pa->data > pb->data)pb = pb->next;
		if (pa->data == pb->data)
		{
			s = (LinkNode*)malloc(sizeof(LinkNode));
			s->data = pa->data;
			r->next = s; r = s;
			pa = pa->next; pb = pb->next;
		}
	}
	r->next = NULL;
}