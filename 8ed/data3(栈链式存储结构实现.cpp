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
	return Ok;
 }
