

Status PreOrderTraverse(BiTree T)
{
	if(T){
		printf("%c",T->data);
//		PreOrderTraverse(T->lchild);
//		PreOrderTraverse(T->rchild);
		//��������������Ȼ�õ��˷���״̬��Status���������������
		//����֪����������������Ļ����������������������Ч�ʣ�
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

	//д��������
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



