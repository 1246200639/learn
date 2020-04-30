#include<iostream>
using namespace std;

//单链表节点类型的定义
typedef struct LNode
{
	char data;
	struct LNode* next;
}Linknode;

//头插法建立链表
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

//尾插法建立链表
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

//初始化线性表
void InidList(Linknode*& L)
{
	L=(Linknode*)malloc(sizeof(Linknode));
	L->next = NULL;
}

//销毁线性表
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

//判断是否为空表
bool ListEmpty(Linknode*& L)
{
	return (L->next == NULL);
}

//求线性表的长度
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

//输出线性表
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

//找位置i的数据元素
bool GetElem(int i, Linknode*& L, char e)
{
	int j=0;
	Linknode* p = L;
	while (j < i && p->next != L)
	{
		j++;
		p = p->next;
	}//指到第i位
	if (p->next == NULL)
		return false;
	else
	{
		e = p->data;
		return true;
	}
}

//确定元素位置
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

//在第i个位置插入元素
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

//删除第i个元素
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

//删除链表中值最大的结点
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

//重排链表元素递增序列
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
}//时间复杂度为O(n*n)

//将链表所有节点逆置
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
//链表拆分
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