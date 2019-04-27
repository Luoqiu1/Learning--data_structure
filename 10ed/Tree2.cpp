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
	while(p||!StackEmpty(S)){
		while(scanf("%c",&ch)&&ch!='#'){
			CSTree cur=(CSNode*)malloc(sizeof(CSNode));
			cur->data=ch;cur->firstchild=nullptr;cur->nextsibling=nullptr;
			Push(S,cur);
			p->firstchild=cur;
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


int main()
{
	CSTree T;
	CreatCSTree(T);
	return 0;
}


















