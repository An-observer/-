#include<iostream>

#define maxSize 10

using namespace std;

typedef struct  //邻接矩阵结点
{
	int no;
	char info;
}VertexType;

typedef struct  //图的定义
{
	int edges[maxSize][maxSize];
	int n, e;  //顶点数和边数
	VertexType vex[maxSize];
}MGraph;

int main()
{

	return 0;
}