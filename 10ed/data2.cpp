#include <bits/stdc++.h>
using namespace std;
#define Ok 1
#define Error 0
#define Overflow -2
#define True 1
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int Status;
typedef char TElemType;
typedef struct LinkBitNode{
	TElemType data;
	LinkBitNode *rchild,*lchild;
}LinkBitNode,*LinkBiTree;
typedef LinkBiTree SElemType;
typedef LinkBiTree QElemType;
typedef struct SqStack{
	SElemType *top,*base;
	int stacksize;
}SqStack;
typedef struct QNode{
	QElemType data;
	struct QNode *next;
}QNode,*Queueptr;
typedef struct LinkQueue{
	Queueptr front,rear;
}LinkQueue;
typedef struct LinkBitNode2{
	LinkBiTree T2;
	bool falg=false;
}LinkBitNode2,*LinkBiTree2;
typedef struct SqStack2{
	LinkBiTree2 top,base; 
	bool flag=false;
}SqStack2;

int QueueLength(LinkQueue Q)
{
	int Length=0;
	Queueptr q;
	q=Q.front;
	while(q!=Q.rear){
		Length++;q=q->next;
	}
	return Length;
}

Status InitQueue(LinkQueue &Q)
{
	Q.front=Q.rear=(QNode*)malloc(sizeof(QNode));
	if(!Q.front)exit(Overflow);
	Q.front->next=nullptr;
	return Ok; 
}

Status QueueEmpty(LinkQueue Q)
{
	if(Q.front==Q.rear)return Ok;
	return !Ok;
}

Status GetHead(LinkQueue Q,QElemType &e)
{
	if(Q.front==Q.rear)return Error;
	e=Q.front->next->data;//���в�ȡͬ���Ա�ĵ�����һ����Ϊ�������������
							//��������Ҳ���һ��ͷ��� Q.front ! 
	return Ok;
}

Status DeQueue(LinkQueue &Q,QElemType &e)
{
	Queueptr q;
	if(Q.front==Q.rear)return Error;
	q=Q.front->next;
	Q.front->next=q->next;
	e=q->data;
	if(Q.rear==q)Q.rear=Q.front;
	free(q);
	return Ok; 
}

Status EnQueue(LinkQueue &Q,QElemType e)
{
	Q.rear->next=(QNode*)malloc(sizeof(QNode));
	if(!(Q.front->next))exit(Overflow);
	Q.rear->next->data=e;
	Q.rear->next->next=nullptr;
	Q.rear=Q.rear->next;
	return Ok;
}

Status InitStack(SqStack &S)
{
	S.base=(SElemType*)malloc(sizeof(SElemType)*STACK_INIT_SIZE);
	if(!S.base)exit(Overflow);
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	return Ok;
}

Status Pop(SqStack &S,SElemType &e)
{
	if(S.base==S.top)return Error;
	S.top--;
	e=*S.top;
	return Ok;
}

Status Push(SqStack &S,SElemType e)
{
	if(S.top-S.base>=S.stacksize){
		S.base=(SElemType*)realloc(S.base,sizeof(SElemType)*(S.stacksize+STACKINCREMENT));
		if(!S.base)exit(Overflow);
		S.top=S.base+S.stacksize;
		S.stacksize+=STACKINCREMENT;
	}
	*S.top=e;
	S.top++;
	return Ok;
}

Status InitBiTree(LinkBiTree &T)
{	//�������빹�������������ڶ�Ϊ���Ķ�������	����Ҫ������ͼ��ʾ��������1#234#567###### 
	//														   1
	//												      #		    2
	//													       3        4 
	//														  #  5	  6    7 
	//														    #  # # #  # # 
	//����ͨ�����Ա����ʽ�洢�ṹʵ��
	//˼·���Ƚ������ĸ���㣬����һ����Ž��ָ���ָ��ռ䣨����ָ������Ĺ��ܣ���ͬ���������Ƕ�̬�ģ�
	//�����˸��������ȷ���˵�һ��ָ��ռ�Ĵ�С�� 
	//ÿ��ѭ����һ�Σ�ѭ����һ�㣩�õ������ĸ�����ͨ����¼�����ĸ��������·������ָ��Ŀռ䡣
	//����� j �����������һ����ѭ�����˵ڼ�������j=0��ʾ��һ������ 
	//ͨ��j%2��j/2��ʾ�����������丸�����ڶ���ָ���е�λ��
	//�������ͷŶ���ָ��Ŀռ䣬��������Ϊ�������·������ָ��Ŀռ� 
	char ch;						
	scanf("%c",&ch);
	if(ch=='#'){
		return Error;
	}
	else{
		T=(LinkBitNode*)malloc(sizeof(LinkBitNode));
		T->data=ch;T->lchild=nullptr;T->rchild=nullptr;
		int ParentsTreeNum=1;
		LinkBitNode **ParentsTree=(LinkBitNode**)malloc(sizeof(LinkBitNode*)*ParentsTreeNum);
		ParentsTree[ParentsTreeNum-1]=T;//�����洢���׽��ָ��,ParentsTree�Լ������childTree�൱��ָ������ 
		//�����˿ռ䣬�ɽ�����Ŀռ俴���ǡ����� ���Ŀռ䣬������Ŀռ���������Ž��ģ���㼰��Ŀռ仹��Ҫ���� 
		while(1){
			int childNum=ParentsTreeNum*2; 
			LinkBitNode **childTree=(LinkBitNode**)malloc(sizeof(LinkBitNode*)*childNum);
			int j;
			int NewParentsTree=0;
			for(j=0;j<childNum;j++){
				scanf("%c",&ch);
				if(ch!='#'){
					LinkBitNode *curchild=(LinkBitNode*)malloc(sizeof(LinkBitNode));
					childTree[NewParentsTree]=curchild;
					curchild->data=ch;
					curchild->lchild=nullptr;
					curchild->rchild=nullptr;
					NewParentsTree++;
					if(j%2==0){
						ParentsTree[j/2]->lchild=curchild; 
					}
					else{
						ParentsTree[j/2]->rchild=curchild;
					}
				}
			}
			free(ParentsTree);//���ͷſռ� 
			ParentsTree=childTree;//�����·���ռ估������ 
			ParentsTreeNum=NewParentsTree;//��������Ϊ���� 
			if(ParentsTreeNum==0)break;
		}
	}
	return Ok;
}

Status StackEmpty(SqStack S)
{
	if(S.base==S.top)return Ok;
	return !Ok;
}

Status GetTop(SqStack S,SElemType &e)
{
	if(S.base==S.top)return Error;
	e=S.top[-1];
	return Ok;
}

Status PreOrderTraverse(LinkBiTree T)
{
	//�öδ���Ϊ�γ������� 
//	
//	SqStack S;InitStack(S);													
//	Push(S,T);
//	while(!StackEmpty(S)){
//		if(T)//PrinfTop(S);
//		cout<<(*S.top)->data;
//	//	cout<<"here";
//		if(T->lchild){
//			T=T->lchild;
//			Push(S,T); 
//	//		cout<<"here";
//		}
//		else{
//			T=nullptr;
//			Pop(S,T);
//			T=T->rchild;
//		}
//	}
//	
	//
	
	/*
	SqStack S;InitStack(S);
	while(T||!StackEmpty(S)){
		while(T){
			cout<<T->data;
		//	PrinfTop(S);
		//	cout<<(*S.top)->data;
			Push(S,T);
			T=T->lchild;
		}
		if(!StackEmpty(S)){
			Pop(S,T);
			T=T->rchild;
		}
	}
	*/


	SqStack(S);InitStack(S);
	while(T||!StackEmpty(S)){
		while(T){
			printf("%c",T->data);
			Push(S,T);
			T=T->lchild;
		}
		if(!StackEmpty(S)){
			Pop(S,T);
			T=T->rchild;
		}
	}
	return Ok;

}

Status InOrderTraverse(LinkBiTree T)
{
	//�ҵ�������һ��ѭ����Ƕ��ѭ�������������� 
 
	SqStack(S);InitStack(S);
	while(T||!StackEmpty(S)){
		while(T){//һ��ֱ���ҵ������������������ǿ�ָ���˳�������Ӱ�������
					//��Ϊ�����е���ջ���¸�T��ֵ���ǿ�ָ���ʱ��û���õ��� 
			Push(S,T);
			T=T->lchild;
		}
		if(!StackEmpty(S)){
			Pop(S,T);
			printf("%c",T->data);
			T=T->rchild;
		}
	}
	
	// 
	//�α����� 
//	SqStack(S);InitStack(S);
//	while(T||!StackEmpty(S)){
//		if(T){
//			Push(S,T);
//			T=T->lchild;
//		}
//		else{
//			Pop(S,T);
//			printf("%c",T->data);
//			T=T->rchild;
//		}
//	} 
	return Ok;
}

Status PostOrderTraverse(LinkBiTree T)
{
	
	// �öδ���Ϊ�γ�������
//	SqStack(S);InitStack(S);
//	while(T||!StackEmpty(S)){
//		while(T){
//			Push(S,T);
//			T=T->lchild;
//		}
//		GetTop(S,T);
//		while(T){
//			T=T->rchild;
//			if(T)Push(S,T);
//		}
//		if(!StackEmpty(S)){
//			Pop(S,T);
//			printf("%c",T->data);
//		}
//	} 
//	
	
	// �öδ���Ϊ�γ�������	
//	SqStack(S);InitStack(S);
//	while(T||!StackEmpty(S)){
//	//	cout<<"here";
//		bool flag=true; 
//		if(T){
//			flag=!flag;
//			Push(S,T);T=T->lchild;
//		}
//		GetTop(S,T);T=T->rchild;
//		if(flag&&T){
//			Push(S,T);T=T->rchild;
//		}
//		else{
//	//		cout<<"here";
//			Pop(S,T);printf("%c",T->data);GetTop(S,T);T=T->rchild;
//		}
//	}
	
	
/*	˼·һ �ж�ÿ������Ƿ����γ�����ջ������Ϊ�ڶ��γ���ջ������� 
	SqStack2(S);InitStack2(S);
	LinkBiTree2 tmp;
	while(T&&StackEmpty2(S)){
		while(T){
			tmp=(LinkBitNode2*)malloc(sizeof(LinkBitNode2));
			tmp->T2=T;
			tmp->falg=true;
			Push2(S,tmp);T=T->lchild;
		}
		if(!StackEmpty2(S)){
			GetTop2(S,tmp);
			if(cur->falg){
				tmp->falg=false;T=tmp->T2->rchild;
			}
			else{
				Pop2(S,tmp);
				printf("%c",tmp->T2->data);
				tmp->T2=nullptr;
			}
		}
	}
*/

//˼·�� �жϽ���Ƿ������������������������Ƿ��ѱ����� 
	SqStack S;InitStack(S);
	Push(S,T);
	LinkBiTree pre=nullptr; 
//	while(T||!StackEmpty(S)){ ���Ǵ�����ж�������������ע�⣡��һ��û�� ��T�Ƿ�Ϊ�桱��һ������
//								������һ�ε�����ÿ��ѭ������������(T||!StackEmpty(S)_) 
//								��Ϊ�ڸ�˼·�£���δ��ʼ�ж��������Ѿ�ѹ��һ������ˣ�
//								��������Ϊ�棡  
	while(!StackEmpty(S)){//���Ǹ�˼·����ȷ�ж����� 
		GetTop(S,T);
		if(!T->lchild&&!T->rchild||pre&&(pre==T->lchild||pre==T->rchild)){
			Pop(S,T);printf("%c",T->data);pre=T;
		}
		else{
			if(T->rchild)Push(S,T->rchild);
			if(T->lchild)Push(S,T->lchild);
		}
	}
	return Ok;
 } 

Status LevelOrderTraverse(LinkBiTree T)
{
	LinkQueue Q;InitQueue(Q);
	EnQueue(Q,T);
//	printf("here");
//	printf("QueueEmpty(Q)=%d",QueueEmpty(Q));
	while(!QueueEmpty(Q)){
//		printf("here");
		DeQueue(Q,T);
		if(T->lchild)EnQueue(Q,T->lchild);
		if(T->rchild)EnQueue(Q,T->rchild);
		printf("%c",T->data);
	}
	return Ok;
}

int StackDepth(SqStack S)
{
	if(S.base==S.top)exit(Overflow);
	int Depth=S.top-S.base;
	return Depth;
}

int DeepLinkBiTree(LinkBiTree T)
{//���ú��������ջ�����ʵ�� 
//	int cnt=0;
//	while(T){
//		cnt++;
//		T=T->lchild;
//	}
//	return cnt;

	//�����ƺ������˵�С���⣬���顣 
//	SqStack(S);InitStack(S);
	int Depth=0;
	int MaxDepth=1;
//	Push(S,T);
//	LinkBiTree pre=nullptr;
//	while(!StackEmpty(S)){
//		GetTop(S,T);
//		if(!T->lchild&&!T->rchild||pre&&(pre==T->lchild||pre==T->rchild)){
//			if(!T->lchild&&!T->rchild)Depth=StackDepth(S);
//			Pop(S,T);
//			pre=T;
//			if(Depth>MaxDepth)MaxDepth=Depth;
//		}
//		else{
//			if(T->rchild)Push(S,T->rchild);
//			if(T->lchild)Push(S,T->lchild);
//		}
//	}
//	return MaxDepth;
	//�ƺ����ö��У����򣩲�����ʵ�� 
//	SqStack(S);InitStack(S);
//	while(T||!StackEmpty(S)){
//		while(T){
//			Push(S,T);
//			T=T->lchild;
//		}
//		if(T->rchild){
//			
//		}
//	}
	LinkQueue(Q);InitQueue(Q);
	EnQueue(Q,T);
	while(!QueueEmpty(Q)){
		int len=QueueLength(Q);
		while(len--){
			DeQueue(Q,T);
			if(T->lchild)EnQueue(Q,T->lchild);
			if(T->rchild)EnQueue(Q,T->rchild);	
		}
		Depth++;
	}
	return Depth;
}

int LeafLinkBiTree(LinkBiTree T)
{
	SqStack(S);InitStack(S);
	int cnt=0;
	while(T||!StackEmpty(S)){
		while(T){
			Push(S,T);T=T->lchild;
		}
		if(!StackEmpty(S)){
			Pop(S,T);cnt++;
			T=T->rchild;
		}
	}
	return cnt;
}

Status ExchangeLinkBiTree(LinkBiTree &T)
{
	LinkBiTree p=T;
	LinkQueue(Q);InitQueue(Q);
	EnQueue(Q,p);
	while(!QueueEmpty(Q)){
	//	cout<<"here";
		DeQueue(Q,p);
		LinkBiTree tmp;
		tmp=p->lchild;p->lchild=p->rchild;p->rchild=tmp;
		if(p->lchild)EnQueue(Q,p->lchild);
		if(p->rchild)EnQueue(Q,p->rchild);
	}
	return Ok;
}

int main ()
{
	printf("����������"); 
	LinkBiTree T; 
	InitBiTree(T);
//	int cnt=0;
//	while(T){
//		cnt++;
//		cout<<T->data;
//		T=T->lchild; 
//		cout<<cnt<<endl;
//	}
	printf("�������������������\n");
	PreOrderTraverse(T);
	cout<<endl;
	printf("�������������������\n");
	InOrderTraverse(T);
	cout<<endl;
	printf("������ĺ�����������\n");
	PostOrderTraverse(T);
	cout<<endl;
	printf("������Ĳ�����������\n");
	LevelOrderTraverse(T);
	cout<<endl;
	printf("��������ȣ������Ϊ��%d\n",DeepLinkBiTree(T));
	printf("������Ҷ�ӽ��������Ҷ�ӽ����Ϊ��%d\n",LeafLinkBiTree(T));
	printf("������������������\n");
	ExchangeLinkBiTree(T);
	printf("������������������������������\n");
	PreOrderTraverse(T);
	cout<<endl;
	printf("��������������������������\n");
	InOrderTraverse(T);
	cout<<endl;
	printf("�������������ĺ�����������\n");
	PostOrderTraverse(T);
	cout<<endl;
	printf("�������������Ĳ�����������\n");
	LevelOrderTraverse(T);
	cout<<endl;
	return Ok;
 }
