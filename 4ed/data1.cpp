#include <bits/stdc++.h>
using namespace std;
#define True 1
#define False 0
#define Ok 1
#define Error 0
#define Overflow -2
#define STACK_INIT_SIZE 100 //�洢�ռ��ʼ������
#define STACKINCREMENT 10 //�洢�ռ��������
typedef int Status;
typedef int SElemType;
typedef struct SqStack{
	SElemType *base; //��ջ����֮ǰ������֮��base��ֵΪNULL 
	SElemType *top; //ջ��ָ��
	int stacksize; //��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ 
}SqStack;

Status InitStack(SqStack &S) //����һ����ջ 
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

Status Push(SqStack &S,SElemType e) //���ܻ����ջ���������Ҫ���ж��Ƿ���Ҫ׷��ջ�ռ䣡 
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
	cout<<"����һ����ջ��"<<endl;
	InitStack(S);
	cout<<"�ж�ջ�Ƿ�Ϊ�գ�"<<endl;
	printf("StackEmpty(s)=%d\n",StackEmpty(S));
	cout<<"����ջ��Ԫ�ظ�����n"<<endl;
	cin>>n;
	printf("����%d����ջԪ�ص�ֵ��\n",n);
	for(i=0;i<n;i++){
		cin>>k;
		Push(S,k);
	} 
	cout<<"�������˳��ջԪ��ֵ��"<<endl;
	Stackoutput(S); 
	cout<<"���˳��ջԪ��ֵ��"<<endl;
	StackTraverse(S);
	cout<<"������ջԪ��ֵ��"<<endl;
	cin>>h;Push(S,h);
	cout<<"�����ջ���˳��ջԪ��ֵ��"<<endl;
	StackTraverse(S);
	Pop(S,a);
	cout<<"�����1����ջԪ��ֵ��"<<a<<endl;
	Pop(S,a);
	cout<<"�����2����ջԪ��ֵ��"<<a<<endl;
	cout<<"������γ�ջ��˳��ջԪ��ֵ��";
	StackTraverse(S);
	GetTop(S,b);
	printf("���ջ��Ԫ��ֵ��%d\n",b);
	return 0; 
 } 
