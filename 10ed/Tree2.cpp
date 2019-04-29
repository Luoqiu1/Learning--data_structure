#include <bits/stdc++.h>
using namespace std;
#define Ok 1
#define Error 0
#define Overflow -2
#define True 1
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int Status;
typedef char ElemType;
typedef struct CSNode{
	ElemType data;
	struct CSNode *firstchild,*nextsibling;
}CSNode,*CSTree;
typedef CSTree SElemType;
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

Status CreatCSTree(CSTree &T)
{
	SqStack S;InitStack(S);
	char ch;scanf("%c",&ch);
	if(ch=='#')return Error;
	else{
		T=(CSNode*)malloc(sizeof(CSNode));if(!T)exit(Overflow);
		T->data=ch;T->firstchild=nullptr;T->nextsibling=nullptr;
		Push(S,T);
	}
	CSTree p=T;
//	while(p!=T||!StackEmpty(S)){ //p!=T这一条件会使在还没建立T的右子树前便结束。。
								//因为 push 结点是在进入条件之后，就算右子树不等于 '#' 
								//在进入右子树前 栈是空的 且 p==T !
								//再思考一下！ 
								
//	while(p||!StackEmpty(S)){ //这样又会造成死循环。。！p恒不为0 
	//故想在一个大while循环中实现根结点的左右树同时构建，稍有难度（或者说我还没有找到实现的方法） 
	//不如分别构建根结点的左子树和右子树。第二次遍历到根结点的时候特判是否有左子树！ 
	//第二次遍历到根结点的特征是：   栈为空 ！
	 
	while(!StackEmpty(S)){
		while(scanf("%c",&ch)&&ch!='#'){
			CSTree cur=(CSNode*)malloc(sizeof(CSNode));
			cur->data=ch;cur->firstchild=nullptr;cur->nextsibling=nullptr;
			Push(S,cur);
			if(!p->firstchild)p->firstchild=cur;
			else if(!p->nextsibling)p->nextsibling=cur;
			p=cur;
		}
		if(!StackEmpty(S)){
			Pop(S,p);
			if(scanf("%c",&ch)&&ch!='#'){
				CSTree cur=(CSNode*)malloc(sizeof(CSNode));
				cur->data=ch;cur->firstchild=nullptr;cur->nextsibling=nullptr;
				Push(S,cur);
				p->nextsibling=cur;
				p=cur;
			}
			else if(!StackEmpty(S))Pop(S,p);
		}
	} //上一段是构建根结点的左子树
	//下一段先特判有无右子树，有再ctrl+c v 代码即可。 
	bool rightTree=true;
	if(StackEmpty(S)){ //！！！干脆特判！ 对根节点是否有右子树特判
								//第二次访问根节点的时候，栈是空的！
								//设置该条件便避免了第一次刚进入根结点进行创建的情况！ 
			if(scanf("%c",&ch)&&ch!='#'||ch==13){
				CSTree cur=(CSNode*)malloc(sizeof(CSNode));
				cur->data=ch;cur->firstchild=nullptr;cur->nextsibling=nullptr;
				Push(S,cur);
				T->nextsibling=cur;
				p=cur;
			}
			else rightTree=false;//如果无右子树，打破。 
	}
	while(rightTree&&!StackEmpty(S)){
		while(scanf("%c",&ch)&&ch!='#'){
			CSTree cur=(CSNode*)malloc(sizeof(CSNode));
			cur->data=ch;cur->firstchild=nullptr;cur->nextsibling=nullptr;
			Push(S,cur);
			if(!p->firstchild)p->firstchild=cur;
			else if(!p->nextsibling)p->nextsibling=cur;
			p=cur;
		}
		if(!StackEmpty(S)){
			Pop(S,p);
			if(scanf("%c",&ch)&&ch!='#'){
				CSTree cur=(CSNode*)malloc(sizeof(CSNode));
				cur->data=ch;cur->firstchild=nullptr;cur->nextsibling=nullptr;
				Push(S,cur);
				p->nextsibling=cur;
				p=cur;
			}
			else if(!StackEmpty(S))Pop(S,p);
		}
	}
}

Status PreOrderCSTree(CSTree T)
{
	SqStack S;InitStack(S);
	while(T||!StackEmpty(S)){
		while(T){
			cout<<T->data;Push(S,T);
			T=T->firstchild;
		}
		if(!StackEmpty(S)){
			Pop(S,T);
			T=T->nextsibling;
		}
	}
	return Ok;
 }
 
Status PostOrderCSTree(CSTree T)
{
	SqStack S;InitStack(S);
	while(T||!StackEmpty(S)){
		while(T){
			Push(S,T);T=T->firstchild;
		}
		if(!StackEmpty(S)){
			Pop(S,T);cout<<T->data;
			T=T->nextsibling;
		}
	}
	return Ok;
}

int main()
{
	CSTree T;
	CreatCSTree(T);
	PreOrderCSTree(T);cout<<endl;
	PostOrderCSTree(T);cout<<endl;
	return 0;
}


















