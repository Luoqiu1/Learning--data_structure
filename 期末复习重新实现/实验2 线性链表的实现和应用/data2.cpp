
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
		//�Ա�֮ǰ�ģ� �� pc->next ����ռ䣬���� pc->next=NULL����ָ�룬ָ����ǿ���
		//														���޷����䣡����ʧ�ܣ�
		//													��Ϊ��ָ�벻�Ǿ����ĳһ����
		//														�޷�����ռ䣡
		//									���룬�������ɹ��ˣ�����ռ�����ƽ�ʲô������ҵ�����ռ䣿	 
		//														���͸���� 
	
	
	while(pb){
		LinkList q=(LinkList)malloc(sizeof(LNode));if(!pc)exit(-2);
		pc->next=q;
		q->data=pb->data;q->next=nullptr;pb=pb->next;
		pc=pc->next;
	}
	return Ok;
}
