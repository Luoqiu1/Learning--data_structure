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
	//先序遍历
	if(T) {
		cout<<T->data;
		InOrderTraverse1(T->firstchild);
		InOrderTraverse1(T->nextsibling);
	}
}
void InOrderTraverse2(CSTree T) {
	//中序遍历
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
	cout<<"请输入二叉树（孩子-兄弟）的元素！\n";
	CreateTree(s);
	cout<<"树的先根遍历输出为：\n";	
	InOrderTraverse1(s);
	cout<<"\n树的后根遍历输出为：\n";	
	InOrderTraverse2(s);
	CountLeaf(s);
	a=Depth(s);
	cout<<"\n树的深度为："<<a;
	cout<<"树的叶子结点个数为："<<n;
	
}
