#include<iostream>
using namespace std;

//������ڵ����͵Ķ���
typedef struct LNode
{
	char data;
	struct LNode* next;
}Linknode;

//ͷ�巨��������
void CreateLinkF(Linknode*& L, char arr[], int n)
{
	Linknode* s;
	int i;
	L = (Linknode*)malloc(sizeof(Linknode));
	L->next = NULL;
	for (i = 0; i < n; i++)
	{
		s = (Linknode*)malloc(sizeof(Linknode));
		s->data = arr[i];
		s->next = L->next;
		L->next = s;
	}
}

//β�巨��������
void CreateLinkR(Linknode*& L, char arr[], int n)
{
	int i;
	Linknode* s, * r;
	L = (Linknode*)malloc(sizeof(Linknode));
	L->next = NULL;
	r = L;
	for (i = 0; i < n; i++)
	{
		s = (Linknode*)malloc(sizeof(Linknode));
		s->data = arr[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

//��ʼ�����Ա�
void InidList(Linknode*& L)
{
	L=(Linknode*)malloc(sizeof(Linknode));
	L->next = NULL;
}

//�������Ա�
void DestoryList(Linknode*& L)
{
	Linknode* pre = L, * p = pre->next;
	while (p->next != NULL)
	{
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);
}

//�ж��Ƿ�Ϊ�ձ�
bool ListEmpty(Linknode*& L)
{
	return (L->next == NULL);
}

//�����Ա�ĳ���
int ListLength(Linknode*& L)
{
	int n=0;
	Linknode* r=L;
	while (r->next != NULL)
	{
		n++;
		r = r->next;
	}
	return n;
}

//������Ա�
void DispList(Linknode*& L)
{
	Linknode* p = L->next;
	while (p->next != NULL)
	{
		cout << p->data;
		p = p->next;
	}
	cout << endl;
}

//��λ��i������Ԫ��
bool GetElem(int i, Linknode*& L, char e)
{
	int j=0;
	Linknode* p = L;
	while (j < i && p->next != L)
	{
		j++;
		p = p->next;
	}//ָ����iλ
	if (p->next == NULL)
		return false;
	else
	{
		e = p->data;
		return true;
	}
}

//ȷ��Ԫ��λ��
int LocateElem(Linknode*& L, char e)
{
	Linknode* p = L->next;
	int i = 1;
	while (p->data != e && p != NULL)
	{
		p = p->next;
		i++;
	}
	if (p == NULL)
		return 0;
	else 
		return (i);
}

//�ڵ�i��λ�ò���Ԫ��
bool ListInsert(Linknode*& L, char e, int i)
{
	Linknode* p = L;
	Linknode* s=NULL;
	int j = 0;
	while (j < i-1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else
	{
		s->data = e;
		s->next = p->next;
		p->next = s;
		return true;
	}
}

//ɾ����i��Ԫ��
bool ListDelete(Linknode*& L, int i, char e)
{
	Linknode* p = L, * q;
	int j = 0;
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
		else
		{
			e = q->data;
			p->next = q->next;
			free(q);
			return true;
		}
	}
}

//ɾ��������ֵ���Ľ��
void delemaxnode(Linknode*& L)
{
	Linknode* p = L->next, * pre = L;
	Linknode* max = p, * maxpre = pre;
	while (p != NULL)
	{
		if (max->data < p->data)
		{
			max = p;
			maxpre = pre;
		}
		pre = p;
		p = p->next;
	}
	maxpre->next = max->next;
	free(max);
}

//��������Ԫ�ص�������
void sort(Linknode*& L)
{
	Linknode* p, * pre, * q;
	p = L->next->next;
	L->next->next = NULL;

	while (p != NULL)
	{
		q = p->next;

		pre = L;
		while (pre->next != NULL && pre->next->data < p->data)
			pre = pre->next;

		p->next = pre->next;
		pre->next = p;
		p = q;
	}
}//ʱ�临�Ӷ�ΪO(n*n)

//���������нڵ�����
void Reverse(Linknode*& L)
{
	Linknode* p = L->next, * q;
	L->next = NULL;
	while (p != NULL)
	{
		q = p->next;
		p->next = L->next;
		L->next = p;
		p = q;
	}
}
//������
void split(Linknode*& L, Linknode*& L1, Linknode*& L2)
{
	Linknode* p = L->next, * q, * r1;
	L1 = L;
	r1 = L1;
	L2 = (Linknode*)malloc(sizeof(Linknode));
	L2->next = NULL;
	while (p != NULL)
	{
		r1->next = p;
		r1 = p;
		p = p->next;
		q = p->next;
		p->next = L2->next;
		L2->next = p;
		p = q;
	}
	r1->next = NULL;
}