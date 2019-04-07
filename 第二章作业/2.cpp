#include <bits/stdc++.h>
using namespace std;
#define Overflow -2
#define Ok 1
#define Error 0
typedef int Status;
typedef int ElemType;
typedef struct LNode{
	ElemType data;
	LNode *next;
}LNode,*LinkList;

Status InitList(LinkList &L,int n)
{
	L=(LinkList)malloc(sizeof(LNode));
	if(!L) exit(Overflow);
	LinkList p=L;
	while(n--){
		LinkList q=(LinkList)malloc(sizeof(LNode));
		p->next=q;
		p=p->next;
		cin>>p->data;
	}
	p->next=NULL;
	return Ok;
}

Status Go(LinkList &L)
{
	LinkList p=L;//p为指向判断连续的两结点中的第一个结点的前一个位置 
	while(1){
		if(!p->next->next){//若已判断到最后两个结点 
		//	cout<<"here";
			if(p->data==p->next->data){
				p->next=NULL;free(p->next->next);break;
			}
			else break;
		}
		while(1){
			if(p->next->data==p->next->next->data){
				if(p->next->next){//若不为最后两个结点 
					LinkList g=p->next->next;//释放结点 
					p->next->next=p->next->next->next;
					free(g);
					break;
				//	p=p->next;
				}
				else {
				p=p->next;
				break;
				}
			}
			else {
				p=p->next;
				break;
			}
		}
		
	}
/*	p=L;
	while(p->next){
		p=p->next;
		cout<<p->data<<' ';
	} */  //该段为输出结果段
	return Ok;   
}

int main ()
{
	int n;
	LinkList L;
	cout<<"输入创建链表的元素个数n：\n";
	cin>>n;
	cout<<"依次输入n个整数作为链表元素：\n";
	InitList(L,n);
	cout<<"将所有小于零的结点移到所有大于等于零的结点的前面：\n";
	Go(L); 
	return 0;
}
