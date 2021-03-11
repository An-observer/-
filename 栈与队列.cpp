#include<iostream>
#define maxSize 10

using namespace std;

/*Ë³ĞòÕ»*/
typedef struct
{
	int data[maxSize];
	int top;
}SqStack;

void initSqStack(SqStack& st)
{
	st.top = -1;
}
bool isEmpty(SqStack st)
{
	if (st.top == -1)
		return true;
	else
		return false;
}

bool push(SqStack& st, int x)
{
	if (st.top == maxSize - 1)
		return false;
	else
	{
		(st.top)++;
		st.data[st.top] = x;
		return true;
	}
}

bool pop(SqStack& st, int& x)
{
	if (isEmpty(st))
		return false;
	else
	{
		x = st.data[st.top];
		(st.top)--;
		return true;
	}
}

/*Á´Õ»*/
typedef struct LNode
{
	int data;
	struct LNode* next;
};
void initStackl(LNode*& lst)
{
	lst = new LNode;
	lst->next = NULL;
}

bool isEmptyl(LNode* lst)
{
	if (lst->next == NULL)
		return true;
	else
		return false;
}

void pushl(LNode*& lst, int x)
{
	LNode* s = new LNode;
	s->data = x;
	s->next = lst->next;
	lst->next = s;
}

bool popl(LNode*& lst, int& x)
{
	if (lst->next == NULL)
		return false;
	else
	{
		x = lst->next->data;
		lst->next = lst->next->next;
		return true;
	}
}

/*Ë³Ğò¶Ó*/
typedef struct
{
	int data[maxSize];
	int front;
	int rear;
}SqQueue;

void initQueue(SqQueue& qu)
{
	qu.front = qu.rear = 0;
}

bool isQueueEmpty(const SqQueue& qu)
{
	if (qu.front == qu.rear)
		return true;
	else
		return false;
}

bool enQueue(SqQueue& qu, const int& x)
{
	if ((qu.rear + 1) % maxSize == qu.front)
		return false;
	else
	{
		qu.rear = (qu.rear + 1) % maxSize;
		qu.data[qu.rear] = x;
		return true;
	}
}

bool deQueue(SqQueue& qu, int& x)
{
	if (qu.rear == qu.front)
		return false;
	else
	{
		qu.front = (qu.front + 1) % maxSize;
		x = qu.data[qu.front];
		return true;
	}
}

/*Á´¶Ó*/
typedef struct QNode
{
	int data;
	struct QNode* next;
}QNode;

typedef struct
{
	QNode* front;
	QNode* rear;
}LiQueue;

void initQueuel(LiQueue*& lqu)
{
	lqu = new LiQueue;
	lqu->front = lqu->rear = NULL;
}

bool isQueueEmptyl(LiQueue* lqu)
{
	if (lqu->front == NULL || lqu->rear == NULL)
		return true;
	else
		return false;
}

void enQueuel(LiQueue*& lqu, int x)
{
	QNode* s = new QNode;
	s->next = NULL;
	s->data = x;
	if (isQueueEmptyl(lqu))
		lqu->front = lqu->rear = s;
	else
	{
		lqu->rear->next = s;
		lqu->rear = s;
	}
}

bool deQueuel(LiQueue* lqu, int& x)
{
	if (isQueueEmptyl(lqu))
		return false;
	else
	{
		if (lqu->front == lqu->rear)
		{
			x = lqu->front->data;
			initQueuel(lqu);
			return true;
		}
		else
		{
			x = lqu->front->data;
			lqu->front = lqu->front->next;
			return true;
		}
	}
}

int main()
{

	return 0;
}