#include <bits/stdc++.h>
using namespace std;
#define True 1
#define Error 0
#define Overflow -2
#define Ok 1
typedef int Status;
typedef int TElemType;
typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

Status CreateBiTree(BiTree &T)
{
	char ch;
	scanf("%c",&ch);
	if(ch=='#')T=NULL;
	else{
		if(!(T=(BiTree)malloc(sizeof(BiTNode))))exit(Overflow);
		T->data=ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return Ok;
 } 
 
Status PreOrderTraverse(BiTree T)
{
	if(T){
		printf("%c",T->data);
		if(PreOrderTraverse(T->lchild))
			if(PreOrderTraverse(T->rchild)) return Ok;
	}
	else return Ok;
}

Status InOrderTraverse(BiTree T)
{
	int m=0;
	if(T){
		if(InOrderTraverse(T->lchild))m=1;
		printf("%c",T->data);
		if(m)
			if(InOrderTraverse(T->rchild))return Ok;
		return Error;
	}
	else return Ok;
}

Status PostOrderTraverse(BiTree T)
{
	if(T){
		if(PostOrderTraverse(T->lchild))
			if(PostOrderTraverse(T->rchild)){
				printf("%c",T->data);return Ok;
			}
		return Error;
	}
	else return Ok;
}

int Depth(BiTree T)
{
	int leftDepth,rightDepth;
	if(T==NULL)return 0;
	else{
		leftDepth=Depth(T->lchild);
		rightDepth=Depth(T->rchild);
		if(leftDepth>=rightDepth)return leftDepth+1;
		else return rightDepth+1;
	}
}

Status NodeCount(BiTree T)
{
	if(T){
		Nodenum++;
		if(NodeCount(T->lchild))
			if(NodeCount(T->rchild))return Ok;
		return Error;
	}
	else return Ok;
}

int main ()
{
	BiTree T,B;
	printf("�������������������������������н���ֵ��\n");
	CreateBiTree(T);
	NodeCount(T);
	printf("�������Ľ�����Ϊ��%d\n",Nodenum);
	printf("�����������Ϊ��%d\n",Depth(T));
	printf("�������������������ǣ�\n");
	PreOrderTraverse(T);
	cout<<endl;
	printf("�������������������ǣ�\n");
	InOrderTraverse(T);
	cout<<endl;
	printf("�������������������ǣ�\n");
	PostOrderTraverse(T);
	cout<<endl;
	printf("�����������Ҷ�ӽ�㣺\n");
	LeafCount(T);
	cout<<endl;
	printf("ͳ�ƶ�������Ҷ�ӽ�������%d\n",Count);
	printf("���������������н�������������\n");
	ExchangeBiTree(T);
	if(CopyBiTree(T,B)==Ok)printf("�ɹ����ƶ�����T��������B��\n");
	if(DestroyTree(T)==Ok)printf("�ɹ����ٶ�����T��\n");
	if(ClearTree(T)==Ok)printf("��������T��Ϊ������\n");
	printf("�������������B������ǣ�\n");
	PreOrderTraverse(B);
	cout<<endl;
	printf("�������������B������ǣ�\n");
	InOrderTraverse(B);
	cout<<endl;
	printf("�������������B������ǣ�\n");
	PostOrderTraverse(B);
	cout<<endl;
	return 0;
}
