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
	//这句话注意了，初始化的时候，即建空队列的时候，需要分配空间了！ 
	if(!Q.front)exit(Overflow);
	Q.front->next=nullptr
	//这条语句记得别忘了！空队列时无队列元素，Q.front是头结点
	//之所以这样做是方便控制判断队列为空的情况！
	//当Q.front=Q.rear时为空！ 
	//而若不将Q.front设为头结点以用来作为判断是否为空的依据
	//则会比较麻烦！因为第一个队列元素用Q.front表示的时候，Q.rear也指向了第一个元素！
	//二者相等。 则想要找一个判断是否为空的基准比较困难！ 
	return Ok;
}
