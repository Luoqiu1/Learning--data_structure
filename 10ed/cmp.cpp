#include <iostream>
#define MAXSIZE 100
using namespace std;
typedef char ElemType;
typedef struct CSNode{
	ElemType data;
	struct CSNode *firstchild,*nextsibling;
}CSNode,*CSTree;
void CreateTree(CSTree &T)
{   char ch; 
	cin>>ch;
	if(ch=='#')
	  T=NULL;
	else
	{
		T=new CSNode;
		T->data=ch;
		CreateTree(T->firstchild);
		CreateTree(T->nextsibling);
	}
}
int n=0;
void CountLeaf(CSTree T)
{
	if(T)
	{
		if(!T->firstchild)
		  n++;
		  CountLeaf(T->firstchild);
		  CountLeaf(T->nextsibling);
	}
}
int Depth(CSTree T)
{   int d,dc,ds;
	if(!T)
	  d=0;
	else
	{
		dc=Depth(T->firstchild);
		ds=Depth(T->nextsibling);
		d=dc+1>+ds?dc+1:ds;
	 } 
	return d; 
}
void InOrderTraverse1(CSTree T) { 
	//�������
	if(T) {
		cout<<T->data;
		InOrderTraverse1(T->firstchild);
		InOrderTraverse1(T->nextsibling);
	}
}
void InOrderTraverse2(CSTree T) {
	//�������
	if(T) {
		InOrderTraverse2(T->firstchild);
		cout<<T->data;
		InOrderTraverse2(T->nextsibling);
	}
}
int main()
{
	CSTree s;
	int a;
	cout<<"�����������������-�ֵܣ���Ԫ�أ�\n";
	CreateTree(s);
	cout<<"�����ȸ��������Ϊ��\n";	
	InOrderTraverse1(s);
	cout<<"\n���ĺ���������Ϊ��\n";	
	InOrderTraverse2(s);
	CountLeaf(s);
	a=Depth(s);
	cout<<"\n�������Ϊ��"<<a;
	cout<<"����Ҷ�ӽ�����Ϊ��"<<n;
	
}
