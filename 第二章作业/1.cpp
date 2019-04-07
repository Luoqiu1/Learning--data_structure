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
{//将所有小于零的结点移到所有大于等于零的结点的前面操作等价于将所有大于等于零的结点移到链表尾部 
	int n;//记录大于等于零的结点的个数
	LinkList p=L;
	while(p->next){
		p=p->next;
		if(p->data>0||p->data==0)n++;
	}
//	cout<<n<<endl;
//	cout<<p->data;
	LinkList q=p;//准备一个指针记录当前的链表尾部位置,初始化时当前的p即为表尾位置 
	LinkList m=L;//若第一个为不满足条件的结点，标记开始位置
	while(n--){
		LinkList r=L;//每次开始寻找第一个大于等于零的结点,r指针指向当前位置,r的下一个结点为满足条件的结点
		while(1){
			if(r->next->data>0||r->next->data==0) break;//找到了。下一个结点即为满足条件的结点，打破循环 
			r=r->next;
		}
		while(1){
			if(L->next->data<0){
				if(m->next->data<0){
					m=m->next;
				}
				else break;
			}
			//从第一个开始，第一个满足条件的结点的前一个结点。 	
			else break;
		}
		q->next=r->next;//当前链尾指向满足条件的结点 
		m->next=r->next->next;//头节点指向满足条件的结点的后一个结点 
		q->next->next=NULL;//链尾指向NULL 
		q=q->next;//刷新链尾位置
//		cout<<"here1";
	}
//	cout<<"here2";
/*	p=L;
	while(p->next){
		p=p->next;
		cout<<p->data<<' ';
	}
	return Ok; */ //该段为输出结果段 
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
