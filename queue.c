#include<stdio.h>
typedef int ElemType;
typedef struct QNode
{
	ElemType data;
	struct QNode* next;
}qNode,*queueptr;
typedef struct
{
	queueptr front, rear;
}Linkqueue;
initQueue(Linkqueue* q)
{
	q->front = q->rear = (queueptr)malloc(sizeof(qNode));
	if (!q->front)
		exit(0);
	q->front->next = NULL;
}
insertQueue(Linkqueue* q, ElemType e)
{
	queueptr p = (queueptr)malloc(sizeof(qNode));
	if (!p)
		exit(0);
	p->data = e;
	p->next = NULL;
	q->rear->next = p;
	q->rear = p;
}
deleteQueue(Linkqueue* q, ElemType* e)
{
	if (q->front == q->rear)
		return;
	queueptr p = q->front->next;
	p->data = *e;
	q->front->next = p->next;
	if (q->rear == p)
	{
		q->rear = q->front;
	}
	free(p);
}
destoryqueue(Linkqueue* q)
{
	while (q->front)
	{
		q->rear = q->front->next;
		free(q->front);
		q->front = q->rear;
	}
}
