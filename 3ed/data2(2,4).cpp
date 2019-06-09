#include <bits/stdc++.h>
using namespace std;
typedef int Status;
#define True 1
#define Error 0
typedef int ElemType;
typedef struct LNode{
	struct LNode *next;
	ElemType data;
}LNode,*LinkList;

Status InitList(LinkList &L,int n)
{
	L=(LinkList)malloc(sizeof(LNode));
	LinkList p=L;
	if(!L) return Error;
	while(n--){
		LinkList q=(LinkList)malloc(sizeof(LNode));
		if(!q) return Error;
		p->next=q;cin>>q->data;
		p=q;
	}
	p->next=NULL;
	return True;
}

Status PutoutList(LinkList &L,int n)
{
	LinkList p=L;
	if(!L) return Error;
	while(n--){
		p=p->next;
		cout<<p->data<<' ';
	}
	cout<<endl;
	return True;
}

Status Fristback(LinkList &L)
{
	LinkList p,q,head=L;
	p=head->next;
	head->next=NULL;
	while(p!=NULL){
		q=p;
		p=p->next;
		q->next=head->next; 
		head->next=q;
	}	
	return True;
}

Status Go(LinkList &L,int n)
{
	LinkList p,q,s;
	if(!L->next)return Error;
	p=L;q=L->next;
	ElemType min=q->data;
	while(n--){
		while(q->next){
			if(min>q->next->data){
				s=q;min=q->next->data;
			}
			q=q->next;
		}
		LinkList r=s->next;
		s->next=s->next->next;
		r->next=p->next;
		p->next=r;
		p=p->next;
	}
	return True;
} 

Status Go(LinkList &L,int n)
{
	LinkList p,q;
	p=L->next;q=p->next;
	ElemType min=p->data;
	while(n--){
		while(q){
			if(q->data<min){
				min=q->data;
			}
			//ɵ�˰�������û��q����������������ѭ���ˣ�
			// ָ���������׳����������p=p->next �൱��i jѭ��������� ++i ++j������
			q=q->next;
			 
		}
		if(min!=p->data){
			q=p->next;
			ElemType mid=p->data;
			p->data=min;
			while(q->data!=min){
				q=q->data;
			}
			q->data=mid;
		}
		p=p->next;
		q=p->next;
	}
	return True;
 } 





int main()
{
	LinkList L;
	printf("��������Ҫ���������Ԫ�ظ���n��\n");
	int n;
	cin>>n;
	printf("������������n��Ԫ�أ�\n");
	InitList(L,n);
	printf("����������\n");
	PutoutList(L,n);
	printf("����������е�Ԫ�ؽ������ò�������������ú�ı�\n");
	Fristback(L);
	PutoutList(L,n);
	printf("�������е�Ԫ�ذ��ǵݼ����У���������к�ı�\n");
	Go(L,n);
	PutoutList(L,n);
	return 0;
}
