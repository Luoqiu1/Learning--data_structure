
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
	//	在想什么啊。。。！
	//	用到循环一定要记得在循环体中改变条件判断中的值啊！
	//	在用到以指针为循环条件的时候尤要注意。。！ 
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
		//这里考虑有问题！
		//是忽略了基址处，即 S.base 这里，本身也可以存储一个元素！
		S.top=S.base+S.stacksize;
	//	同时又忘记了！！！在追加空间后，代表空间中空间大小的 S.stacksize 也需要跟着变化！
		S.stacksize+=STACKINCREMENT;
			 
		 
	}
	*S.top++=e;
	return Ok;
}






















