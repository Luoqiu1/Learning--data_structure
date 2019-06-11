typedef struct BiNode{
	SElemType data;
	struct BiNode *lchild;
	struct BiNode *rchild;
}BiNode,*BiTree;


Status PreOrderTraverse(BiTree T)
{
	SqStack S;InitStack(S);
	while(!StackEmpty||T){
		while(T){
			printf("%c",T->data);
			Push(S,T);
			T=T->lchild;
		}
		if(!StackEmpty){
			Pop(S,T);
			T=T->rchild;
		}
	}
 }
 

 
 
 
