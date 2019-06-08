
Status GetElem_L(LinkList L,int i,ElemType &e)
{
	if(!L)return 0;
	LinkList p=L;int j=0;
//	while(j!=i){
	//对指针，一定要仔细！访问的时候一定要判断是否为空
	while(p&&j!=i){	//j<i也可 
	 
		p=p->next;++j;
	}
	//要判断是否存在第i个元素！
	if(!p||j>i)return 0;//我觉得j>i不可能成立啊 
	
//	e=*p;
	//p指针指向了什么！是一个结构体。。。
	//我们要的是结构体成员！而不是这个结构体
	e=p->data;
	
	return 1;
}

Status ListInsert_L(LinkList &L,int i,ElemType e)
{
	if(!L)return Error;
	LinkList p=L;int j=0;
//	while(p&&j<i){
	//这个条件一定要仔细啊！。。j<i为循环条件是只要j<i就进入循环体！
	//结束的时候正好是j=i！。。。
	//我们要在j=i-1的时候结束 条件应该是 j<i-1!!!!!!!!!!!!!!!!!!!!!!
	while(p&&j<i-1){
		p=p->next;++j;
	}
	if(!p)return Error;
	LinkList q=(LinkList)malloc(sizeof(LNode));
	if(!q)exit(Overflow);
	q->next=p->next;q->data=e;
	p->next=q;
	return Ok;
}








