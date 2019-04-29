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
//	while(p!=T||!StackEmpty(S)){ //p!=T��һ������ʹ�ڻ�û����T��������ǰ���������
								//��Ϊ push ������ڽ�������֮�󣬾��������������� '#' 
								//�ڽ���������ǰ ջ�ǿյ� �� p==T !
								//��˼��һ�£� 
								
//	while(p||!StackEmpty(S)){ //�����ֻ������ѭ��������p�㲻Ϊ0 
	//������һ����whileѭ����ʵ�ָ�����������ͬʱ�����������Ѷȣ�����˵�һ�û���ҵ�ʵ�ֵķ����� 
	//����ֱ𹹽������������������������ڶ��α�����������ʱ�������Ƿ����������� 
	//�ڶ��α����������������ǣ�   ջΪ�� ��
	 
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
	} //��һ���ǹ���������������
	//��һ������������������������ctrl+c v ���뼴�ɡ� 
	bool rightTree=true;
	if(StackEmpty(S)){ //�������ɴ����У� �Ը��ڵ��Ƿ�������������
								//�ڶ��η��ʸ��ڵ��ʱ��ջ�ǿյģ�
								//���ø�����������˵�һ�θս���������д���������� 
			if(scanf("%c",&ch)&&ch!='#'||ch==13){
				CSTree cur=(CSNode*)malloc(sizeof(CSNode));
				cur->data=ch;cur->firstchild=nullptr;cur->nextsibling=nullptr;
				Push(S,cur);
				T->nextsibling=cur;
				p=cur;
			}
			else rightTree=false;//����������������ơ� 
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


















