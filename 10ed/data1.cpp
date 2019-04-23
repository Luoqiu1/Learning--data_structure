#include <bits/stdc++.h>
using namespace std;
#define True 1
#define Error 0
#define Overflow -2
#define Ok 1
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10 
#define CHILD 1
#define BROTHER 0
typedef int TreeData;
typedef struct _treenode
{
	TreeData data;              
	struct _treenode *child;      
	struct _treenode *brother;     
}TreeNode;

typedef struct _tree
{
	int len;                 
	TreeNode *head;          
}Tree;

 
Tree *Create_tree ()
{
	Tree *tree = (Tree*)malloc(sizeof(Tree)/sizeof(char));
	if (tree == NULL)
	{
		return NULL;
	}
	tree->head = (TreeNode *)malloc(sizeof(TreeNode)/sizeof(char));
	if (tree->head == NULL)
	{
		free(tree);
		return NULL;
	}
	tree->head->child = NULL;   
	tree->head->brother = NULL;  
	tree->len = 0;     
	return tree;
}

int Insert_Tree(Tree *tree, TreeData data, int pos, int count, int flag)
{
	if(tree == NULL || count < 0 || pos < 0 || flag != CHILD && flag != BROTHER)
	{
		return Error;
	}
	TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode)/sizeof(char));
	if (node == NULL)
	{
		return Error;
	}
	node->data = data;
	node->child = NULL;
	node->brother = NULL;
	if (count == 0)   
	{
		tree->head->child = node;
		tree->len++;  
		return True;
	}
	else
	{
		TreeNode *tmp = tree->head;
		int way;
		while (count > 0 && tmp != NULL)
		{
			way = pos & 1;
			pos = pos >> 1;
			if (way == CHILD)
			{
				tmp = tmp->child;
			}
			else
			{
				tmp = tmp->brother;
			}
			count--;
		}
		if (tmp == NULL)
		{
			printf ("插入越界\n");
			return Error;
		}
		if (flag == CHILD)
		{
			tmp->child = node;
		}
		else
		{
			tmp->brother = node;
		}
		tree->len++; 
	}
	return True;	
}
 
void r_display(TreeNode *node,int gap)
{
	if (node == NULL)
	{
		return;
	}
	int i;
	for (i = 0; i < gap;i++)
	{
		printf ("-");
	}
	printf ("%c\n",node->data);
	TreeNode * child = node->child;
	r_display (child,gap+4);
	TreeNode * brother = node->brother;
	r_display (brother,gap);
}
 
void Display(Tree *tree)
{
	if (tree == NULL)
	{
		return;
	}
	r_display(tree->head->child,0);
}
 
void r_delete (Tree* tree,TreeNode* node)
{
	if (node ==NULL || node->child == NULL && node->brother == NULL)
	{
		return;
	}
	TreeNode* p = node->child;  
	r_delete(tree,p);   
	if (p != NULL)
	{
		tree->len--;   
	}
	free(p);       
	p = node->brother;   
	r_delete(tree,p);  
	if (p != NULL)
	{
		tree->len--;
	}
	free(p);      
}
 
int Delete(Tree *tree, int pos, int count, TreeData *x)
{
	if(tree == NULL || x == NULL || count <= 0 || pos <= 0)
	{
		return Error;
	}
	if(tree->head->child == NULL)
	{
		printf ("此树为空\n");
		return Error;
	}
	TreeNode *tmp = tree->head;
	int way;
	while (count > 1 && tmp != NULL)
	{
		way = pos & 1;
		pos = pos >> 1;
		if (way == CHILD)
		{
			tmp = tmp->child;
		}
		else
		{
			tmp = tmp->brother;
		}
		count--;
	}
	if (tmp == NULL)
	{
		printf ("删除越界\n");
		return Error;
	}
	way = pos & 1;  
	if (way == CHILD)
	{
		if (tmp->child == NULL)
		{
			printf ("删除越界\n");
			return Error;
		}
	}
	else
	{
		if (tmp->brother == NULL)
		{
			printf ("删除越界\n");
			return Error;
		}
	}
	if (way == CHILD)
	{
		TreeNode* p = tmp->child;
		*x = p->data;
		tmp->child = p->brother; 
		p->brother = NULL;   
		
		r_delete(tree,p);  
		free(p); 
		tree->len--;  
	}
	else
	{
		TreeNode* p = tmp->brother;
		*x = p->data;
		tmp->brother = p->brother;
		p->brother = NULL;
		
		r_delete(tree,p);
		free(p);
		tree->len--;
	}
}
 
int Tree_Get(Tree *tree, int pos, int count, TreeData *x)
{
	if(tree == NULL || x == NULL || count <= 0 || pos <= 0)
	{
		return Error;
	}
	TreeNode *tmp = tree->head;
	int way;
	while (count > 0 && tmp != NULL)
	{
		way = pos & 1;
		pos = pos >> 1;
		if (way == CHILD)
		{
			tmp = tmp->child;
		}
		else
		{
			tmp = tmp->brother;
		}
		count--;
	}
	if (tmp == NULL)
	{
		printf ("查看越界\n");
		return Error;
	}
	*x = tmp->data;
	return True;
	
}
 
int Tree_Clear(Tree* tree)
{
	if (tree == NULL)
	{
		return Error;
	}
	TreeData x;
	return Delete(tree,1,1,&x); 
}
 
void Tree_Destroy(Tree* tree)
{
	if (tree == NULL)
	{
		return;
	}
	Tree_Clear(tree); 
	free(tree->head);
	free(tree); 
}
 
TreeNode* Tree_Root(Tree* tree)
{
	if (tree == NULL)
	{
		return Error;
	}
	return tree->head->child;
}
 
int Tree_Count(Tree* tree)
{
	if (tree == NULL)
	{
		return Error;
	}
	return tree->len;
}
 
int r_height (TreeNode *node,int gap)
{
	if (node == NULL)
	{
		return gap;
	}
	
	TreeNode * child = node->child; 
	int ret = r_height (child,gap+1);  
	TreeNode * brother = node->brother;   
	r_height (brother,gap);     
	return ret; 
}
 
int Tree_Height(Tree* tree)
{
	if (tree == NULL)
	{
		return Error;
	}
	int ret = r_height (tree->head->child,0);
	return ret;
}
 
int r_degree (TreeNode* node,int deg)
{
	int i = 0;
	if (node == NULL)
	{
		return deg;
	}
	TreeNode* p = node->child;
	if (p != NULL) 
	{
		i++;
	}
	int degtmp = r_degree(p,i);
	p = node->brother;
	if (p != NULL) 
	{
		deg++;
	}
	int tmpdeg = r_degree(p,deg); 
	return (tmpdeg > degtmp ? tmpdeg : degtmp);
}

int Tree_Degree(Tree* tree)
{
	if (tree == NULL || tree->head == NULL || tree->head->child == NULL)
	{
		return Error;
	}
	int deg = r_degree (tree->head->child,0);
	return deg;
}


