#include<iostream>
using namespace std;

//串的顺序存储
//非紧缩串定义如下
#define MaxSize 100
typedef struct SqString
{
	char data[MaxSize];
	int length;
};
//顺序存储的串的基本运算与顺序表基本相同。
//设计字符串比较运算
int Strcmp(SqString s, SqString t)
{
	int i, comlen;
	if (s.length < t.length)
		comlen = s.length;
	else
		comlen = t.length;
	for (i = 0; i < comlen; i++)
	{
		if (s.data[i] > t.data[i])
			return 1;
		else if (s.data[i] < t.data[i])
			return -1;
	}
	if (s.length == t.length)
		return 0;
	else if (s.length > t.length)
		return 1;
	else
		return -1;
}

//串的链式存储及基本操作实现
//链串的结点类型定义如下
typedef struct snode
{
	char data;
	struct snode* next;
}LinkStrNode;
//链串实现串的基本运算与单链表基本运算类似
//设计一个算法把最先出现的子串“ab”改为“xyz”
void Pepl(LinkStrNode*& s)
{
	LinkStrNode* p = s->next, * q;
	int find = 0;
	while (p->next != NULL && find == 0)
	{
		if (p->data == 'a' && p->next->data == 'b')
		{
			p->data = 'x';
			p->next->data = 'z';
			q = (LinkStrNode*)malloc(sizeof(LinkStrNode));
			q->data = 'y';
			q->next = p->next;
			p->next = q;
			find = 1;
		}
		else p = p->next;
	}
}
//串的复制
void strcopy(LinkStrNode*& s, LinkStrNode* t)
{
	LinkStrNode* p = t->next, * q, * r;
	r = s;
	while (p != NULL)
	{
		q = (LinkStrNode*)malloc(sizeof(LinkStrNode));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}
	r->next = NULL;
}
//串的模式匹配
//BF算法
int index(SqString s, SqString t)
{
	int i = 0, j = 0;
	while (i < s.length && j < t.length)
	{
		if (s.data[i] == t.data[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j >= t.length)
		return (i - t.length);
	else
		return (-1);
}
//KMP算法
//先求next值
void GetNext(SqString t, int next[])
{
	int j, k;
	j = 0; k = -1;
	next[0] = -1;
	while (j < t.length - 1)
	{
		if (k == -1 || t.data[j] == t.data[k])
		{
			j++; k++;
			next[j] = k;
		}
		else
			k = next[k];
	}
}
//kmp算法
int KMPIndex(SqString s, SqString t)
{
	int next[MaxSize], i = 0, j = 0;
	GetNext(t, next);
	while (i < s.length && j < t.length)
	{
		if (j == -1 || s.data[i] == t.data[j])
		{
			i++;
			j++;
		}
		else
			j = next[j];
	}
	if (i > t.length)
		return(i - t.length);
	else
		return (-1);
}