
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

int Go_L(LinkList La,LinkList Lb,LinkList &Lc)
{
//	pa=La;pb=Lb;pc=Lc=pa;
	//����������㷨����ʼ�������ˣ�����û������pa��pb��pc�Ϳ�ʼ�����ˣ��϶����ԣ�
	//�ϲ���ȡLc�ı�ͷΪLa�����ջ�Ҫ��Lb���ͷŵ���
	//��Ϊ�ǰ�Lb�ϲ���La���γ���Lc��Lc����La��ͷ��㣡 
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
	//����ʹ���ش��ˣ�����
	//����Ҫ����  �ϲ���  ��  ����  ���¹�����  �� 
	
		//�� 
	// һ��Ҫ�������� �����ϵ�������� if ���� while ��ѡȡ��
		//�� 
	 
	//����ֻҪ���ú�ʣ��������ɣ���Ϊ֮ǰ��La����Lb��û�жϿ���
	if(pa){
	 
	//	pc->next=pa->next;pa=pa->next;pc=pc->next;
		//�����������˼�伴�ɣ�
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


