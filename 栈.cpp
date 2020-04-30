#include<iostream>
using namespace std;
const int MaxSize = 100;
//ջ��˳��洢�ṹ����������ʵ��
//����
typedef struct SqStack
{
	char data[MaxSize];
	int top;
};
//��ʼ��ջ
void InitStack(SqStack*& s)
{
	s = (SqStack*)malloc(sizeof(SqStack));
	s->top = -1;
}
//����ջ
void DestroyStack(SqStack*& s)
{
	free(s);
}
//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(SqStack* s)
{
	return (s->top == -1);
}
//��ջ
bool Push(SqStack*& s, char e)
{
	if (s->top == MaxSize - 1)
		return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}
//��ջ
bool Pop(SqStack*& s, char e)
{
	if (s->top == - 1)
		return false;
	e=s->data[s->top];
	s->top--;
	return true;
}
//ȡջ��Ԫ��
bool GetTop(SqStack*& s, char e)
{
	if (s->top == - 1)
		return false;
	e=s->data[s->top];
	return true;
}
//����㷨�ж�һ���ַ����Ƿ��ǶԳƴ�
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

//ջ����ʽ�洢�ṹ����������ʵ��
//����
typedef struct LinkStNode
{
	char data;
	struct LinkStNode* next;
};
//��ʼ��ջ
void InitStack(LinkStNode*& s)
{
	s = (LinkStNode*)malloc(sizeof(LinkStNode));
	s->next = NULL;
}
//����ջ
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
//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(LinkStNode* s)
{
	return (s->next == NULL);
}
//��ջ
void Push(LinkStNode*& s, char &e)
{
	LinkStNode* p;
	p = (LinkStNode*)malloc(sizeof(LinkStNode));
	p->data = e;
	p->next = s->next;
	s->next = p;
}
//��ջ
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
//ȡջ��Ԫ��
bool GetTop(LinkStNode*& s, char &e)
{
	if (s->next == NULL)
		return false;
	e = s->next->data;
	return true;
}
//��д�㷨�ж������Ƿ����
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