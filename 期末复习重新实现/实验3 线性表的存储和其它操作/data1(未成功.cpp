Status Go(LinkList &L,int n)
{
	LinkList p,q,s;
	if(!L->next)return Error;
	p=L;q=L->next;
	ElemType min=q->data;
	while(n--){
		while(q->next){
			if(min>q->next->data){
				s=q;min=q->next->data;
			}
			q=q->next;
		}
		LinkList r=s->next;
		s->next=s->next->next;
		r->next=p->next;
		p->next=r;
		p=p->next;
	}
	return True;
} 

Status Go(LinkList &L,int n)
{
	LinkList p,q;
	p=L->next;q=p->next;
	ElemType min=p->data;
	while(n--){
		while(q){
			if(q->data<min){
				min=q->data;
			}
			//傻了啊。。。没对q做操作，不是无限循环了！
			// 指针里最容易出这个错。。！p=p->next 相当于i j循环里的自增 ++i ++j！！！
			q=q->next;
			 
		}
		if(min!=p->data){
			q=p->next;
			ElemType mid=p->data;
			p->data=min;
			while(q->data!=min){
				q=q->data;
			}
			q->data=mid;
		}
		p=p->next;
		q=p->next;
	}
	return True;
 } 




