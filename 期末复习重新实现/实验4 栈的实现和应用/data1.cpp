
typedef struct{
	SelemType *base;
	SelemType *top;
	int stacksize;
}SqStack;

Status InitStack(SqStack &S)
{
	S.base=(SelemType*)malloc(sizeof(SelemType)*STACK_INIT_SIZE);
	if(!S.base)exit(Overflow);
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE; 
	return Ok;
 } 
 
Status StackEmpty(SqStack S)
{
	if(S.base==S.top)return Ok;
	return No;
}

Status StackTraverse(SqStack S)
{
	SelemType *p=S.top-1;
	while(p!=S.base){
		cout<<*p;
	//	����ʲô����������
	//	�õ�ѭ��һ��Ҫ�ǵ���ѭ�����иı������ж��е�ֵ����
	//	���õ���ָ��Ϊѭ��������ʱ����Ҫע�⡣���� 
		--p;
		
	}
	cout<<*p;
	return Ok;
}

Status GetTop(SqStack S,SElemType &e)
{
	if(S.base==S.top)return Error;
	e=S.top[-1];
	return Ok;
}

Status Push(SqStack &S,SElemType e)
{
	if(S.top-S.base>=S.stacksize){
		S.base=(SElemType*)realloc(S.base,sizeof(SElemType)*(S.stacksize+STACKINCREMENT));
		if(!S.base)exit(Overflow);
	//	S.top=S.base+S.stacksize+1;
		//���￼�������⣡
		//�Ǻ����˻�ַ������ S.base �������Ҳ���Դ洢һ��Ԫ�أ�
		S.top=S.base+S.stacksize;
	//	ͬʱ�������ˣ�������׷�ӿռ�󣬴���ռ��пռ��С�� S.stacksize Ҳ��Ҫ���ű仯��
		S.stacksize+=STACKINCREMENT;
			 
		 
	}
	*S.top++=e;
	return Ok;
}






















