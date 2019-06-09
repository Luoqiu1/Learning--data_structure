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








