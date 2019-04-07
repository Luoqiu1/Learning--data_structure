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
typedef char SElemType;
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
					cout<<"����ƥ�����\n";return False; 
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
				cout<<"����ƥ�����\n";return False; 
			}
			if(a=='('||a=='[') Push(S,a);
			else Push(Y,a);
			k++;
		}
	}while(S.base!=S.top);
	cout<<"����ƥ����ȷ��\n";
	return True;
}

int main ()
{
	SqStack S,Y;
	InitStack(S);InitStack(Y);
	cout<<"������Ҫ��������ƥ����ı��ʽ��\n";
	kuohao(S,Y);
	return 0;
 } 
