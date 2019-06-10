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
		//在访问指针前，先判断指针是否为空啊！。
		while(q->next&&q->next->data>=0)q=q->next;
		
		//考虑到，当没有找到小于0的结点后，即可结束循环！
		//找到的话，则执行以下语句
		if(!q->next)break; 
		
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
		q=p;//这里别忘记更新啊！。。 
	}
}





