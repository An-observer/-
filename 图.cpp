#include<iostream>

#define maxSize 10

using namespace std;

typedef struct  //�ڽӾ�����
{
	int no;
	char info;
}VertexType;

typedef struct  //ͼ�Ķ���
{
	int edges[maxSize][maxSize];
	int n, e;  //�������ͱ���
	VertexType vex[maxSize];
}MGraph;

int main()
{

	return 0;
}