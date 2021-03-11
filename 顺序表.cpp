#include<iostream>

#define maxSize 10

using namespace std;

typedef struct //建立顺序表
{
	int data[maxSize];
	int length;
}Sqlist;

void initList(Sqlist& L) //初始化顺序表，将length置零
{
	L.length = 0;
}

int getElem(Sqlist L, int x, int& e) //按元素下标查找元素值
{
	if (x < 0 || x > L.length - 1) //只要有下标就要检查是否越界
	{
		return 0;
	}
	else
	{
		e = L.data[x];
		return 1;
	}
}

int findElem(Sqlist L, int e) //根据元素值查找元素下标
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