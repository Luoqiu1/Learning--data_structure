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
	struct BiThrNode *lchild,*rchild;
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
		cout<<p->data;//中序输出结点 
		while(p->RTag==Thread&&p->rchild!=T){//线索访问后继 
		p=p->rchild;cout<<p->data;//直接输出后继 
		}
		p=p->rchild;//1、有右子树，进入，并进入寻找下一次中序输出的第一个结点。 
					//2、p->rchild==T，进入，结束循环 
	}
	return Ok;
}

void PreThreading(BiThrTree p)
{
	if(p){
		if(!p->lchild){//左子树空，前驱结点确定 
			p->lchild=pre;p->LTag=Thread;
		}
		if(!pre->rchild){//上一个访问的结点右子树空，后继结点确定为当前结点 
			pre->rchild=p;pre->RTag=Thread;
		}
		pre=p;//更新 
		if(p->LTag==Link)PreThreading(p->lchild);//其实可以说，在某种意义上
		if(p->RTag==Link)PreThreading(p->rchild);//p->L/R Tag==0(Link)表示其 左/右 子树非空，
												 //Tag==1(Thread)则 子树空。利用空域去指向前驱或后继元素！ 
	}
}

Status PreOrderThreading(BiThrTree T,BiThrTree &Thrt)
{
	Thrt=(BiThrNode*)malloc(sizeof(BiThrNode));if(!Thrt)exit(Overflow);
	Thrt->LTag=Link;Thrt->RTag=Thread;Thrt->rchild=Thrt;
	if(!T)Thrt->lchild=Thrt;
	else{
		Thrt->lchild=T;
		pre=Thrt;
		PreThreading(T);
		pre->rchild=Thrt;pre->RTag=Thread;
		Thrt->rchild=pre;
	}
	return Ok;
}

Status PreOrderTraverse_Thr(BiThrTree T)
{
	BiThrTree p=T->lchild;
	while(p!=T){
		cout<<p->data;
		while(p->LTag==Link){//找到最左下角 
		p=p->lchild;cout<<p->data;//先序 每次直接访问 
		}//循环结束表示左子树空了，要访问下一个 
//		while(p->RTag==Thread&&p->rchild!=T){
//			p=p->rchild;cout<<p->data;
//		}
//		cout<<p->data; 
		p=p->rchild;//不论是后继结点还是右子树均在p->rchild中。进去直接输出（先序，右子树直接输出） 
	}
}

void PostThreading(BiThrTree p)
{
	if(p){
		if(p->LTag==Link)PostThreading(p->lchild);
		if(p->RTag==Link)PostThreading(p->rchild);
		if(!p->lchild){
			p->LTag=Thread;p->lchild=pre;
		}
		if(!pre->rchild){
			pre->RTag=Thread;pre->rchild=p;
		}
		pre=p;
	}
 } 

Status PostOrderThreading(BiThrTree T,BiThrTree Thrt)
{
	Thrt=(BiThrNode*)malloc(sizeof(BiThrNode));if(!Thrt)exit(Overflow);
	Thrt->LTag=Link;Thrt->RTag=Thread;Thrt->rchild=Thrt;
	if(!T)Thrt->lchild=Thrt;
	else{
		Thrt->lchild=T;
		pre=Thrt;
		PostThreading(T);
		pre->rchild=Thrt;pre->RTag=Thread;
		Thrt->rchild=pre;
	}
	return Ok;
}

Status PostOrderTraverse_Thr(BiThrTree T)
{
	BiThrTree p=T->lchild;
	while(p!=T){
		while(p->LTag==Link){
			p=p->lchild;
		}
		while(p->RTag==Link){
			p=p->rchild;
		}
		if(p->LTag==Thread&&p->RTag==Thread){
			cout<<p->data;p=p->rchild;
		}
		else{
		//	if(p->LTag==Link)p=p->lchild;
		}
	}
}

int main ()
{
	BiThrTree T,ThrtIn,ThrtPre,ThrtPost;
	printf("层序创建二叉树，输入结点的值：\n");
	CreateBiThrTree(T);
//	printf("中序线索化二叉树，并输出二叉树：");
//	InOrderThreading(T,ThrtIn);
//	InOrderTraverse_Thr(ThrtIn);cout<<endl;
//	printf("前序线索化二叉树，并输出二叉树：");
//	PreOrderThreading(T,ThrtPre);
//	PreOrderTraverse_Thr(ThrtPre);cout<<endl;
	printf("后序线索化二叉树，并输出二叉树：");
	PostOrderThreading(T,ThrtPost);
	PostOrderTraverse_Thr(ThrtPost);cout<<endl;
	cout<<"here";
	return 0; 
}
