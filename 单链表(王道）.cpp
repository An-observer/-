#include<iostream>

using namespace std;

typedef struct LNode                  // 以结构体定义节点
{
	int data;
	struct LNode* next;
}LNode, * LinkList;

LinkList List_HeadInsert(LinkList& L) // 头插法
{
	LNode* s; int x;
	L = new LNode;
	L->next = NULL;
	cin >> x;
	while (x != 9999)
	{
		s = new LNode;
		s->data = x;
		s->next = L->next;
		L->next = s;
		cin >> x;
	}
	return L;
}

LinkList List_TailInsert(LinkList& L) // 尾插法
{
	int x;
	L = new LNode;
	LNode* s, * r = L;
	cin >> x;
	while (x != 9999)
	{
		s = new LNode;
		s->data = x;
		r->next = s;
		r = s;
		cin >> x;
	}
	r->next = NULL;
	return L;
}

LNode* GetElem(LinkList L, int i)   // 按序号查找， i即为序号
{
	int j = 1;
	LNode* p = L->next;
	if (i == 0)
		return L;
	if (i < 0)
		return NULL;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	return p;
}

LNode* LocateElem(LinkList L, double e)  // 按值查找
{
	LNode* p = L->next;
	while (p != NULL && p->data != e)
	{
		p = p->next;
	}
	return p;
}

int main()
{
	LinkList L;
	//头插法
	List_HeadInsert(L);
	cout << L->data << endl;
	return 0;
}