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
{//������С����Ľ���Ƶ����д��ڵ�����Ľ���ǰ������ȼ��ڽ����д��ڵ�����Ľ���Ƶ�����β�� 
	int n;//��¼���ڵ�����Ľ��ĸ���
	LinkList p=L;
	while(p->next){
		p=p->next;
		if(p->data>0||p->data==0)n++;
	}
//	cout<<n<<endl;
//	cout<<p->data;
	LinkList q=p;//׼��һ��ָ���¼��ǰ������β��λ��,��ʼ��ʱ��ǰ��p��Ϊ��βλ�� 
	LinkList m=L;//����һ��Ϊ�����������Ľ�㣬��ǿ�ʼλ��
	while(n--){
		LinkList r=L;//ÿ�ο�ʼѰ�ҵ�һ�����ڵ�����Ľ��,rָ��ָ��ǰλ��,r����һ�����Ϊ���������Ľ��
		while(1){
			if(r->next->data>0||r->next->data==0) break;//�ҵ��ˡ���һ����㼴Ϊ���������Ľ�㣬����ѭ�� 
			r=r->next;
		}
		while(1){
			if(L->next->data<0){
				if(m->next->data<0){
					m=m->next;
				}
				else break;
			}
			//�ӵ�һ����ʼ����һ�����������Ľ���ǰһ����㡣 	
			else break;
		}
		q->next=r->next;//��ǰ��βָ�����������Ľ�� 
		m->next=r->next->next;//ͷ�ڵ�ָ�����������Ľ��ĺ�һ����� 
		q->next->next=NULL;//��βָ��NULL 
		q=q->next;//ˢ����βλ��
//		cout<<"here1";
	}
//	cout<<"here2";
/*	p=L;
	while(p->next){
		p=p->next;
		cout<<p->data<<' ';
	}
	return Ok; */ //�ö�Ϊ�������� 
}

int main ()
{
	int n;
	LinkList L;
	cout<<"���봴�������Ԫ�ظ���n��\n";
	cin>>n;
	cout<<"��������n��������Ϊ����Ԫ�أ�\n";
	InitList(L,n);
	cout<<"������С����Ľ���Ƶ����д��ڵ�����Ľ���ǰ�棺\n";
	Go(L); 
	return 0;
}
