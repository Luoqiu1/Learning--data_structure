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
		ParentsTree[ParentsTreeNum-1]=T;//用来存储父亲结点指针,ParentsTree以及下面的childTree相当于指针数组 
		//虽然申请了空间，但申请的空间是“数组”的空间，即申请的空间是用来存放结点的，结点及其的空间还需要另设 
		while(1){
			int childNum=ParentsTreeNum*2;
			LinkBitNode **childTree=(LinkBitNode**)malloc(sizeof(LinkBitNode*)*childNum); 
			int j;
			int NewParentsTree=0;
			for(j=0;j<childNum;j++){
				scanf("%c",&ch);getchar();
				if(j%2==0){//左树 
				//	if(ch=='#'){// j/2表示父亲结点指针的位置 
				//		ParentsTree[j/2]->lchild=nullptr;
				//	}
				//	else{
						LinkBitNode *curchild=(LinkBitNode*)malloc(sizeof(LinkBitNode)); 
						ParentsTree[j/2]->lchild=curchild;
						curchild->data=ch;
						curchild->lchild=nullptr;
						curchild->rchild=nullptr; 
					//	ParentsTree[j/2]->lchild=childTree[j];
					//	childTree[j]->data=ch; 
						NewParentsTree++;
				//	}
				}
				else{//右树 
				//	if(ch=='#'){
				//		ParentsTree[j/2]->rchild=nullptr;
				//	}
				//	else{
						LinkBitNode *curchild=(LinkBitNode*)malloc(sizeof(LinkBitNode));
						ParentsTree[j/2]->rchild=curchild;
						curchild->data=ch;
						curchild->lchild=nullptr;
						curchild->rchild=nullptr;
					//	ParentsTree[j/2]->rchild=childTree[j];
					//	childTree[j]->data=ch;
						NewParentsTree++;
				//	}
				}
				free(ParentsTree);
				ParentsTree=childTree;
				ParentsTreeNum=NewParentsTree;
				if(ParentsTreeNum==0)break;
			}
		}
	}
	return Ok;
}

#include <stdio.h>
#include <malloc.h>

// 布尔类型
typedef enum {FALSE=0,TRUE=1} aa;
// 用于标识当前建立左子树还是右子树
typedef enum {LEFT=0,RIGHT=1} flag;
// 节点存放数据的类型
typedef char data_type;
// 二叉树节点类型
typedef struct node {
  data_type data;
  struct node *left_subtree,
  *right_subtree;
} node , *bin_tree;

int create_bin_tree(bin_tree *root)
{
  /* 创建根节点 */
  data_type data = '\0';
  scanf("%c",&data);
  if(data == '#'){
    return FALSE; // 根节点为空，创建失败
  }
  else
  {
    *root = (node*)malloc(sizeof(node));
    (*root)->data = data;
    (*root)->left_subtree = NULL;
    (*root)->right_subtree = NULL;
  }
  
  /* 创建非根节点 */
  // 存放父层的节点列表
  node **parent_list = (node**)malloc(sizeof(node*));
  parent_list[0] = *root;
  // 父节点个数
  int parent_amount = 1;  
  
  while(1)
  {
    // 当前节点个数，设置为父节点个数的两倍
    int current_amount = parent_amount * 2;
    // 创建临时列表存放当前深度的节点
    node **tmp_list = (node**)malloc(sizeof(node*)
    * current_amount);
    // 用于记录当前深度节点非空节点个数
    int count = 0;
    // 创建当前层次的所有节点
    int j = 0;
    for(;j < current_amount;++j)
    {
      data = '\0';
      scanf("%c",&data);
      if(data != '#')  // 不为空节点
      {
        // 新建节点并赋值
        node *current_node = (node*)malloc(sizeof(node));
        current_node->data = data;
        current_node->left_subtree = NULL;
        current_node->right_subtree = NULL;
        // 加入到临时列表中
        tmp_list[count] = current_node;
        // 非空节点数加1
        count++;
        // 与父节点建立关系
        if(j%2 == LEFT)
        {
          (parent_list[j/2])->left_subtree = current_node;
        }
        else
        {
          (parent_list[j/2])->right_subtree = current_node;
        }
      }
    }  // for循环结束
    
    // 释放父层列表
    free(parent_list);
    // 更新父层列表
    parent_list = tmp_list;
    // 更新父节点数
    parent_amount = count;
    // 若非空节点数为0，则停止创建
    if(count == 0) break;
  }
  return TRUE;
}

int main ()
{
	bin_tree T,S;
//	LinkBiTree T,S;
	create_bin_tree(&T); 
//	InitBiTree(T);
//	S=(LinkBitNode*)malloc(sizeof(LinkBitNode));S=T;
	while(T){
		cout<<T->left_subtree->data<<' ';
		T=T->left_subtree; 
	}
	return Ok;
 }
