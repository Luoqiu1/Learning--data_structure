
Status InitList_Sq(SqList &L)
{
//	L.elem=(ElemType*)malloc(sizeof(ElemType));
	//这里没有深刻理解 SqList L后的表L的含义！
	//表L其实是一种头结点的存在！
	//记录了当前长度、当前总容量及需要存放的数据！
	//而数据比较多，必然不适合放在头结点里
	//故用 链表 的形式来存放数据！
	//这样一来，头结点只要储存链表的头指针（基地址）
	//即可以依次找到其他的数据！
	L.elem=(ElemType*)malloc(sizeof(LISTINCREMENT*sizeof(ElemType)));
	
	 
	if(!L.elem)exit(Overflow);
	L.listsize=LIST_INIT_SIZE;
	L.length=0;
	return OK;
 } 
 
Status ListInsert_Sq(SqList &L,int i,ElemType e)
{
	if(i<1||i>L.length+1)return Error;
	if(!L.length)return Error;
	if(L.length+1>L.listsize){
//	该条件与 L.length>=L.listsize等效！
//	因为每次只插入一个元素！	
		L.elem=(ElemType*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!L.elem)exit(Overflow);
	//	++L.listsize; 
		//在想啥。。。每次增加空间不止是只增加一个啊！
		L.listsize+=LISTINCREMENT;
		 
	}
	for(int j=L.length-1;j>=i-1;--j){
	//	L.data[j+1]=L.data[j];
		//仔细。。结构体里的类型名是elem！不是data。。！
		L.elem[j+1]=L.elem[j];
	}
	L.elem[i-1]=e;
	//怎么又忘记长度要加一了！！！
	++L.length;
	 
	return Ok;
}


Status ListDelete_Sq(SqList &L,int i,ElemType &e)
{
	if(i<1||i>L.length)return Error;
	if(!L.length)return Error;
	e=L.elem[i-1];
	for(int j=i-1;j<L.length-1;++j){
		L.elem[j]=L.elem[j+1];
	} 
	--L.length;
	return Ok;
}





