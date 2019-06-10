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
		//这两句有问题！因为如果是把负的插入在
		//头结点后，成为新的首结点元素
		//会跟后面的已经同样这样插入进来的负元素继续比较
		//这样会造成无限循环！。
		//故应该是插在每次的p后，然后更新p为刚插入的负结点！
		r->next=p->next;
		p->next=r; 
	
		p=p->next;
		q=p;
	}
	
} 
