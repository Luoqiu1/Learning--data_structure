typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

Status Go(LinkList &L)
{
	LinkList p=L,q=p;
	while(p){
	//	while(q->next->data>=0)q=q->next;
		//�ڷ���ָ��ǰ�����ж�ָ���Ƿ�Ϊ�հ�����
		while(q->next&&q->next->data>=0)q=q->next;
		
		//���ǵ�����û���ҵ�С��0�Ľ��󣬼��ɽ���ѭ����
		//�ҵ��Ļ�����ִ���������
		if(!q->next)break; 
		
		LinkList r=q->next;
		q->next=r->next;
	//	r->next=L->next;
	//	L->next=r;
		//�����������⣡��Ϊ����ǰѸ��Ĳ�����
		//ͷ���󣬳�Ϊ�µ��׽��Ԫ��
		//���������Ѿ�ͬ��������������ĸ�Ԫ�ؼ����Ƚ�
		//�������������ѭ������
		//��Ӧ���ǲ���ÿ�ε�p��Ȼ�����pΪ�ղ���ĸ���㣡
		r->next=p->next;
		p->next=r; 
	
		p=p->next;
		q=p;
	}
} 

Status Go2(LinkList &L)
{
	LinkList p=L->next,q=p;
	while(p){
		ElemType judge=p->data;
		while(q){
			while(q->next&&q->next->data!=judge)q=q->next;
			if(!q->next)break;
			LinkList r=q->next;
			q->next=r->next;
			free(r);
			q=p;
		}
		p=p->next;
		q=p;//��������Ǹ��°������� 
	}
}





