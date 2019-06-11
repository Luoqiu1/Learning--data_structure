typedef struct BiNode{
	SElemType data;
	struct BiNode *lchild;
	struct BiNode *rchild;
}BiNode,*BiTree;


Status PreOrderTraverse(BiTree T)
{
	SqStack S;InitStack(S);
//	while(!StackEmpty||T){
	//��ϸ����StackEmpty�Ǹ���������Ҫ���Σ����ٿո�����Ҫ�ģ��ǵ��ú����ı�־�� 
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
		//���ú����ǵ��ú������ú� ���� ����
		if(!StackEmpty()){
			Pop(S,T);
			printf("%c",T->data);
		//�����ټ�ǿһ����⣡
		//��Ϊ�����µ�������Ҷ�ӽ�㣩��ʱ��
		//��ջ������Լ�
		//Ȼ��T=T->rchild;Ϊ������
		//��ΪҶ�ӽ����������
		//������һ��ѭ����
		//�����while(T)ֱ�Ӳ�����
		//��ֱ�ӵ�����ж��У���ջ���õ�Ҷ�ӽ�㸸�������
		//������Ҷ�ӽ����˵��������ջ���Σ�ʵ������������� 
			T=T->rchild;
		}
	}
}
 

 
 
 
