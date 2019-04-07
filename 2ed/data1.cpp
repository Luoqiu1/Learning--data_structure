#include <bits/stdc++.h>
typedef int ElemType;
using namespace std;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

int CreateList_L(LinkList &L,int n)
{
	L=(LinkList)malloc(sizeof(LNode));
	LinkList p;
	p=L;
	for( ;n>0;n--){
		LinkList q=(LinkList)malloc(sizeof(LNode));
		scanf("%d",&q->data);
		p->next=q;p=q;
	}
	p->next=L;
}

void OutputList_L(LinkList L)
{
//	printf("here");
	LinkList p=L->next;
	while(p!=L){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

void GetElem_L(LinkList L,int n,int &dd)
{
	int i=0;
	while(i!=n){
		i++;
		L=L->next;
	}
	dd=L->data;
}

void ListInsert_L(LinkList L,int n,int k)
{
	int i=0;
	LinkList p;
	LinkList x;
	
	while(i!=n){
		i++;
		p=L->next;
		L=p;
	}
	LinkList q=(LinkList)malloc(sizeof(LNode));
	q->next=p->next;p->next=q;q->data=k;
}

void ListDelete_L(LinkList L,int n)
{
	int i=0;
	while(i!=n-1){
		i++;
		L=L->next;
	}
	L->next=L->next->next;
}

int main ()
{
	ElemType b,dd;
	LinkList L;
	printf("��������������5��Ԫ�أ�\n");
	CreateList_L(L,5);
	printf("�������������Ԫ�أ�\n");
	OutputList_L(L);
	printf("����������2��λ��Ԫ�ص�dd��\n");
	GetElem_L(L,2,dd);
	printf("dd=%d\n",dd);
	printf("����Ԫ�� b��\n");
	scanf("%d",&b);
	printf("�ڵ������4��λ�ò���%d��\n",b);
	ListInsert_L(L,4,b);
	printf("��������������������Ԫ�أ�\n");
	OutputList_L(L);
	printf("ɾ���������3��λ�õ�Ԫ�أ�\n");
	ListDelete_L(L,3);
	printf("���ɾ����������������Ԫ�أ�\n");
	OutputList_L(L); 
	return 0;
}
