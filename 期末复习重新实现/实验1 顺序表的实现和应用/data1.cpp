
Status ListInsert(SqList &L,int i,ElemType e)
{
	//
	if(i<1||i>L.length+1)return Error;
//	for(int j=L.length+1;j>i;++j){
						//���ˡ����ǵݼ�������ϸ 
	/*	for(int j=L.length+1;j>i;--j){////
		L.data[j]=L.data[j-1];
	}
	L.data[i]=e;
	*/		//��ʵ��������������⣡
			//����i�ǵ�i��Ԫ�أ������������еĵ�i��������
			//��˼�� ��3��Ԫ�� ΪL.data[2] !
		 
		
	//û��ע��ϸ�ڣ�����Ԫ�غ��ܳ�����Ҫ��һ�� 
		++L.length; ////
	return True;
 } 
