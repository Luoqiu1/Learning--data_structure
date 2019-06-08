
Status ListInsert(SqList &L,int i,ElemType e)
{
	//
	if(i<1||i>L.length+1)return Error;
//	for(int j=L.length+1;j>i;++j){
						//憨了。。是递减啊！仔细 
	/*	for(int j=L.length+1;j>i;--j){////
		L.data[j]=L.data[j-1];
	}
	L.data[i]=e;
	*/		//其实这整段理解有问题！
			//给的i是第i个元素！而不是数组中的第i个索引！
			//意思是 第3个元素 为L.data[2] !
		 
		
	//没有注意细节！插入元素后总长度需要加一！ 
		++L.length; ////
	return True;
 } 
