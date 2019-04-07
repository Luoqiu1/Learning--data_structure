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
	Q.rear->next=NULL;//�����������ʵ�֣� 
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
 
