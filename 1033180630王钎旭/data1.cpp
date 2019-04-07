#include <bits/stdc++.h>
using namespace std;
#define True 1
#define Error 0
#define Overflow -2
#define Ok 1
typedef int Status;
typedef int TElemType;
typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

Status CreateBiTree(BiTree &T)
{
	char ch;
	scanf("%c",&ch);
	if(ch=='#')T=NULL;
	else{
		if(!(T=(BiTree)malloc(sizeof(BiTNode))))exit(Overflow);
		T->data=ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return Ok;
 } 
 
Status PreOrderTraverse(BiTree T)
{
	if(T){
		printf("%c",T->data);
		if(PreOrderTraverse(T->lchild))
			if(PreOrderTraverse(T->rchild)) return Ok;
	}
	else return Ok;
}

Status InOrderTraverse(BiTree T)
{
	int m=0;
	if(T){
		if(InOrderTraverse(T->lchild))m=1;
		printf("%c",T->data);
		if(m)
			if(InOrderTraverse(T->rchild))return Ok;
		return Error;
	}
	else return Ok;
}

Status PostOrderTraverse(BiTree T)
{
	if(T){
		if(PostOrderTraverse(T->lchild))
			if(PostOrderTraverse(T->rchild)){
				printf("%c",T->data);return Ok;
			}
		return Error;
	}
	else return Ok;
}

int Depth(BiTree T)
{
	int leftDepth,rightDepth;
	if(T==NULL)return 0;
	else{
		leftDepth=Depth(T->lchild);
		rightDepth=Depth(T->rchild);
		if(leftDepth>=rightDepth)return leftDepth+1;
		else return rightDepth+1;
	}
}

Status NodeCount(BiTree T)
{
	if(T){
		Nodenum++;
		if(NodeCount(T->lchild))
			if(NodeCount(T->rchild))return Ok;
		return Error;
	}
	else return Ok;
}

int main ()
{
	BiTree T,B;
	printf("创建二叉树，按先序次序输入二叉树中结点的值：\n");
	CreateBiTree(T);
	NodeCount(T);
	printf("二叉树的结点个数为：%d\n",Nodenum);
	printf("二叉树的深度为：%d\n",Depth(T));
	printf("先序遍历二叉树，结果是：\n");
	PreOrderTraverse(T);
	cout<<endl;
	printf("中序遍历二叉树，结果是：\n");
	InOrderTraverse(T);
	cout<<endl;
	printf("后序遍历二叉树，结果是：\n");
	PostOrderTraverse(T);
	cout<<endl;
	printf("输出二叉树的叶子结点：\n");
	LeafCount(T);
	cout<<endl;
	printf("统计二叉树的叶子结点个数：%d\n",Count);
	printf("交换二叉树中所有结点的左右子树！\n");
	ExchangeBiTree(T);
	if(CopyBiTree(T,B)==Ok)printf("成功复制二叉树T到二叉树B！\n");
	if(DestroyTree(T)==Ok)printf("成功销毁二叉树T！\n");
	if(ClearTree(T)==Ok)printf("将二叉树T置为空树！\n");
	printf("先序遍历二叉树B，结果是：\n");
	PreOrderTraverse(B);
	cout<<endl;
	printf("中序遍历二叉树B，结果是：\n");
	InOrderTraverse(B);
	cout<<endl;
	printf("后序遍历二叉树B，结果是：\n");
	PostOrderTraverse(B);
	cout<<endl;
	return 0;
}
