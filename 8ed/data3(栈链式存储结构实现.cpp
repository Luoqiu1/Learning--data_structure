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
		ParentsTree[ParentsTreeNum-1]=T;//�����洢���׽��ָ��,ParentsTree�Լ������childTree�൱��ָ������ 
		//�����˿ռ䣬�ɽ�����Ŀռ俴���ǡ����� ���Ŀռ䣬������Ŀռ���������Ž��ģ���㼰��Ŀռ仹��Ҫ���� 
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
					curchild->data=ch;//�� 
					curchild->lchild=nullptr;//�� 
					curchild->rchild=nullptr;//�� 
					NewParentsTree++;//�� 
					if(j%2==0){
						ParentsTree[j/2]->lchild=curchild;//�� 
					}
					else{
						ParentsTree[j/2]->rchild=curchild;//�� 
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

Status PrinfTop(SqStack S)
{
	printf("%c",(*S.top)->data);
	return Ok;
}

Status PreOrderTraverse(LinkBiTree T)
{
	SqStack S;InitStack(S);
	Push(S,T);
	while(!StackEmpty(S)){
		if(T)PrinfTop(S);
		cout<<"here";
		if(T->lchild){
			T=T->lchild;
			Push(S,T); 
			cout<<"here";
		}
		else{
			T=nullptr;
			Pop(S,T);
			T=T->rchild;
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
	return Ok;
 }
