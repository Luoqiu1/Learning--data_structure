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
