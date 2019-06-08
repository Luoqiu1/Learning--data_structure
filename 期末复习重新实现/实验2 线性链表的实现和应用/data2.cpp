
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

int Go_L(LinkList La,LinkList Lb,LinkList &Lc)
{
//	pa=La;pb=Lb;pc=Lc=pa;
	//根据下面的算法，初始条件错了！而且没有声明pa、pb、pc就开始在用了！肯定不对！
	//合并表，取Lc的表头为La，最终还要将Lb给释放掉！
	//因为是把Lb合并到La中形成了Lc！Lc借助La的头结点！ 
	LinkList pa=La->next,pb=Lb->next,pc;pc=Lc=La; 
	 
	while(pa&&pb){
		if(pa->data<=pb->data){
		//	pc->next=pa->next;pa=pa->next;pc=pc->next;
			pc->next=pa;pa=pa->next;pc=pc->next; 
		}
		else{
		//	pc->next=pb->next;pb=pb->next;pc=pc->next;
			pc->next=pb;pb=pb->next;pc=pc->next;
		}
	}
//	while(pa){
	//这里就大错特错了！！！
	//根据要求，是  合并表  而  不是  重新构建表  ！ 
	
		//！ 
	// 一定要理解清楚！ 这里关系到下面是 if 还是 while 的选取！
		//！ 
	 
	//所以只要利用好剩余的链表即可！因为之前的La或者Lb都没有断开！
	if(pa){
	 
	//	pc->next=pa->next;pa=pa->next;pc=pc->next;
		//跟着上面的意思变即可！
		pc->next=pa; 
	}
//	while(pb){
	if(pb){
		pc->next=pb;
	}
	free(Lb);
	return 1;
}




int Go_L(LinkList La,LinkList Lb,LinkList &Lc)
{
	LinkList pa=La->next,pb=Lb->next,pc; pc=Lc=La;
	while(pa&&pb){
		if(pa->data<=pb->data){
			pc->next=pa;pa=pa->next;pc=pc->next;
		}
		else{
			pc->next=pb;pb=pb->next;pc=pc->next;
		}
	}
	if(pa){
		pc->next=pa;
	}
	if(pb){
		pc->next=pb;
	}
	free(Lb);
	return 1;
}


