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

Status PostOrderTraverse(BiTree T)
{
	SqStack S;InitStack(S);
	Push(S,T);
	BiTree pre=nullptr;
	while(!StackEmpty(S)){
		//����û��ô��ʱ�����ʱ��һ�¡�
		//ǰ��������ж������� T||!StackEmpty(S)
		//				������ !StackEmpty(S) 
		//���ŷ���ǣ���������Push�˸���㣬���Կ���ֱ���� !StackEmpty(S)
		//				��ǰ��������ѭ��֮ǰû��Push����㣡
		 
		if(!T->lchild&&!T->rchild||pre&&(pre==T->lchild||pre==T->rchild)){//�ҵ������������Ľ�� 
		//	pre=T;
			//������������Ⱑ����preӦ���ǵ��ڵ�ǰ���ʵ������
			//��Ϊ��һ���ж�ʱ�Ͷ��¸�T��˵��pre������һ�η��ʵ��ˣ�
			//����preӦ�÷��ڸ�����T֮��Ҳ����Pop��S��T��֮��
			//	д��ջ�����У�Pop��Push�������T�� 
			Pop(S,T);
			printf("%c",T->data);
			//����
			pre=T; 
			
		}
	//	if(T->lchild)Push(S,T->lchild);
	//	if(T->rchild)Push(S,T->rchild);
		//Ӧ�����������ջ�����
		//δ��������ջ������
		else{//δ�ҵ�����ջ�� 
			if(T->lchild)Push(S,T->lchild);
			if(T->rchild)Push(S,T->rchild);
		} 
		
	}
 } 

 

 
 
 
