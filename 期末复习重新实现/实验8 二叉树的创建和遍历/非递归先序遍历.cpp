typedef struct BiNode{
	SElemType data;
	struct BiNode *lchild;
	struct BiNode *rchild;
}BiNode,*BiTree;


Status PreOrderTraverse(BiTree T)
{
	SqStack S;InitStack(S);
//	while(!StackEmpty||T){
	//仔细。。StackEmpty是个函数，需要传参！至少空格是需要的，是调用函数的标志！ 
	while(!StackEmpty(S)||T){
		
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
 
Status InOrderTraverse(BiTree T)
{
	SqStack S;InitStack(S);
	while(!StackEmpty(S)||T){
		while(T){
			Push(S,T);
			T=T->lchild;
		}
	//	if(!StackEmpty){
		//调用函数记得用函数调用号 （） 啊！
		if(!StackEmpty()){
			Pop(S,T);
			printf("%c",T->data);
		//这里再加强一下理解！
		//当为最左下的子树（叶子结点）的时候。
		//出栈后输出自己
		//然后T=T->rchild;为右子树
		//因为叶子结点无右子树
		//所以下一次循环中
		//上面的while(T)直接不成立
		//又直接到这个判断中，出栈，得到叶子结点父树的输出
		//即对于叶子结点来说，连续出栈两次！实现了中序遍历！ 
			T=T->rchild;
		}
	}
}
 

 
 
 
