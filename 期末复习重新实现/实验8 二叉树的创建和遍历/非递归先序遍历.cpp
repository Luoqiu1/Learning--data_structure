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

Status PostOrderTraverse(BiTree T)
{
	SqStack S;InitStack(S);
	Push(S,T);
	BiTree pre=nullptr;
	while(!StackEmpty(S)){
		//这里没那么多时间就暂时记一下。
		//前序中序的判断条件是 T||!StackEmpty(S)
		//				后序是 !StackEmpty(S) 
		//跟着反向记，后序中先Push了根结点，所以可以直接用 !StackEmpty(S)
		//				而前中序中在循环之前没有Push根结点！
		 
		if(!T->lchild&&!T->rchild||pre&&(pre==T->lchild||pre==T->rchild)){//找到了满足条件的结点 
		//	pre=T;
			//这个次序有问题啊。。pre应该是等于当前访问的这个。
			//因为下一次判断时就对下个T来说，pre就是上一次访问的了！
			//所以pre应该放在更新了T之后！也就是Pop（S，T）之后
			//	写的栈操作中，Pop和Push都会更新T！ 
			Pop(S,T);
			printf("%c",T->data);
			//这里
			pre=T; 
			
		}
	//	if(T->lchild)Push(S,T->lchild);
	//	if(T->rchild)Push(S,T->rchild);
		//应该是满足则出栈，输出
		//未满足则入栈！。。
		else{//未找到，入栈！ 
			if(T->lchild)Push(S,T->lchild);
			if(T->rchild)Push(S,T->rchild);
		} 
		
	}
 } 

 

 
 
 
