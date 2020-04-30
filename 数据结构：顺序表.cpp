#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100

typedef struct//����˳���ṹ��
{
	char data[MaxSize];
	int lengh;
}SqList;
/********�߼�˳�������˳�����1**********/

/*����˳���*/
void CreateList(SqList*& L, char a[], int n)//���彨��˳���
{
	int i;
	L = (SqList*)malloc(sizeof(SqList));
	for (i = 0; i < n; i++)
		L->data[i] = a[i];
	L->lengh = n;
}
/*��ʼ�����Ա�*/
void InitList(SqList*& L)
{
	L = (SqList*)malloc(sizeof(SqList));
	L->lengh = 0;
}
/*��ĳ������Ԫ��ֵ*/
bool GetElem(SqList*& L, int i, char& e)
{
	if (i<1 || i>L->lengh)return false;
	e = L->data[i];
	return true;
}
/*��Ԫ��ֵ����LocateElem(L,e)*/
int LocateElem(SqList*& L, char e)
{
	int i = 0;
	while (i < L->lengh && L->data[i] != e)
		i++;
	if (i >= L->lengh)return 0;
	else return i + 1;
}
/*��������Ԫ��*/
bool ListInsert(SqList *&L, int i, char &e)
{
	int j;
	if (i<1 || i>L->lengh + 1)
		return false;
	i--;//�߼����ת�������
	for (j = L->lengh; j > i; j--)
		L->data[j] = L->data[j - 1];
	L->data[i] = e;
	L->lengh++;
	return true;
}
/*ɾ������Ԫ��*/
bool ListDelete(SqList*& L, int i, char &e)
{
	int j;
	if (i<1 || i>L->lengh)
		return false;
	i--;
	e = L->data[i];
	for (j = i; j < L->lengh - 1; j++)
		L->data[j] = L->data[j + 1];
	L->lengh--;
	return true;
}

//ɾ�����Ա�������ֵΪx��Ԫ��
//1.�ؽ���
void delnode1(SqList*& A, char x)
{
	int k = 0, i;
	for (i = 0; i < A->lengh; i++)
	{
		if (A->data[i] != x)
		{
			A->data[k] = A->data[i];
			k++;
		}
	}
	A->lengh = k;
}
//2.ǰ�Ʒ�
void delnode2(SqList*& A, char x)
{
	int k = 0, i=0;
	while (i < A->lengh)
	{
		if (A->data[i] == x)
			k++;
		else
			A->data[i - k] = A->data[i];
		i++;
	}
}
//�Ե�һ��Ԫ��Ϊ��׼��С����ǰ����ں�
//�Ի���
void move1(SqList*& A)
{
	int i=0, j=A->lengh-1;
	char temp;
	char p = A->data[0];
	while (i < j)
	{
		while (i < j && A->data[i] <= p)
			i++;
		while (i<j && A->data[j]>p)
			j--;
		if (i < j)
		{
			temp = A->data[i];
			A->data[i] = A->data[j];
			A->data[j] = temp;
		}
	}
	temp = A->data[0];
	A->data[0] = A->data[j];
	A->data[j] = temp;
}
//ǰ�󽻻���
void move2(SqList*& A)
{
	int i = 0, j = A->lengh - 1;
	char pivot = A->data[0];
	while (i < j)
	{
		while (j > i && A->data[j] > pivot)
			j--;
		A->data[i] = A->data[j];
		while (i < j && A->data[i] <= pivot)
			i++;
		A->data[j] = A->data[i];
	}
	A->data[i] = pivot;
}