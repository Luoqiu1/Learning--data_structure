#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define True 1
#define Error 0
#define Overflow -2
#define Ok 1
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef char TElemType;
typedef int Status;
typedef enum PointerTag{Link,Thread//Link==0：指针，Thread==1：线索 
}PointerTag;//不用typedef的话直接 enum PointerTag{Link,Thread};  
typedef struct BiThrNode{
	TElemType data;
	struct BiThrNode *lchild,*rchild,*father;
	PointerTag LTag,RTag;
}BiThrNode,*BiThrTree;
BiThrTree pre=nullptr;

Status CreateBiThrTree(BiThrTree &T)
{
	T=(BiThrNode*)malloc(sizeof(BiThrNode));
	if(!T)exit(Overflow);
	char ch;scanf("%c",&ch);
	if(ch=='#')exit(Overflow);
	T->data=ch;T->lchild=nullptr;T->rchild=nullptr;T->LTag=Link;T->RTag=Link;//刚开始初始化的时候
	T->father=nullptr;
										//在创建线索二叉树的时候，标志域均初始化为Link！ 
	int FatherNum=1;
	BiThrNode **FatherTree=(BiThrNode**)malloc(sizeof(BiThrNode*)*FatherNum);
	FatherTree[0]=T;
	while(FatherNum){
		int ChildNum=FatherNum*2;
		BiThrNode **ChildTree=(BiThrNode**)malloc(sizeof(BiThrNode*)*ChildNum);
		int j=0;int NewChildNum=0;
		while(ChildNum--){
			scanf("%c",&ch);if(ch=='#')j++;
			else{
				BiThrTree q=(BiThrNode*)malloc(sizeof(BiThrNode));
				if(!q)exit(Overflow);
				q->data=ch;q->lchild=nullptr;q->rchild=nullptr;
q->LTag=Link;q->RTag=Link;  //这里仔细。。。！再看看为什么少这两语句会错 
				q->father=FatherTree[j/2];
				ChildTree[NewChildNum++]=q;
				if(j%2==0){//左树 
					FatherTree[j/2]->lchild=q;
				}
				else{
					FatherTree[j/2]->rchild=q;
				}
				j++;
			}
		}
		FatherNum=NewChildNum;
		free(FatherTree);
		FatherTree=ChildTree;
	}
}

BiThrTree SearchPost(BiThrTree p)
{
	if(p->lchild){
		return SearchPost(p->lchild);																																			SearchPost(p->lchild);
	}
	else if(p->rchild){
		return SearchPost(p->rchild);
	}
	else return p;
}

void PostThreading(BiThrTree p)
{
	if(p){
		if(p==p->father->lchild&&p->father->rchild){
			BiThrTree Post=SearchPost(p->father->rchild);
			p->RTag=Thread;p->rchild=Post;
			Post->LTag=Thread;Post->lchild=p;
		}
		else if(p==p->father->rchild||p==p->father->lchild&&!p->rchild){
			if(!p->lchild){
				p->LTag=Thread;p->lchild=p->father;
			}
			p->RTag=Thread;p->rchild=p->father;
		}
		
	} 
}

Status PostOrderThreading(BiThrTree T,BiThrTree &Thrt)
{
	if(!(Thrt=(BiThrNode*)malloc(sizeof(BiThrNode))))exit(Overflow);
	Thrt->LTag=Link;Thrt->RTag=Thread;Thrt->rchild=Thrt;
	if(!T)Thrt->lchild=Thrt;
	else{
		Thrt->lchild=T;
		pre=Thrt;
		PostThreading(T);
		pre->RTag=Thread;pre->rchild=Thrt;
		Thrt->rchild=pre;
	}
	return Ok;
}



int main ()
{
	BiThrTree T,Thrt;
	printf("层序创建二叉树，输入结点的值：\n");
	CreateBiThrTree(T);
	PostOrderThreading(T,Thrt);
//	PostOrderTraverse_Thr(Thrt);cout<<endl;
	return 0;
}
