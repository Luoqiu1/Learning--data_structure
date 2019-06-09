
Status MergeList_L(LinkList La,LinkList Lb,LinkList &Lc)
{
	Lc=(LinkList)malloc(sizeof(LNode));if(!Lc)exit(-2);
	LinkList pa=La->next,pb=Lb->next,pc=Lc;
	while(pa&&pb){
		if(pa->data<pb->data){
			LinkList q=(LinkList)malloc(sizeof(LNode));if(!pc)exit(-2);
			pc->next=q;
			q->data=pa->data;q->next=nullptr;pa=pa->next;
			pc=pc->next;
		}
		else{
			LinkList q=(LinkList)malloc(sizeof(LNode));if(!pc)exit(-2);
			pc->next=q;
			q->data=pb->data;q->next=nullptr;pb=pb->next;
			pc=pc->next;
		}
	}
	while(pa){
		LinkList q=(LinkList)malloc(sizeof(LNode));if(!pc)exit(-2);
		pc->next=q;
		q->data=pa->data;q->next=nullptr;pa=pa->next;
		pc=pc->next;
	}
	
	//
	//	LinkList pc->next=(LinkList)malloc(sizeof(LNode));if(!pc)exit(-2);
		//对比之前的， 对 pc->next 分配空间，但若 pc->next=NULL，空指针，指向的是空域
		//														则无法分配！分配失败！
		//													因为空指针不是具体的某一对象！
		//														无法分配空间！
		//									试想，就算分配成功了，这个空间的名称叫什么，如何找到这个空间？	 
		//														理解透彻！ 
	
	
	while(pb){
		LinkList q=(LinkList)malloc(sizeof(LNode));if(!pc)exit(-2);
		pc->next=q;
		q->data=pb->data;q->next=nullptr;pb=pb->next;
		pc=pc->next;
	}
	return Ok;
}
