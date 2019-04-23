#include <iostream>
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



void InThreading(BiThrTree p)
{//中序线索化 
	if(p){
		InThreading(p->lchild);
		if(!p->lchild){
			p->LTag=Thread;p->lchild=pre;
		}
		if(!pre->rchild){
			pre->RTag=Thread;pre->rchild=p;
		}
		pre=p;
		InThreading(p->rchild);
	}
}

Status InOrderThreading(BiThrTree T,BiThrTree &Thrt)
{
	Thrt=(BiThrNode*)malloc(sizeof(BiThrNode));if(!Thrt)exit(Overflow);
	Thrt->LTag=Link;  //头结点“左子树”（应该）非空 
	Thrt->RTag=Thread;//头结点“右子树”暂空 
	Thrt->rchild=Thrt;//回指自身，以防止在线索化时出现指向首结点（首结点是第一个有意义的结点，不是头结点） 
	if(!T)Thrt->lchild=Thrt;
	else{
		Thrt->lchild=T;
		pre=Thrt;
		InThreading(T);
		pre->rchild=Thrt;pre->RTag=Thread;//最后一个结点指向头结点 
		Thrt->rchild=pre;
	}
}

Status InOrderTraverse_Thr(BiThrTree T)
{//中序遍历 
	BiThrTree p=T->lchild;
	while(p!=T){
		while(p->LTag==Link){//访问到最左下子树 
			p=p->lchild;
		}
		cout<<p->data;cout<<p->father->data<<' ';//中序输出结点 
		while(p->RTag==Thread&&p->rchild!=T){//线索访问后继 
		p=p->rchild;cout<<p->data;//直接输出后继
		if(p->father)cout<<p->father->data<<' ';
		else cout<<"  ";
		}
		p=p->rchild;//1、有右子树，进入，并进入寻找下一次中序输出的第一个结点。 
					//2、p->rchild==T，进入，结束循环 
	}
	return Ok;
}




int main ()
{
	BiThrTree T,Thrt;
	printf("层序创建二叉树，输入结点的值：\n");
	CreateBiThrTree(T);
	printf("中序线索化二叉树，并输出二叉树：");
	InOrderThreading(T,Thrt);
	InOrderTraverse_Thr(Thrt);cout<<endl;
	return 0;
}
