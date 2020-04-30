#include<iostream>
using namespace std;
//˫�����㶨��
typedef struct DNode
{
	char data;
	struct DNode* prior;
	struct DNode* next;
}DLinkNode;
//����˫����
//ͷ�巨
void CreateListF(DLinkNode*& L, char a[], int n)
{
	DLinkNode* s;
	int i;
	L = (DLinkNode*)malloc(sizeof(DLinkNode));
	L->prior = L->next = NULL;
	for (i = 0; i < n; i++)
	{
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = a[i];
		s->next = L->next;
		if (L->next != NULL)
		{
			L->next->prior = s;
		}
		L->next = s;
		s->prior = L;
	}
}
//β�巨
void CreateListR(DLinkNode*& L, char a[], int n)
{
	DLinkNode* s, * r;
	int i;
	L = (DLinkNode*)malloc(sizeof(DLinkNode));
	r = L;
	for (i = 0; i < n; i++)
	{
		s= (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = a[i];
		r->next = s;
		s->prior = r;
		r = s;
	}
	r->next = NULL;
}
//˫����Ĳ����㷨
bool ListInsert(DLinkNode*& L, int i, char e)
{
	int j = 0;
	DLinkNode* p = L, * s;
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else
	{
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = e;
		s->next = p->next;
		if (p->next != NULL)
			p->next->prior = s;
		s->prior = p;
		p->next = s;
		return true;
	}
}//˫�����ɾ���㷨
bool ListDelete(DLinkNode*& L, int i, char& e)
{
	int j = 0;
	DLinkNode* p = L, * q;
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else
	{
		q = p->next;
		if (q == NULL)
			return false;
		e = q->data;
		p->next = q->next;
		if (p->next != NULL)
			p->next->prior = p;
		free(q);
		return true;
	}
}
//˫����Ԫ������
void Reverse(DLinkNode*& L)
{
	DLinkNode* p = L->next, * q;
	L->next = NULL;
	while (p != NULL)
	{
		q = p->next;
		p->next = L->next;
		if (L->next != NULL)
			L->next->prior = p;
		L->next = p;
		p->prior = L;
		p = q;
	}
}

//ѭ������
//ѭ��������