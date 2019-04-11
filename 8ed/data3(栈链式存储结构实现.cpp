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
		ParentsTree[ParentsTreeNum-1]=T;//�����洢���׽��ָ��,ParentsTree�Լ������childTree�൱��ָ������ 
		//��Ȼ�����˿ռ䣬������Ŀռ��ǡ����顱�Ŀռ䣬������Ŀռ���������Ž��ģ���㼰��Ŀռ仹��Ҫ���� 
		while(1){
			int childNum=ParentsTreeNum*2;
			LinkBitNode **childTree=(LinkBitNode**)malloc(sizeof(LinkBitNode*)*childNum); 
			int j;
			int NewParentsTree=0;
			for(j=0;j<childNum;j++){
				scanf("%c",&ch);getchar();
				if(j%2==0){//���� 
				//	if(ch=='#'){// j/2��ʾ���׽��ָ���λ�� 
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
				else{//���� 
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

// ��������
typedef enum {FALSE=0,TRUE=1} aa;
// ���ڱ�ʶ��ǰ��������������������
typedef enum {LEFT=0,RIGHT=1} flag;
// �ڵ������ݵ�����
typedef char data_type;
// �������ڵ�����
typedef struct node {
  data_type data;
  struct node *left_subtree,
  *right_subtree;
} node , *bin_tree;

int create_bin_tree(bin_tree *root)
{
  /* �������ڵ� */
  data_type data = '\0';
  scanf("%c",&data);
  if(data == '#'){
    return FALSE; // ���ڵ�Ϊ�գ�����ʧ��
  }
  else
  {
    *root = (node*)malloc(sizeof(node));
    (*root)->data = data;
    (*root)->left_subtree = NULL;
    (*root)->right_subtree = NULL;
  }
  
  /* �����Ǹ��ڵ� */
  // ��Ÿ���Ľڵ��б�
  node **parent_list = (node**)malloc(sizeof(node*));
  parent_list[0] = *root;
  // ���ڵ����
  int parent_amount = 1;  
  
  while(1)
  {
    // ��ǰ�ڵ����������Ϊ���ڵ����������
    int current_amount = parent_amount * 2;
    // ������ʱ�б��ŵ�ǰ��ȵĽڵ�
    node **tmp_list = (node**)malloc(sizeof(node*)
    * current_amount);
    // ���ڼ�¼��ǰ��Ƚڵ�ǿսڵ����
    int count = 0;
    // ������ǰ��ε����нڵ�
    int j = 0;
    for(;j < current_amount;++j)
    {
      data = '\0';
      scanf("%c",&data);
      if(data != '#')  // ��Ϊ�սڵ�
      {
        // �½��ڵ㲢��ֵ
        node *current_node = (node*)malloc(sizeof(node));
        current_node->data = data;
        current_node->left_subtree = NULL;
        current_node->right_subtree = NULL;
        // ���뵽��ʱ�б���
        tmp_list[count] = current_node;
        // �ǿսڵ�����1
        count++;
        // �븸�ڵ㽨����ϵ
        if(j%2 == LEFT)
        {
          (parent_list[j/2])->left_subtree = current_node;
        }
        else
        {
          (parent_list[j/2])->right_subtree = current_node;
        }
      }
    }  // forѭ������
    
    // �ͷŸ����б�
    free(parent_list);
    // ���¸����б�
    parent_list = tmp_list;
    // ���¸��ڵ���
    parent_amount = count;
    // ���ǿսڵ���Ϊ0����ֹͣ����
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
