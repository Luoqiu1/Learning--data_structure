

Status PreOrderTraverse(BiTree T)
{
	if(T){
		printf("%c",T->data);
//		PreOrderTraverse(T->lchild);
//		PreOrderTraverse(T->rchild);
		//不够给力。。既然用到了返回状态的Status，最好利用起来！
		//并且知道，如果无左子树的话，则无右子树！可以提高效率！
		if(PreOrderTraverse(T->lchild))
			if(PreOrderTraverse(T->rchild))return Ok; 
	}
	return Ok;
 }
 
Status InOrderTraverse(BiTree T)
{
//	if(T){
//		if(InOrderTraverse(T->lchild)){
//			printf("%c",T->data);
//			if(InOrderTraverse(T->rchild))return Ok;
//		}
//	}
//	return Ok;

	//写法不够好
	int m=0;
	if(T){
		if(InOrderTraverse(T->lchild))m=1;
		printf("%c",T->data);
		if(m)
			if(InOrderTraverse(T->rchild))return Ok;
			return Error;
	}
	return Ok;
	
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
	return OK;
}



