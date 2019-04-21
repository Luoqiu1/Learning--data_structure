#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define True 1
#define Error 0
#define Overflow -2
#define Ok 1
typedef char TElemType;
typedef int Status;
typedef enum PointerTag{Link,Thread//Link==0：指针，Thread==1：线索 
};
typedef struct BiThrNode{
	TElemType data;
	struct BiThrNode *lchild,*rchild;
	PointerTag LTag,RTag;
}BiThrNode,*BiThrTree;

Status CreateBiThrTree(BiThrTree &T)
{
	T=(BiThrNode*)malloc(sizeof(BiThrNode));
	if(!T)exit(Overflow);
	char ch;scanf("%c",&ch);
	if(ch=='#')exit(Overflow);
	T->data=ch;T->lchild=nullptr;T->rchild=nullptr;//T->LTag=Thread;T->RTag=Thread; 
	int FatherNum=1;
	BiThrNode **FatherTree=(BiThrNode**)malloc(sizeof(BiThrNode*)*FatherNum);
	while(FatherNum){
		BiThrNode **ChildTree=(BiThrNode**)malloc(sizeof(BiThrNode*)*FatherNum*2);
		int j=0;int ChildNum=0;
		while(FatherNum--){
			scanf("%c",&ch);if(ch=='#')j++;
			else{
				ChildNum++;
				BiThrTree q=(BiThrNode*)malloc(sizeof(BiThrNode));
				if(!q)exit(Overflow);
				q->data=ch;q->lchild=nullptr;q->rchild=nullptr;//q->LTag=Thread;q->RTag=Thread;
				if(j%2==0){//左树 
					FatherTree[j/2]->lchild=q;
				}
				else{
					FatherTree[j/2]->rchild=q;
				}
				j++;
			}
		}
		FatherNum=ChildNum;
		free(FatherTree);
		FatherTree=ChildTree;
	}
}

int main()
{
	BiThrTree T,Thrt;
	printf("层序创建二叉树，输入结点的值：\n");
	CreateBiThrTree(T);
}
