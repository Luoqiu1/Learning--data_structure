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
	printf("����һ���ն��У�\n");
	InitQueue(Q);
	printf("�ж϶����Ƿ�Ϊ�գ�\n");
	printf("QueueEmpty(Q)=%d\n",QueueEmpty(Q));
	printf("�������е�Ԫ�ظ�����\n");
	scanf("%d", &n);
	printf("����%d��������е�Ԫ�ص�ֵ��\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d", &k);
		EnQueue(Q, k);
	}
    printf("�������Ԫ�صĸ�����%d\n",QueueLength(Q));
	printf("�������Ԫ�ص�ֵ��\n");
	QueueTraverse(Q);
	printf("���������е�Ԫ�ص�ֵ��");
	scanf("%d", &h);
	EnQueue(Q, h);
	printf("�������һ������Ԫ�غ����Ԫ�ص�ֵ��\n");
	QueueTraverse(Q);
    DeQueue(Q, a);
	printf("�����1��ɾ���Ķ�ͷԪ�ص�ֵ��%d\n", a);
	DeQueue(Q, a);
	printf("�����2��ɾ���Ķ�ͷԪ�ص�ֵ��%d\n", a);
	printf("�������ɾ����ͷԪ�غ���е�Ԫ��ֵ��");
	QueueTraverse(Q);
	GetHead(Q, f);
	printf("�����ͷԪ�ص�ֵ��%d\n",f);
	printf("�������Ԫ�صĸ�����%d\n",QueueLength(Q));
	printf("��Q��Ϊ�ն��У�\n");
	CLearQueue(Q);
	printf("�������Ԫ�صĸ�����%d\n",QueueLength(Q));
	printf("�ж϶����Ƿ�Ϊ�գ�\n");
	printf("QueueEmpty(Q)=%d\n",QueueEmpty(Q));
	return 0;
}
 
