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
	CSNode *firstchild,*nextsibling;
}CSNode,*CSTree;
//CSTree *a;
Status CreatCSTree(CSTree &T)
{
	char ch;scanf("%c",&ch);
	if(ch=='#')return Error;//kk
	else{
		T=(CSTree)malloc(sizeof(CSNode));if(!T)exit(Overflow);
		T->data=ch;
		T->firstchild=nullptr;//kk
		T->nextsibling=nullptr;//kk
		CreatCSTree(T->firstchild);
		CreatCSTree(T->nextsibling);
	}
	return Ok;
}

Status CopyCSTree(CSTree T,CSTree &T2)
{
//	cout<<a<<' ';
	if(!T){//  �������Կ��� ��������ʶ���� �Ƿ����� ����������غ����
								//֮һ ���ǣ�������ô���Գ��򶼸о�û���⣡
							//������ָ����ʽ���ʱ��һ��Ҫע�⣬�����������
							//�᲻������Ƿ����ʣ�������Ȼ���ⲻ�ᣬ����ѭ�����ߵݹ��
							//�����л᲻������֣�����һ��Ҫ��ÿ�η���ĳ�����ǰ�ȼ�����Ƿ�Ϊ�գ��Ϸ�����
										 
	//	T2->firstchild=nullptr;
	//	T2->nextsibling=nullptr;
		return Error;//kk
	}
	else{
		T2=(CSTree)malloc(sizeof(CSNode));if(!T2)exit(Overflow);
		T2->data=T->data;
		T2->firstchild=nullptr;//kk
		T2->nextsibling=nullptr;//kk
		CopyCSTree(T->firstchild,T2->firstchild);
		CopyCSTree(T->nextsibling,T2->nextsibling);
	}
	return Ok;
}

Status DestroyTree(CSTree &T)
{
	if(!T)return Ok;
	DestroyTree(T->firstchild);
	DestroyTree(T->nextsibling);
	free(T);
	return Ok;
}

Status ClearTree(CSTree &T)
{
	if(!T)return Ok;
	DestroyTree(T->firstchild);
	DestroyTree(T->nextsibling);
	T=nullptr;
	return Ok;
}

void PreOrderCSTree(CSTree T)
{
//	cout<<"here";
	if(T){
		cout<<T->data;
		PreOrderCSTree(T->firstchild);
		PreOrderCSTree(T->nextsibling);
	}
}

void PostOrderCSTree(CSTree T)
{
	if(T){
		PostOrderCSTree(T->firstchild);
		cout<<T->data;
		PostOrderCSTree(T->nextsibling);
	}
 } 

int main ()
{
	CSTree T,T2;
//	a=&T;
	CreatCSTree(T);
	CopyCSTree(T,T2);
	DestroyTree(T); 
	PreOrderCSTree(T2);
	cout<<endl;
	PostOrderCSTree(T2);
	cout<<endl;
	CopyCSTree(T2,T);
	PreOrderCSTree(T);
	cout<<endl;
	PostOrderCSTree(T);
	cout<<endl;
	return 0;
}



// RAD#E##B#CFG#####




