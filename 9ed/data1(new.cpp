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
typedef enum PointerTag{Link,Thread//Link==0��ָ�룬Thread==1������ 
}PointerTag;//����typedef�Ļ�ֱ�� enum PointerTag{Link,Thread};  
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
				q->data=ch;q->lchild=nullptr;q->rchild=nullptr;//q->LTag=Thread;q->RTag=Thread;
				ChildTree[NewChildNum++]=q;
				if(j%2==0){//���� 
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

typedef BiThrTree SElemType;
typedef struct SqStack{
	SElemType *top,*base;
	int stacksize;
}SqStack;
Status InitStack(SqStack &S)
{
	S.base=(SElemType*)malloc(sizeof(SElemType)*STACK_INIT_SIZE);
	if(!S.base)exit(Overflow);
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	return Ok;
}
Status Pop(SqStack &S,SElemType &e)
{
	if(S.base==S.top)return Error;
	S.top--;
	e=*S.top;
	return Ok;
}
Status Push(SqStack &S,SElemType e)
{
	if(S.top-S.base>=S.stacksize){
		S.base=(SElemType*)realloc(S.base,sizeof(SElemType)*(S.stacksize+STACKINCREMENT));
		if(!S.base)exit(Overflow);
		S.top=S.base+S.stacksize;
		S.stacksize+=STACKINCREMENT;
	}
	*S.top=e;
	S.top++;
	return Ok;
}
Status StackEmpty(SqStack S)
{
	if(S.base==S.top)return Ok;
	return !Ok;
}

Status GetTop(SqStack S,SElemType &e)
{
	if(S.base==S.top)return Error;
	e=S.top[-1];
	return Ok;
}

Status InOrderThreading(BiThrTree T,BiThrTree &Thrt)
{
	SqStack S;InitStack(S);
	BiThrTree pre;
	Thrt=(BiThrNode*)malloc(sizeof(BiThrNode));if(!Thrt)exit(Overflow);
	Thrt->LTag=Link;Thrt->RTag=Thread; 
	Thrt->rchild=Thrt;
	if(!T)Thrt->lchild=Thrt;
	else{
		Thrt->lchild=T;pre=Thrt;
		while(T||!StackEmpty(S)){
			while(T){
				Push(S,T);T=T->lchild;
			}
			if(!StackEmpty(S)){
				Pop(S,T);if(!T->lchild){//����ǰ�������������˵�������������������һ��㡣
										//��ô��ʱ���� ǰ����� ��ȷ���� 
					T->LTag=Thread;T->lchild=pre;
				}
				if(!pre->rchild){//���ϴμ�¼�Ľ��û���������ˣ�˵���Ѿ�������ʹ��ý���ˡ� 
								//��ô��ʱ�ϴμ�¼�Ľ��� ��̽�� ��ȷ���� 
					pre->RTag=Thread;pre->rchild=T; 
				}
				pre=T;
			}
		}
	}
}

int main()
{
	BiThrTree T,Thrt;
	printf("���򴴽����������������ֵ��\n");
	CreateBiThrTree(T);
	InOrderThreading(T,Thrt);
	return 0;
}
