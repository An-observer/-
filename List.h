#pragma once
void reverse(int& x, int& y)
{
	y = x ^ y;
	x = x ^ y;
	y = x ^ y;
}

typedef struct LNode
{
	int val;
	struct LNode* next;
}LNode, * LinkList;

LinkList List_HeadInsert(LinkList &L, const int x)
{
	LNode* s;
	L = new LNode;
	s->val = x;
	s->next = L->next;
	L->next = s;
	return L;
}

