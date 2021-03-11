#include<iostream>

using namespace std;

typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode;

typedef struct DLNode
{
	int data;
	struct DLNode* prior;
	struct DLNode* next;
};

void createlistR(LNode*& C, int a[], int n)
{
	LNode* s, * r;
	C = new LNode;
	C->next = NULL;
	r = C;
	for (int i = 0; i < n; i++)
	{
		s = new LNode;
		s->data = a[i];
		r->next = s;
		r = r->next;
	}
	r->next = NULL;
}

void createlistF(LNode*& C, int a[], int n)
{
	LNode* s;
	C = new LNode;
	C->next = NULL;
	for (int i = 0; i < n; i++)
	{
		s = new LNode;
		s->data = a[i];
		s->next = C->next;
		C->next = s;
	}
}

void mergeR(LNode* A, LNode* B, LNode*& C)
{
	LNode* p = A->next;
	LNode* q = B->next;
	C = new LNode;
	C->next = NULL;
	LNode* r = C;
	delete(A);
	delete(B);
	while(p != NULL && q != NULL)
	{
		if (p->data <= q->data)
		{
			r->next = p;
			p = p->next;
			r = r->next;
		}
		else
		{
			r->next = q;
			q = q->next;
			r = r->next;
		}
	}
	if (p != NULL)
		r->next = p;
	if (q != NULL)
		r->next = q;
}

void mergeF(LNode* A, LNode* B, LNode*& C)
{
	LNode* p = A;
	LNode* q = B;
	C = A;
	C->next = NULL;
	delete(B);
	LNode* s;
	while (p != NULL && q != NULL)
	{
		if (p->data <= q->data)
		{
			s = p;
			p = p->next;
			s->next = C->next;
			C->next = s;
		}
		else
		{
			s = q;
			q = q->next;
			s->next = C->next;
			C->next = s;
		}
	}
	
	while (p != NULL)
	{
		s = p;
		p = p->next;
		s->next = C->next;
		C->next = s;
	}
	while (q != NULL)
	{
		s = q;
		q = q->next;
		s->next = C->next;
		C->next = s;
	}
}

int findAndDelete(LNode* C, int x)
{
	LNode* p, * q;
	p = C;
	while (p->next != NULL && p->next->data != x)
		p = p->next;
	if (p->next == NULL)
		return 0;
	else
	{
		q = p->next;
		p->next = q->next;
		delete(q);
		return 1;
	}
}

void print(LNode* C)
{
	LNode* p = C->next;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	delete p;
	cout << endl;
}

void createDoubleListR(DLNode*& C, int a[], int n)
{
	C = new DLNode;
	C->next = NULL;
	C->prior = NULL;
	DLNode* r = C, * s;
	for (int i = 0; i < n; i++)
	{
		s = new DLNode;
		s->data = a[i];
		r->next = s;
		s->prior = r;
		r = s;
	}
	r->next = NULL;
}

int main()
{
	LNode* C;
	int a[5] = { 1,23,5,8,4 };
	createlistR(C, a, 5);
	print(C);
	cout << findAndDelete(C, 5) << endl;
	cout << findAndDelete(C, 23) << endl;
	cout << findAndDelete(C, 0) << endl;
	print(C);

	delete C;
	return 0;
}