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

Status DestroyQueue(LinkList &Q)
{
	if(Q.rear==Q.front)free(Q.front);
	QueuePtr p=Q.front,q=p->next;
	while(q!=Q.rear){
		free(p);p=q;q=q->next;
	}
	//还有队尾没有释放
	free(q);
	//有更好的做法。直接利用Q.front和Q.rear，反正整个队列都要被销毁了，改变Q.front和Q.rear无所谓
	
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
	//还有表一开始就不存在的时候
	if(!Q.front)exit(Overflow);
	 
	QueuePtr p=Q.front->next,q=p;
//	while(p){
	//有问题。。这样会连Q.rear，队尾域一起删除掉了！
	//应该保留队尾域，但是使队尾等于队头（空队列的标准） 
	while(p!=Q.rear){
	
		free(p);p=q->next;q=p;
	}
	Q.front->next=nullptr;
	Q.rear=Q.front;
	return Ok;
}








