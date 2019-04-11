#include <bits/stdc++.h>
using namespace std;
#define Ok 1
#define Error 0
#define Overflow -2
#define True 1
typedef int Status;
typedef char TElemType;
typedef struct LinkBitNode{
	TElemType data;
	LinkBitNode *rchild,*lchild;
}LinkBitNode,*LinkBiTree;

Status InitBiTree(LinkBiTree &T)
{
	char ch;
	scanf("%c",&ch);getchar();
	if(ch=='#'){
		return Error;
	}
	else{
		T=(LinkBitNode*)malloc(sizeof(LinkBitNode));
		T->data=ch;T->lchild=nullptr;T->rchild=nullptr;
		int ParentsTreeNum=1;
		LinkBitNode **ParentsTree=(LinkBitNode**)malloc(sizeof(LinkBitNode*)*ParentsTreeNum);
		ParentsTree[ParentsTreeNum-1]=T;//用来存储父亲结点指针 
		while(1){
			int childNum=ParentsTreeNum*2;
			LinkBitNode **childTree=(LinkBitNode**)malloc(sizeof(LinkBitNode*)*childNum); 
			int j;
			int NewParentsTree=0;
			for(j=0;j<childNum;j++){
				scanf("%c",&ch);getchar();
				if(j%2==0){//左树 
					if(ch=='#'){// j/2表示父亲结点指针的位置 
						ParentsTree[j/2]->lchild=nullptr;
					}
					else{
						ParentsTree[j/2]->lchild=childTree[j];
						childTree[j]->data=ch; 
					//	childTree[NewParentsTree-1]=childTree[j];
						NewParentsTree++;
					}
				}
				else{//右树 
					if(ch=='#'){
						ParentsTree[j/2]->rchild=nullptr;
					}
					else{
						ParentsTree[j/2]->rchild=childTree[j];
						childTree[j]->data=ch;
					//	childTree[NewParentsTree-1]=childTree[j];
						NewParentsTree++;
					}
				}
				free(ParentsTree);
				ParentsTree=childTree;
				ParentsTreeNum=NewParentsTree;
			}
		}
	}
	return Ok;
}



int main ()
{
	LinkBiTree T,S;
	InitBiTree(T);
	S=(LinkBitNode*)malloc(sizeof(LinkBitNode));S=T;
	while(S){
		cout<<S->lchild->data<<' ';
		S=S->lchild; 
	}
	return Ok;
 }
