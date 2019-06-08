
Status InitList_Sq(SqList &L)
{
//	L.elem=(ElemType*)malloc(sizeof(ElemType));
	//����û�������� SqList L��ı�L�ĺ��壡
	//��L��ʵ��һ��ͷ���Ĵ��ڣ�
	//��¼�˵�ǰ���ȡ���ǰ����������Ҫ��ŵ����ݣ�
	//�����ݱȽ϶࣬��Ȼ���ʺϷ���ͷ�����
	//���� ���� ����ʽ��������ݣ�
	//����һ����ͷ���ֻҪ���������ͷָ�루����ַ��
	//�����������ҵ����������ݣ�
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
//	�������� L.length>=L.listsize��Ч��
//	��Ϊÿ��ֻ����һ��Ԫ�أ�	
		L.elem=(ElemType*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!L.elem)exit(Overflow);
	//	++L.listsize; 
		//����ɶ������ÿ�����ӿռ䲻ֹ��ֻ����һ������
		L.listsize+=LISTINCREMENT;
		 
	}
	for(int j=L.length-1;j>=i-1;--j){
	//	L.data[j+1]=L.data[j];
		//��ϸ�����ṹ�������������elem������data������
		L.elem[j+1]=L.elem[j];
	}
	L.elem[i-1]=e;
	//��ô�����ǳ���Ҫ��һ�ˣ�����
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





