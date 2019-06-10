

Status PreOrderTraverse(BiTree T)
{
	if(T){
		printf("%d",T->data);
//		PreOrderTraverse(T->lchild);
//		PreOrderTraverse(T->rchild);
		//不够给力。。既然用到了返回状态的Status，最好利用起来！
		//并且知道，如果无左子树的话，则无右子树！可以提高效率！
		if(PreOrderTraverse(T->lchild))
			if(PreOrderTraverse(T->rchild))return Ok; 
	}
	return Ok;
 }
 
Status InOrderTraverse()
