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
	LinkList p=L;//pΪָ���ж�������������еĵ�һ������ǰһ��λ�� 
	while(1){
		if(!p->next->next){//�����жϵ����������� 
		//	cout<<"here";
			if(p->data==p->next->data){
				p->next=NULL;free(p->next->next);break;
			}
			else break;
		}
		while(1){
			if(p->next->data==p->next->next->data){
				if(p->next->next){//����Ϊ���������� 
					LinkList g=p->next->next;//�ͷŽ�� 
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
	} */  //�ö�Ϊ��������
	return Ok;   
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
