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
			//傻了啊。。。没对q做操作，不是无限循环了！
			// 指针里最容易出这个错。。！p=p->next 相当于i j循环里的自增 ++i ++j！！！
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
	printf("请输入需要创建链表的元素个数n！\n");
	int n;
	cin>>n;
	printf("请依次输入这n个元素！\n");
	InitList(L,n);
	printf("输出这个链表！\n");
	PutoutList(L,n);
	printf("对这个链表中的元素进行逆置操作，并输出逆置后的表！\n");
	Fristback(L);
	PutoutList(L,n);
	printf("将链表中的元素按非递减排列，并输出排列后的表！\n");
	Go(L,n);
	PutoutList(L,n);
	return 0;
}
