
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
