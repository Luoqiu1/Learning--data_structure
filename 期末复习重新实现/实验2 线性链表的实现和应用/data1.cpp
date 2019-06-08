
Status GetElem_L(LinkList L,int i,ElemType &e)
{
	if(!L)return 0;
	LinkList p=L;int j=0;
//	while(j!=i){
	//��ָ�룬һ��Ҫ��ϸ�����ʵ�ʱ��һ��Ҫ�ж��Ƿ�Ϊ��
	while(p&&j!=i){	//j<iҲ�� 
	 
		p=p->next;++j;
	}
	//Ҫ�ж��Ƿ���ڵ�i��Ԫ�أ�
	if(!p||j>i)return 0;//�Ҿ���j>i�����ܳ����� 
	
//	e=*p;
	//pָ��ָ����ʲô����һ���ṹ�塣����
	//����Ҫ���ǽṹ���Ա������������ṹ��
	e=p->data;
	
	return 1;
}

Status ListInsert_L(LinkList &L,int i,ElemType e)
{
	if(!L)return Error;
	LinkList p=L;int j=0;
//	while(p&&j<i){
	//�������һ��Ҫ��ϸ��������j<iΪѭ��������ֻҪj<i�ͽ���ѭ���壡
	//������ʱ��������j=i��������
	//����Ҫ��j=i-1��ʱ����� ����Ӧ���� j<i-1!!!!!!!!!!!!!!!!!!!!!!
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

Status ListDelete_L(LinkList &L,int i,ElemType &e)
{
	if(!L)return Error;
	LinkList p=L;int j=0;
//	while(p&&j!=i-1){
	//���������һЩ��������Ϊ֮��Ҫ�ͷű�ɾ���Ŀռ䣡
	//����������ֻ�ǿ�p�Ƿ�ǿյĻ�����ѭ��������е���p=p->next;
	//p��ǿգ���p->nextΪ�գ��ͷŻ����
	//��Ϊ��ָ���޷��ͷţ���
	//������������p������Ϊʲô����д��
	while(p->next&&j!=i-1){
	 
		p=p->next;++j;
	}
	if(!p)return Error;
	e=p->next->data;
	LinkList s=p->next;
	p->next=p->next->next;
	free(s);
	return Ok;
}







