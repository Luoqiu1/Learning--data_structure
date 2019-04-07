#include <bits/stdc++.h>
using namespace std;
#define MAXQSIZE 100
#define True 1
#define False 0
#define Ok 1
#define Error 0
#define Overflow -2
typedef int Status;
typedef int QElemType;
typedef struct
{
	QElemType *base;
	int rear;
	int front;
}SqQueue;

Status InitQueue(SqQueue &Q)
{
	Q.base=(QElemType*)malloc(MAXQSIZE*sizeof(QElemType));
	if(!Q.base) exit(Overflow);
	Q.front=Q.rear=0;
	return Ok;
}

Status CLearQueue(SqQueue &Q)
{
	if(Q.front==Q.rear) exit(Overflow);
	while(Q.front%MAXQSIZE!=Q.rear)Q.front++;
	Q.front=Q.front%MAXQSIZE;
	return Ok;
}

Status QueueEmpty(SqQueue Q)
{
	if(Q.front==Q.rear)return True;
	return False;
}

int QueueLength(SqQueue Q)
{
	return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
}

Status GetHead(SqQueue Q,QElemType &e)
{
	if(Q.front==Q.rear)return Error;
	e=Q.base[Q.front];
	return Ok;
}

Status EnQueue(SqQueue &Q,QElemType e)
{
	if((Q.rear+1)%MAXQSIZE==Q.front) return Error;
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%MAXQSIZE;
	return Ok;
}

Status DeQueue(SqQueue &Q,QElemType &e)
{
	if(Q.front==Q.rear) return Error;
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%MAXQSIZE;
	return Ok;
}

Status QueueTraverse(SqQueue &Q)
{
	if(Q.front==Q.rear) return Error;
	int i=Q.front;
	while(i!=Q.rear){
		cout<<Q.base[i]<<' ';
		i=(i+1)%MAXQSIZE;
	}
	return Ok;
}

int main()
{
	int i,n;
	QElemType k,h,a,f;
	SqQueue Q;
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
 
