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
int LeafCount;
int curDepth,maxDepth;
CSTree pre;
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

void CountTree(CSTree T)
{
//	cout<<"here";
	if(T){
	//	if(!T->firstchild&&!T->nextsibling)LeafCount++;
												//�����Ҷ��ָ����
												//��δת��Ϊ�����ֵ�������������ʱ��Ҷ��
												//��ԭ�� �� ��Ҷ�ӣ� 
		if(!T->firstchild)LeafCount++;
		CountTree(T->firstchild);
		CountTree(T->nextsibling);
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

void PreOrderCSTree(CSTree T)
{
	if(T){
		cout<<T->data;
		PreOrderCSTree(T->firstchild);
		PreOrderCSTree(T->nextsibling);
	}
}

int Depth(CSTree T)
{
//	if(!T)pre=T;
//	if(T){
//		if(pre&&pre==T->firstchild)curDepth++;	
//		pre=T;
//		Depth(T->firstchild);
//		pre=T;
//		Depth(T->nextsibling);
//		pre=T;
//		if(!T->firstchild&&!T->nextsibling){
//			if(curDepth>maxDepth)maxDepth=curDepth;
//			curDepth--;
//		}
//	}
	int h1,h2;
	if(!T)return 0;
	else{
		h1=Depth(T->firstchild);
		h2=Depth(T->nextsibling);
		return h1+1>h2?h1+1:h2;//̫�����ˣ���֤�����Զ������������ ���ӣ�
								//��֤����Զ���ص��Ǵ��������ȣ� 
	}
}

int main ()
{
	CSTree T,T2;
//	a=&T;
	printf("ǰ��������T�����������ֵ��\n"); 
	CreatCSTree(T);
	printf("������T��T2��������T\n");
	CopyCSTree(T,T2);
	DestroyTree(T); 
	printf("ǰ��������T2��\n");
	PreOrderCSTree(T2);
	cout<<endl;
	printf("���������T2��\n");
	PostOrderCSTree(T2);
	cout<<endl;
	printf("������T2��T�������T2\n");
	CopyCSTree(T2,T);
	ClearTree(T2);
	printf("���Ƴɹ��������T2�ɹ���\n");
	printf("ǰ��������T��\n");
	PreOrderCSTree(T);
	cout<<endl;
	printf("ǰ��������T��\n");
	PostOrderCSTree(T);
	cout<<endl;
	printf("����T��Ҷ�Ӹ�����");
	CountTree(T);
	cout<<LeafCount<<endl;
	maxDepth=Depth(T);
	printf("����T����ȣ�"); 
	cout<<maxDepth<<endl;
	return 0;
}



// RAD#E##B#CFG#####
// RAD#EB#CFG#H#K#####]
// RAD#E##B#CFG#H#K#####




