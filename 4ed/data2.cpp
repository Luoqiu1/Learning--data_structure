#include <bits/stdc++.h>
using namespace std;
#define True 1
#define False 0
#define Ok 1
#define Error 0
#define Overflow -2
#define STACK_INIT_SIZE 100 //存储空间初始分配量
#define STACKINCREMENT 10 //存储空间分配增量
typedef int Status;
typedef char SElemType;
typedef struct SqStack{
	SElemType *base; //在栈构造之前和销毁之后，base的值为NULL 
	SElemType *top; //栈顶指针
	int stacksize; //当前已分配的存储空间，以元素为单位 
}SqStack;

Status InitStack(SqStack &S) //构造一个空栈 
{
	S.base=(SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!S.base) exit(Overflow);
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	return Ok;
}

Status GetTop(SqStack &S,SElemType &e)
{
	if(S.base!=S.top) {
		e=S.top[-1];return Ok;
	}
	else return Error;
}

Status Push(SqStack &S,SElemType e) //可能会出现栈满的情况！要先判断是否需要追加栈空间！ 
{
	if(S.top-S.base>=S.stacksize){
		S.base=(SElemType*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!S.base) exit(Overflow);
		S.top=S.base+S.stacksize;
		S.stacksize+=STACKINCREMENT;
	}
	*S.top++=e;
	return Ok;
}

Status Pop(SqStack &S,SElemType &e)
{
	if(S.base!=S.top){
		e=*--S.top;return Ok;
	}
	else return Error;
}

Status lookfor(SqStack S,SElemType a,SElemType b)
{
	if(a=='(')if(b!=')')return False;else return True;
	if(a=='[')if(b!=']')return False;else return True;
}

Status kuohao(SqStack &S,SqStack &Y)
{
	int k=0;
	do{
		SElemType a;
		cin>>a;
		if(k){
			if(a=='('||a=='[') Push(S,a);
			if(a==')'||a==']') {
				SElemType mid;GetTop(S,mid);
				if(lookfor(S,mid,a)) Pop(S,mid);
				else {
					cout<<"括号匹配错误！\n";return False; 
				}
			//	else Push(Y,a);
			}
			else {
				k++;continue;
			}
			k++;
		}
		else{
			if(a!='('&&a!='['){
				cout<<"括号匹配错误！\n";return False; 
			}
			if(a=='('||a=='[') Push(S,a);
			else Push(Y,a);
			k++;
		}
	}while(S.base!=S.top);
	cout<<"括号匹配正确！\n";
	return True;
}

int main ()
{
	SqStack S,Y;
	InitStack(S);InitStack(Y);
	cout<<"输入需要进行括号匹配检测的表达式：\n";
	kuohao(S,Y);
	return 0;
 } 
