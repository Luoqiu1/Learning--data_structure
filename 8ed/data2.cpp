#include <bits/stdc++.h>
using namespace std;
#define True 1
#define Error 1
#define Overflow -2
#define Ok 1
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int Status;
typedef char SElemType;
typedef struct {
	SElemType *top,*base;
	int stacksize;
}SqStack;



Status pop(SqStack &S,SElemType &e)
{
	if(S.base==S.top)exit(Overflow);
	e=*S.top;
	--S.top;
	return Ok;
}

Status StackEmpty(SqStack S)
{
	if(S.base==S.top)return Ok;
	return !Ok;
}

Status push(SqStack &S,SElemType e)
{
	if(S.base-S.top>=S.stacksize){
		S.base=(SElemType*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!S.base)exit(Overflow);
		S.top=S.base+S.stacksize;
	}
	*S.top=e;++S.top;
	return Ok;
}


Status InitStack(SqStack &S)
{
//	S.base=(SElemType*)malloc(sizeof(SElemType)*STACK_INIT_SIZE);
//	if(!S.base)exit(Overflow);
//	S.top=S.base;
//	S.stacksize=STACK_INIT_SIZE;
//	return Ok;

	char s[100];scanf("%s",s);
	int i=0;push(S,s[i]);
	char ch;
	while(!StackEmpty(S)){
		pop(S,ch);if(ch!='#')s[i]=ch;
		else {
			
		}
	}
	
}

int main ()
{
	SqStack S;
	InitStack(S);
	char ch;
	std::cin>>ch;
	push(S,ch);
//	while(S.base){
//		
//	}
}
