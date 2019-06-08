
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
