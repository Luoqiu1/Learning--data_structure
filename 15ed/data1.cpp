#include <iostream>
using namespace std;
#define Ok 1
#define Error 0
#define Overflow -2
#define True 1
#define False 0
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int KeyType;
typedef int Status;
typedef int TElemType;
typedef struct{
	KeyType key;//�ؼ����� 
}ElemType;
typedef struct BiTNode{
	TElemType data;
	struct BiTNode *rchild,*lchild; 
}BiTNode,*BiTree;
typedef BiTree SElemType;
typedef struct SqStack{
	SElemType *top,*base;
	int stacksize;
}SqStack;

Status StackEmpty(SqStack S)
{
	if(S.base==S.top)return Ok;
	return !Ok;
}

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

Status GetTop(SqStack S,SElemType &e)
{
	if(S.base==S.top)return Error;
	e=S.top[-1];
	return Ok;
}

Status SearchBST(BiTree T,KeyType key,BiTree f,BiTree &p)
{
	if(!T){
		p=f;return False;
	}
	else if(T->data==key){
		p=f;return Ok;
	}
	else if(key<T->data){
		return SearchBST(T->lchild,key,T,p);
	}
	else{
		return  SearchBST(T->rchild,key,T,p);
	}
}

Status PreOrderTraverse(BiTree T)
{
	SqStack(S);InitStack(S);
	while(T||!StackEmpty(S)){
		while(T){
			printf("%d",T->data);
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

Status InOrderTraverse(BiTree T)
{
	SqStack(S);InitStack(S);
	while(T||!StackEmpty(S)){
		while(T){
			Push(S,T);
			T=T->lchild;
		}
		if(!StackEmpty(S)){
			Pop(S,T);
			printf("%d",T->data);
			T=T->rchild;
		}
	}
	return Ok;
}

Status PostOrderTraverse(BiTree T)
{
	SqStack S;InitStack(S);
	Push(S,T);
	BiTree pre=nullptr; 
	while(!StackEmpty(S)){
		GetTop(S,T);
		if(!T->lchild&&!T->rchild||pre&&(pre==T->lchild||pre==T->rchild)){
			Pop(S,T);printf("%d",T->data);pre=T;
		}
		else{
			if(T->rchild)Push(S,T->rchild);
			if(T->lchild)Push(S,T->lchild);
		}
	}
	return Ok;
 }

Status InsertBST(BiTree &T,ElemType e)
{
	BiTree p;
	if(!SearchBST(T,e.key,nullptr,p)){
		BiTree s=(BiTNode*)malloc(sizeof(BiTNode));
		s->data=e.key;s->lchild=nullptr;s->rchild=nullptr;
		//ע��һ��ʼ���ʼ�ǿ��������������ʱp=nullptr!
		if(!p)T=s;
		else if(e.key<p->data)p->lchild=s;
		else p->rchild=s;
		return Ok;
	}
	return False;
}

Status DeleteBST(BiTree &T,KeyType key,BiTree &parent)
{
	if(!T)return False;
	if(key==T->data){
		if(T->lchild){//T��������
			if(T->lchild->rchild){//����������������
				BiTree p=T->lchild->rchild,q=T->lchild;
				while(p->rchild){p=p->rchild;q=p;}//�ҵ������½ǵ�������
				p->lchild=T->lchild;p->rchild=T->rchild;//��������������ָ�򽫱�ɾ����������������������ͬ�� 
				q->rchild=nullptr;
				T=p;//��ɾ��������ɾ����ͬʱ������pָ�����
				return Ok;
			}
			else{//����������������
				T->lchild->rchild=T->rchild;//����������������ָ��T����������
				T=T->lchild;//����
			}
		}
		else if(T->rchild){//T����������������
			if(!parent){//���Ǹ����
				T=T->rchild;
			}
			else{//�Ǹ����
				parent->rchild=T->rchild; 
			}
		}
		else{//����������Ҳ��������
			if(parent){//�и��� 
				if(parent->lchild->data==key){//�Ǹ����������� 
					parent->lchild=nullptr;
				}
				else if(parent->rchild->data==key){//�Ǹ����������� 
					parent->rchild=nullptr;
				}
			}
			else{
				T=nullptr;//������Ϊ���� 
			}
		}
	}
	else if(key<T->data){
		return DeleteBST(T->lchild,key,T);
	}
	else return DeleteBST(T->rchild,key,T);
}

int main ()
{
	BiTree T=nullptr,s=nullptr,d=nullptr;
	int n,i;
	ElemType e;
	printf("��������������Ľ������");
	scanf("%d",&n);
	printf("����%d������ֵ��\n",n);
	for(i=1;i<=n;++i){
		scanf("%d",&e.key);
		InsertBST(T,e);
	}
	printf("���������������������������\n");
	PreOrderTraverse(T);
	cout<<endl;
	printf("���������������������������\n");
	InOrderTraverse(T);
	cout<<endl;
	printf("��������������ĺ�����������\n");
	PostOrderTraverse(T);
	cout<<endl;
	printf("������ҽ���ֵ��\n");
	scanf("%d",&e.key);
	bool flag=SearchBST(T,e.key,nullptr,s);
	if(flag)printf("���ҵ������İ˽��Ƶ�ַΪ��%o\n",&s);
	else printf("δ�ҵ���\n");
	printf("����������ֵ��\n",n);
	scanf("%d",&e.key);
	InsertBST(T,e);
	printf("���������������������������\n");
	PreOrderTraverse(T);
	cout<<endl;
	printf("���������������������������\n");
	InOrderTraverse(T);
	cout<<endl;
	printf("��������������ĺ�����������\n");
	PostOrderTraverse(T);
	cout<<endl;
	printf("����ɾ������ֵ��\n");
	scanf("%d",&e.key);
	DeleteBST(T,e.key,d);
	printf("���������������������������\n");
	PreOrderTraverse(T);
	cout<<endl;
	printf("���������������������������\n");
	InOrderTraverse(T);
	cout<<endl;
	printf("��������������ĺ�����������\n");
	PostOrderTraverse(T);
	cout<<endl;
	return 0;
} 

