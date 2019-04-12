#include <bits/stdc++.h>
using namespace std;
#define Ok 1
#define Error 0
#define Overflow -2
#define True 1
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int Status;
typedef char TElemType;
typedef struct LinkBitNode{
	TElemType data;
	LinkBitNode *rchild,*lchild;
}LinkBitNode,*LinkBiTree;
typedef LinkBiTree SElemType;
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

Status InitBiTree(LinkBiTree &T)
{
	char ch;
	scanf("%c",&ch);
	if(ch=='#'){
		return Error;
	}
	else{
		T=(LinkBitNode*)malloc(sizeof(LinkBitNode));
		T->data=ch;T->lchild=nullptr;T->rchild=nullptr;
		int ParentsTreeNum=1;
		LinkBitNode **ParentsTree=(LinkBitNode**)malloc(sizeof(LinkBitNode*)*ParentsTreeNum);
		ParentsTree[ParentsTreeNum-1]=T;//用来存储父亲结点指针,ParentsTree以及下面的childTree相当于指针数组 
		//申请了空间，可将申请的空间看作是“数组 ”的空间，即申请的空间是用来存放结点的，结点及其的空间还需要另设 
		while(1){
			int childNum=ParentsTreeNum*2; 
			LinkBitNode **childTree=(LinkBitNode**)malloc(sizeof(LinkBitNode*)*childNum);
			int j;
			int NewParentsTree=0;
			for(j=0;j<childNum;j++){
				scanf("%c",&ch);
				if(ch!='#'){
					LinkBitNode *curchild=(LinkBitNode*)malloc(sizeof(LinkBitNode));
					childTree[NewParentsTree]=curchild;
					curchild->data=ch;//对 
					curchild->lchild=nullptr;//对 
					curchild->rchild=nullptr;//对 
					NewParentsTree++;//对 
					if(j%2==0){
						ParentsTree[j/2]->lchild=curchild;//对 
					}
					else{
						ParentsTree[j/2]->rchild=curchild;//对 
					}
				}
			}
			free(ParentsTree);
			ParentsTree=childTree;
			ParentsTreeNum=NewParentsTree;
			if(ParentsTreeNum==0)break;
		}
	}
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

Status PreOrderTraverse(LinkBiTree T)
{
	//该段代码为何出错再议 
//	
//	SqStack S;InitStack(S);													
//	Push(S,T);
//	while(!StackEmpty(S)){
//		if(T)//PrinfTop(S);
//		cout<<(*S.top)->data;
//	//	cout<<"here";
//		if(T->lchild){
//			T=T->lchild;
//			Push(S,T); 
//	//		cout<<"here";
//		}
//		else{
//			T=nullptr;
//			Pop(S,T);
//			T=T->rchild;
//		}
//	}
//	
	//
	
	/*
	SqStack S;InitStack(S);
	while(T||!StackEmpty(S)){
		while(T){
			cout<<T->data;
		//	PrinfTop(S);
		//	cout<<(*S.top)->data;
			Push(S,T);
			T=T->lchild;
		}
		if(!StackEmpty(S)){
			Pop(S,T);
			T=T->rchild;
		}
	}
	*/


	SqStack(S);InitStack(S);
	while(T||!StackEmpty(S)){
		while(T){
			printf("%c",T->data);
			Push(S,T);
			T=T->lchild;
		}
		if(!StackEmpty(S)){
			Pop(S,T);
			T=T->rchild;
		}
	}
	return Ok;

}

Status InOrderTraverse(LinkBiTree T)
{
	//我的做法，一次循环内嵌套循环遍历完左子树 
 
	SqStack(S);InitStack(S);
	while(T||!StackEmpty(S)){
		while(T){//一次直接找到左子树的最深处，最后是空指针退出，但不影响后续。
					//因为后续中弹出栈重新给T赋值，是空指针的时候没有用到！ 
			Push(S,T);
			T=T->lchild;
		}
		if(!StackEmpty(S)){
			Pop(S,T);
			printf("%c",T->data);
			T=T->rchild;
		}
	}
	
	// 
	//课本做法 
//	SqStack(S);InitStack(S);
//	while(T||!StackEmpty(S)){
//		if(T){
//			Push(S,T);
//			T=T->lchild;
//		}
//		else{
//			Pop(S,T);
//			printf("%c",T->data);
//			T=T->rchild;
//		}
//	} 
	return Ok;
}

Status PostOrderTraverse(LinkBiTree T)
{
	
//	
//	SqStack(S);InitStack(S);
//	while(T||!StackEmpty(S)){
//		while(T){
//			Push(S,T);
//			T=T->lchild;
//		}
//		GetTop(S,T);
//		while(T){
//			T=T->rchild;
//			if(T)Push(S,T);
//		}
//		if(!StackEmpty(S)){
//			Pop(S,T);
//			printf("%c",T->data);
//		}
//	} 
//	


	SqStack(S);InitStack(S);
	while(T||!StackEmpty(S)){
	//	cout<<"here";
		bool flag=true; 
		if(T){
			flag=!flag;
			Push(S,T);T=T->lchild;
		}
		GetTop(S,T);T=T->rchild;
		if(flag&&T){
			Push(S,T);T=T->rchild;
		}
		else{
	//		cout<<"here";
			Pop(S,T);printf("%c",T->data);GetTop(S,T);T=T->rchild;
		}
	}
	
 } 


int main ()
{
	LinkBiTree T; 
	InitBiTree(T);
//	int cnt=0;
//	while(T){
//		cnt++;
//		cout<<T->data;
//		T=T->lchild; 
//		cout<<cnt<<endl;
//	}
	PreOrderTraverse(T);
	cout<<endl;
	InOrderTraverse(T);
	cout<<endl;
	PostOrderTraverse(T); 
	return Ok;
 }
