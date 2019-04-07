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
typedef int SElemType;
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

Status StackEmpty(SqStack &S)
{
	if (S.base==S.top) return True;
	else return False;
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

Status Stackoutput(SqStack S)
{
	if(S.base==S.top) return Error;
	while(--S.top!=S.base){
		cout<<*S.top<<' ';
	}
	cout<<*S.base;
	cout<<endl;
	return Ok;
}

Status StackTraverse(SqStack &S)
{
	if(S.base==S.top) return Error;
	int n=S.top-S.base;
	for(int i=0;i<n;i++) cout<<S.base[i]<<' ';  
	cout<<endl;
	return Ok;
}


int main ()
{
	int i,n,k,h,a,b;
	SqStack S;
	cout<<"创建一个空栈！"<<endl;
	InitStack(S);
	cout<<"判断栈是否为空！"<<endl;
	printf("StackEmpty(s)=%d\n",StackEmpty(S));
	cout<<"创建栈的元素个数：n"<<endl;
	cin>>n;
	printf("输入%d个入栈元素的值：\n",n);
	for(i=0;i<n;i++){
		cin>>k;
		Push(S,k);
	} 
	cout<<"逆序输出顺序栈元素值："<<endl;
	Stackoutput(S); 
	cout<<"输出顺序栈元素值："<<endl;
	StackTraverse(S);
	cout<<"输入入栈元素值："<<endl;
	cin>>h;Push(S,h);
	cout<<"输出入栈后的顺序栈元素值："<<endl;
	StackTraverse(S);
	Pop(S,a);
	cout<<"输出第1个出栈元素值："<<a<<endl;
	Pop(S,a);
	cout<<"输出第2个出栈元素值："<<a<<endl;
	cout<<"输出两次出栈后顺序栈元素值：";
	StackTraverse(S);
	GetTop(S,b);
	printf("输出栈顶元素值：%d\n",b);
	return 0; 
 } 
