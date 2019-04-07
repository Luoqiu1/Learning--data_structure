#include <bits/stdc++.h>
using namespace std;
#define True 1
#define False 0
#define Ok 1
#define Error 0
#define Overflow -2
typedef int Status;
typedef int QElemType;
typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue &Q)
{
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
	if(!Q.front) exit(Overflow);
	Q.front->next=NULL;
	return Ok;
}

Status DestroyQueue(LinkQueue &Q)
{
	while(Q.front){
		Q.rear=Q.front->next;
		free(Q.front);
		Q.front=Q.rear;
	}
	return Ok;
}

Status CLearQueue(LinkQueue &Q)
{
	QueuePtr p,q;
	if (!Q.front) exit(Overflow);
	p=Q.front->next;
	Q.front->next=NULL;
	q=p->next;
	while(p!=Q.rear){
		free(p);
		p=q;
	}
	Q.rear=Q.front;
	return Ok;
}

Status QueueEmpty(LinkQueue Q)
{
	if(Q.front==Q.rear)return True;
	return False;
}

int QueueLength(LinkQueue Q)
{
	QueuePtr p;
	int n=0;
	p=Q.front;
	while(p!=Q.rear){
		n++;
		p=p->next;
	}
	return n;
}

Status GetHead(LinkQueue Q,QElemType &e)
{
	QueuePtr p;
	if(Q.front==Q.rear)return Error;
	p=Q.front->next;
	e=p->data;
	return Ok;
}

Status EnQueue(LinkQueue &Q,QElemType e)
{
	QueuePtr p;
	p=(QueuePtr)malloc(sizeof(QNode));
	if(!p) exit(Overflow);
	Q.rear->next=p;
	Q.rear=p;
	Q.rear->data=e;
	Q.rear->next=NULL;//这里三行如何实现？ 
	return Ok;
}

Status DeQueue(LinkQueue &Q,QElemType &e)
{
	QueuePtr p;
	if(Q.front==Q.rear)return Error;
	p=Q.front->next;
	Q.front->next=p->next;
	e=p->data;
	if(Q.rear==p) Q.rear==Q.front;
	free(p);
	return Ok;
}

Status QueueTraverse(LinkQueue &Q)
{
	QueuePtr p=Q.front->next;
	if(p==NULL)return Error;
	while(p){
		cout<<p->data<<' ';
		p=p->next;
	}
	cout<<endl;
	return Ok;
}

int main()
{
	int i,n;
	QElemType k,h,a,f;
	LinkQueue Q;
	printf("创建一个空队列！\n");
	InitQueue(Q);
	printf("判断队列是否为空！\n");
	printf("QueueEmpty(Q)=%d\n",QueueEmpty(Q));
	printf("创建队列的元素个数：\n");
	scanf("%d", &n);
	printf("输入%d个插入队列的元素的值：\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d", &k);
		EnQueue(Q, k);
	}
    printf("输出队列元素的个数：%d\n",QueueLength(Q));
	printf("输出队列元素的值：\n");
	QueueTraverse(Q);
	printf("输入插入队列的元素的值：");
	scanf("%d", &h);
	EnQueue(Q, h);
	printf("输出插入一个队列元素后队列元素的值：\n");
	QueueTraverse(Q);
    DeQueue(Q, a);
	printf("输出第1个删除的队头元素的值：%d\n", a);
	DeQueue(Q, a);
	printf("输出第2个删除的队头元素的值：%d\n", a);
	printf("输出两次删除队头元素后队列的元素值：");
	QueueTraverse(Q);
	GetHead(Q, f);
	printf("输出队头元素的值：%d\n",f);
	printf("输出队列元素的个数：%d\n",QueueLength(Q));
	printf("将Q清为空队列！\n");
	CLearQueue(Q);
	printf("输出队列元素的个数：%d\n",QueueLength(Q));
	printf("判断队列是否为空！\n");
	printf("QueueEmpty(Q)=%d\n",QueueEmpty(Q));
	return 0;
}
 
