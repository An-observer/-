#include<iostream>

#define maxSize 10

using namespace std;

typedef struct //����˳���
{
	int data[maxSize];
	int length;
}Sqlist;

void initList(Sqlist& L) //��ʼ��˳�����length����
{
	L.length = 0;
}

int getElem(Sqlist L, int x, int& e) //��Ԫ���±����Ԫ��ֵ
{
	if (x < 0 || x > L.length - 1) //ֻҪ���±��Ҫ����Ƿ�Խ��
	{
		return 0;
	}
	else
	{
		e = L.data[x];
		return 1;
	}
}

int findElem(Sqlist L, int e) //����Ԫ��ֵ����Ԫ���±�
{
	for (int i = 0; i < L.length; i++)
		if (e == L.data[i])
			return i;
	return -1;
}

int insertElem(Sqlist& L, int p, int e)
{
	if (p < 0 || p > L.length || L.length == maxSize)
		return 0;
	for (int i = p; i < L.length; i++)
	{
		L.data[i + 1] = L.data[i];
	}
	L.data[p] = e;
	(L.length)++;
	return 1;
}


int main()
{
	Sqlist L;

	return 0;
}