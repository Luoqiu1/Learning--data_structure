#include <bits/stdc++.h>
using namespace std;
#define True 1
#define Error 0
#define Overflow -2
#define Ok 1
int Nodenum,Leafnum;
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
	getchar();
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
	int leftDepth=0,rightDepth=0;
	if(T==NULL)return 0;
	else{
		leftDepth=Depth(T->lchild);
		rightDepth=Depth(T->rchild);
		if(leftDepth>rightDepth)return leftDepth+1;
		return rightDepth+1;
	}
}

Status NodeCount(BiTree T)
{
	if(T){
		Nodenum++;
		NodeCount(T->lchild);
		NodeCount(T->rchild);
	}
	else return Ok;
}

Status LeafCount(BiTree T)
{
	if(T){
		if(T->lchild==NULL)if(T->rchild==NULL){
			printf("%c",T->data);Leafnum++;return Ok;
		}
		if(LeafCount(T->lchild))
			if(LeafCount(T->rchild))return Ok;
		return Error;
	}
	else return Ok; 
}

Status ExchangeBiTree(BiTree &T)
{
	BiTree p;
	if(T){
		if(T->lchild||T->rchild){
			p=T->rchild;T->rchild=T->lchild;T->lchild=p;
		}
		if(ExchangeBiTree(T->lchild))
			if(ExchangeBiTree(T->rchild)) return Ok;
		return Error;
	}
	else return Ok;
}

Status CopyBiTree(BiTree T,BiTree &B)
{
	if(!T){
		B=T;
	}
	else{
		if(!(B=(BiTree)malloc(sizeof(BiTNode))))exit(Overflow);
		B->data=T->data;
		CopyBiTree(T->lchild,B->lchild);
		CopyBiTree(T->rchild,B->rchild);
	}
	return Ok;
}

Status DestroyTree(BiTree &T)
{
	if(T){
		DestroyTree(T->lchild);
		DestroyTree(T->rchild);
		free(T);
	}
	return Ok;
}

Status ClearTree(BiTree &T)
{
	if(T){
		ClearTree(T->lchild);
		ClearTree(T->rchild);
		T=NULL;
	}
	return Ok;
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
	printf("ͳ�ƶ�������Ҷ�ӽ�������%d\n",Leafnum);
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
