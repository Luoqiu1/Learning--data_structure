typedef struct QNode{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;
typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue &Q)
{
	Q.front=Q.rear=(QNode*)malloc(sizeof(QNode));
	//��仰ע���ˣ���ʼ����ʱ�򣬼����ն��е�ʱ����Ҫ����ռ��ˣ� 
	if(!Q.front)exit(Overflow);
	Q.front->next=nullptr
	//�������ǵñ����ˣ��ն���ʱ�޶���Ԫ�أ�Q.front��ͷ���
	//֮�����������Ƿ�������ж϶���Ϊ�յ������
	//��Q.front=Q.rearʱΪ�գ� 
	//��������Q.front��Ϊͷ�����������Ϊ�ж��Ƿ�Ϊ�յ�����
	//���Ƚ��鷳����Ϊ��һ������Ԫ����Q.front��ʾ��ʱ��Q.rearҲָ���˵�һ��Ԫ�أ�
	//������ȡ� ����Ҫ��һ���ж��Ƿ�Ϊ�յĻ�׼�Ƚ����ѣ� 
	return Ok;
}

Status DestroyQueue(LinkList &Q)
{
	if(Q.rear==Q.front)free(Q.front);
	QueuePtr p=Q.front,q=p->next;
	while(q!=Q.rear){
		free(p);p=q;q=q->next;
	}
	//���ж�βû���ͷ�
	free(q);
	//�и��õ�������ֱ������Q.front��Q.rear�������������ж�Ҫ�������ˣ��ı�Q.front��Q.rear����ν
	
	while(Q.front){
		Q.rear=Q.front->next;
		free(Q.front);
		Q.front=Q.rear;
	} 
	
	return Ok;
}

Status ClearQueue(LinkQueue &Q)
{
	if(Q.front==Q.rear)return Error;
	//���б�һ��ʼ�Ͳ����ڵ�ʱ��
	if(!Q.front)exit(Overflow);
	 
	QueuePtr p=Q.front->next,q=p;
//	while(p){
	//�����⡣����������Q.rear����β��һ��ɾ�����ˣ�
	//Ӧ�ñ�����β�򣬵���ʹ��β���ڶ�ͷ���ն��еı�׼�� 
	while(p!=Q.rear){
	
		free(p);p=q->next;q=p;
	}
	Q.front->next=nullptr;
	Q.rear=Q.front;
	return Ok;
}

int QueueLength(LinkQueue Q)
{
	if(Q.front==Q.rear)return Error;
	QueuePtr p=Q.front->next;int length=1;
	while(p!=Q.rear){
		++length;p=p->next;
	}
	return length;
}

Status GetHead(LinkQueue Q,QElemType &e)
{
	if(Q.front==Q.rear)return Error;
	e=Q.front->next->data;
	return Ok;
}

Status EnQueue(LinkQueue &Q,QElemType e)
{
	QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
	//���������������ˡ�����׳�ԣ�
	if(!p)exit(Overflow);
	 
	p->data=e;p->next=nullptr;
	Q.rear->next=p;Q.rear=p;
	return Ok;
}

Status DeQueue(LinkQueue &Q,QElemType &e)
{
	if(Q.front==Q.rear)return Error;
//	QueuePtr p=Q.front;
//	while(p->next!=Q.rear){
//		p=p->next;
//	}
//	e=Q.rear->data;
//	if(Q.front->next=Q.rear){
//		free(Q.rear);Q.rear=Q.front;Q.front->next=nullptr;
//	}
//	free(Q.rear);
//	p->next=nullptr;Q.rear=p;
	//ɵ�˰������������������Ƚ��ȳ��������������ǳ�����Ԫ�أ�������
	QueuePtr p=Q.front->next;
	Q.front->next=Q.front->next->next;
	e=p->data;
	if(p==Q.rear)Q.rear=Q.front;
	free(p);
	return Ok;
}

Status QueueTraverse(LinkQueue Q)
{
	QueuePtr p=Q.front->next;
	if(!p)return Error;
	while(p){
		cout<<p->data;
		//���ﵽ�״���ٴ��ˡ�����!!!
		//ָ��μӵ�ѭ����һ���ǵ���ѭ�����ڸı�ָ�밡��
		p=p->next; 
	}
	return Ok;
}




