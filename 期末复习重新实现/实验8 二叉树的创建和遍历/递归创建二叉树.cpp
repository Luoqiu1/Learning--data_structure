

Status PreOrderTraverse(BiTree T)
{
	if(T){
		printf("%d",T->data);
//		PreOrderTraverse(T->lchild);
//		PreOrderTraverse(T->rchild);
		//��������������Ȼ�õ��˷���״̬��Status���������������
		//����֪����������������Ļ����������������������Ч�ʣ�
		if(PreOrderTraverse(T->lchild))
			if(PreOrderTraverse(T->rchild))return Ok; 
	}
	return Ok;
 }
 
Status InOrderTraverse()
