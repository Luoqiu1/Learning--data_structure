typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

Status Go(LinkList &L)
{
	LinkList p=L,q=p;
	while(p){
		while(q->next->data>=0)q=q->next;
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
