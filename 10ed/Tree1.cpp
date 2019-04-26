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
	if(!T){//  ！！！吃亏了 总算是意识到了 非法访问 会带来的严重后果！
								//之一 就是，无论怎么调试程序都感觉没问题！
							//在利用指针访问结点的时候，一定要注意，在这个过程中
							//会不会产生非法访问！！（虽然本意不会，但在循环或者递归的
							//过程中会不经意出现！所以一定要在每次访问某个结点前先检查其是否为空（合法）！
										 
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
												//这里的叶子指的是
												//还未转换为孩子兄弟树（二叉树）时的叶子
												//即原来 树 的叶子！ 
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
		return h1+1>h2?h1+1:h2;//太巧妙了！保证大的永远是左子树！即 孩子！
								//保证了永远返回的是大的且是深度！ 
	}
}

int main ()
{
	CSTree T,T2;
//	a=&T;
	printf("前根建立树T，请输入结点的值：\n"); 
	CreatCSTree(T);
	printf("复制树T至T2，并销毁T\n");
	CopyCSTree(T,T2);
	DestroyTree(T); 
	printf("前根遍历树T2：\n");
	PreOrderCSTree(T2);
	cout<<endl;
	printf("后根遍历树T2：\n");
	PostOrderCSTree(T2);
	cout<<endl;
	printf("复制树T2至T，并清空T2\n");
	CopyCSTree(T2,T);
	ClearTree(T2);
	printf("复制成功！清空树T2成功！\n");
	printf("前根遍历树T：\n");
	PreOrderCSTree(T);
	cout<<endl;
	printf("前根遍历树T：\n");
	PostOrderCSTree(T);
	cout<<endl;
	printf("求树T的叶子个数：");
	CountTree(T);
	cout<<LeafCount<<endl;
	maxDepth=Depth(T);
	printf("求树T的深度："); 
	cout<<maxDepth<<endl;
	return 0;
}



// RAD#E##B#CFG#####
// RAD#EB#CFG#H#K#####]
// RAD#E##B#CFG#H#K#####




