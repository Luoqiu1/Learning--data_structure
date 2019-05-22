#include <iostream>
using namespace std;
#define Ok 1
#define Error 0
#define Overflow -2
#define True 1
#define False 0
typedef int KeyType;
typedef int ElemType;
typedef int Status;
typedef char TElemType;
typedef struct BiTNode{
	TElemType data;
	struct BiTNode *rchild,*lchild; 
}BiTNode,*BiTree;

Status SearchBST(BiTree T,KeyType key,BiTree f,BiTree &p)
{
	if(!T){
		p=f;return False;
	}
	else if(T->data==key){
		p=f;return Ok;
	}
	else if(key<T->data){
	//	if(SearchBST(T->lchild,key,T,p))return Ok;else return False;
		return SearchBST(T->lchild,key,T,p);//形式简洁些 
	}
	else{
	//	if(SearchBST(T->rchild,key,T,p))return Ok;else return False;
		return  SearchBST(T->rchild,key,T,p);
	}
}

Status InsertBST(BiTree &T,ElemType e)
{
	BiTree p;
	if(!SearchBST(T,e,nullptr,p)){
		BiTree s=(BiTNode*)malloc(sizeof(BiTNode));
		s->data=e;s->lchild=nullptr;s->rchild=nullptr;
		//注意一开始！最开始是空树的情况。。此时p=nullptr!
		if(!p)T=s;
		else if(e<p->data)p->lchild=s;//
		else p->rchild=s;
		return Ok;
	}
	return False;
}

int main ()
{
	
} 
