#include<iostream>
using namespace std;
const int MaxSize = 100;
//栈的顺序存储结构及基本运算实现
//定义
typedef struct SqStack
{
	char data[MaxSize];
	int top;
};
//初始化栈
void InitStack(SqStack*& s)
{
	s = (SqStack*)malloc(sizeof(SqStack));
	s->top = -1;
}
//销毁栈
void DestroyStack(SqStack*& s)
{
	free(s);
}
//判断栈是否为空
bool StackEmpty(SqStack* s)
{
	return (s->top == -1);
}
//进栈
bool Push(SqStack*& s, char e)
{
	if (s->top == MaxSize - 1)
		return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}
//出栈
bool Pop(SqStack*& s, char e)
{
	if (s->top == - 1)
		return false;
	e=s->data[s->top];
	s->top--;
	return true;
}
//取栈顶元素
bool GetTop(SqStack*& s, char e)
{
	if (s->top == - 1)
		return false;
	e=s->data[s->top];
	return true;
}
//设计算法判断一个字符串是否是对称串
bool symmetry(char str[])
{
	int i;
	char e;
	SqStack* st;
	InitStack(st);

	for (i = 0; str[i] != '\0'; i++)
		Push(st, str[i]);

	for (i = 0; str[i] != '\0'; i++)
	{
		Pop(st, e);
		if (str[i] != e)
		{
			DestroyStack(st);
			return false;
		}
	}
	DestroyStack(st);
	return true;
}

//栈的链式存储结构及基本运算实现
//定义
typedef struct LinkStNode
{
	char data;
	struct LinkStNode* next;
};
//初始化栈
void InitStack(LinkStNode*& s)
{
	s = (LinkStNode*)malloc(sizeof(LinkStNode));
	s->next = NULL;
}
//销毁栈
void DestoryStack(LinkStNode*& s)
{
	LinkStNode* p = s, * q = s->next;
	while (q != NULL)
	{
		free(p);
		p = q;
		q = p->next;
	}
	free(p);
}
//判断栈是否为空
bool StackEmpty(LinkStNode* s)
{
	return (s->next == NULL);
}
//进栈
void Push(LinkStNode*& s, char &e)
{
	LinkStNode* p;
	p = (LinkStNode*)malloc(sizeof(LinkStNode));
	p->data = e;
	p->next = s->next;
	s->next = p;
}
//出栈
bool Pop(LinkStNode*& s, char &e)
{
	LinkStNode* p;
	if (s->next == NULL)
		return false;
	p = s->next;
	e = p->data;
	s->next = p->next;
	free(p);
}
//取栈顶元素
bool GetTop(LinkStNode*& s, char &e)
{
	if (s->next == NULL)
		return false;
	e = s->next->data;
	return true;
}
//编写算法判断括号是否配对
bool Match(char exp[], int n)
{
	int i = 0;
	char e;
	bool match = true;
	LinkStNode* st;
	InitStack(st);
	while (i < n && match)
	{
		if (exp[i] == '(')
			Push(st, exp[i]);
		else if (exp[i] == ')')
		{
			if (GetTop(st, e) == true)
			{
				if (e != '(')
					match = false;
				else
					Pop(st, e);
			}
			else
				match = false;
		}
		i++;
	}
	if (!StackEmpty(st))
		match = false;
	DestoryStack(st);
	return match;
}