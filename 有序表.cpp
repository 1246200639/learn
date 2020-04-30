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
//��˳���洢���������ֻ�в����㷨�в��죬���£�
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
//��������㷨
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
//�����������󹫹�Ԫ�ط��ڵ������С�
//��·����β�巨����
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