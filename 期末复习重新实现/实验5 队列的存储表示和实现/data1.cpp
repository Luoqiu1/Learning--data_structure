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
