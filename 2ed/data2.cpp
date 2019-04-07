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
	p->next=NULL;
}

int CreateList_Lc(LinkList &L,int n)
{
	L=(LinkList)malloc(sizeof(LNode));
	LinkList p;
	p=L;
	for( ;n>0;n--){
		LinkList q=(LinkList)malloc(sizeof(LNode));
	//	scanf("%d",&q->data);
		p->next=q;p=q;
	}
	p->next=NULL;
}

void OutputList_L(LinkList L)
{
//	printf("here");
	LinkList p=L->next;
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

void OutputList_Lc(LinkList L)
{
//	printf("here");
	int i=0;
	LinkList p=L->next;
	while(i!=10){
		i++;
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

void Go_L(LinkList &La,LinkList &Lb,LinkList &Lc)
{
	LinkList pa,pb,pc;
	pa=La->next;pb=Lb->next;
	pc=Lc->next;
	while(pa&&pb){
		if(pa->data<pb->data){
			pc->data=pa->data;
			pc=pc->next;
			pa=pa->next;	
		}
		else{
			pc->data=pb->data;
			pc=pc->next;
			pb=pb->next;
		}
	}
//	printf("here");
	while(pa){
		pc->data=pa->data;
		pc=pc->next;
		pa=pa->next;
	}
	while(pb){
		pc->data=pb->data;
		pc=pc->next;
		pb=pb->next;
	}
	free(Lb);free(La);
}

int main ()
{
	ElemType b,dd;
	LinkList La,Lb,Lc;
	printf("�����ǵݼ�������La��Lb������5��Ԫ�أ�\n");
	CreateList_L(La,5);
	CreateList_L(Lb,5);
	printf("���������La��Lb����Ԫ�أ�\n");
	OutputList_L(La);
	OutputList_L(Lb);
	CreateList_Lc(Lc,15);
	printf("��La��Lb����ϲ�ΪLc�����Ұ��ǵݼ����У�\n");
	Go_L(La,Lb,Lc);
	printf("����µ�����Lc��");
	OutputList_Lc(Lc);
	return 0;
}
