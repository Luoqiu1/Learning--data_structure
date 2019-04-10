#include <bits/stdc++.h> 
#define Ok 1
#define True 1
#define Error 0
#define Overflow -2
#define Link 0
#define Thread 1
typedef int Status;
typedef int TElemType;
typedef enum PointTag{
	Link,Thread;
}
typedef struct BiThrTree{
	TElemType data;
	struct BiThrTree *lchild,*rchild;
	PointTag LTag,RTag;
}BiThrNode,*BiThrTree;

Status CreateBiThrTree(BiThrTree &T)
{
	char ch;
	scanf("%c",ch);getchar();
	if(ch=='#')T=nullptr;
	else {
		if(!(T=(BiThrTree)malloc(sizeof(BiThrNode))))exit(Overflow);
		T->data=ch;
	//	T->LTag=Link;
	//	T->RTag=Link;
		CreateBiThrTree(T->lchild);
		CreateBiThrTree(T->rchild);
	}
	return Ok;
}
/*
Status InOrderThreading(BiThrTree &Thrt,BiThrTree T)
{
	
}
*/

Status PrintElement(TElemType e)
{
	printf("%c",e);
	return Ok;
}


int main ()
{
	BiThrTree T,Thrt;
	printf("����������������������������������������н���ֵ��\n");
	CreateBiThrTree(T);
	if(InOrderThreading(Thrt,T)==Ok)
		printf("�ɹ�������������������\n");
	InOrderTraverse_Thr(Thrt,PrintElement);
	printf("\n");
	return 0;
}
