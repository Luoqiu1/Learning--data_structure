#include <bits/stdc++.h>
using namespace std;
#define Ok 1
#define Error 0
#define Overflow -2
#define True 1
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int Status;
typedef char ElemType;
typedef struct CSNode{
	ElemType data;
	struct CSNode *firstchild,*nextsibling;
}CSNode,*CSTree;
typedef CSTree SElemType;
typedef CSTree QElemType;
typedef struct SqStack{
	SElemType *top,*base;
	int stacksize;
}SqStack;
typedef struct QNode{
	QElemType data;
	struct QNode *next;
}QNode,*Queueptr;
typedef struct LinkQueue{//ͷ��㡣����˶�ͷָ��Ͷ�βָ�롣 
						//    Q.front  ��ͷ��㣬ע�⣡Q.frontû�д洢��һ�����ݣ� 
	Queueptr rear,front;
}LinkQueue;

int QueueLength(LinkQueue Q)
{
	if(Q.front==Q.rear)return Error;
//	return Q.front-Q.rear;  //������˳��洢�ṹ�Ķ��У�
	Queueptr p=Q.front;
	int Length=0;
	while(p!=Q.rear){
		Length++;p=p->next;
	}
	return Length;
}

Status InitQueue(LinkQueue &Q)
{
	Q.front=(QNode*)malloc(sizeof(QNode));
	if(!Q.front)exit(Overflow);
	Q.rear=Q.front;
	Q.front->next=nullptr;
	return Ok; 
}

int QueueEmpty(LinkQueue Q)
{
	if(Q.front==Q.rear)return True;
	return !True;
}

Status GetHead(LinkQueue Q,QElemType &e)
{
	if(Q.front==Q.rear)return Error;
	e=Q.front->next->data;
	return Ok;
}

Status DeQueue(LinkQueue &Q,QElemType &e)
{
	if(Q.front==Q.rear)return Error;
	e=Q.front->next->data;
	Queueptr p=Q.front->next; 
	Q.front->next=Q.front->next->next;//�����Ļ�ԭ���� Q.front->next ��㶪ʧ��δ�ͷţ�
									//֮�����ҵ���ʧ�Ľ���Ѿ��������ˣ��޷��ͷ���ռ䣬������˷ѣ�
									//��Ӧ�ڶ�ʧ������֮ǰ�����λ�ã���ʧ֮���ͷ���ռ䣡 
									
//	if(Q.front->next==Q.rear){			//���ԣ����ҵ��Ƕ���ֻ��һ���������������
									//����ʱ�Ǹ�����������ڵ�Q.front==nullptr�ˣ�
									//��Ϊ֮ǰ��Q.front->next��ָ���˶�βָ��
									// Q.front->next=Q.front->next->next;��������� Q.front==nullptr�ˣ�
									//�������pָ�뻹����һ���ã��ж��Ƿ���У���ͷָ��βָ����ȣ�
	if(p==Q.rear){
		Q.front=Q.rear;
	//	Q.front->next=nullptr;
	}
	free(p);
	return Ok;
}

Status EnQueue(LinkQueue &Q,QElemType e)
{
	Q.rear->next=(QNode*)malloc(sizeof(QNode));if(!Q.rear->next)exit(Overflow);
	Q.rear=Q.rear->next;Q.rear->data=e;Q.rear->next=nullptr;
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

Status CreatCSTree(CSTree &T)
{
	SqStack S;InitStack(S);
	char ch;scanf("%c",&ch);
	if(ch=='#')return Error;
	else{
		T=(CSNode*)malloc(sizeof(CSNode));if(!T)exit(Overflow);
		T->data=ch;T->firstchild=nullptr;T->nextsibling=nullptr;
		Push(S,T);
	}
	CSTree p=T;
//	while(p!=T||!StackEmpty(S)){ //p!=T��һ������ʹ�ڻ�û����T��������ǰ���������
								//��Ϊ push ������ڽ�������֮�󣬾��������������� '#' 
								//�ڽ���������ǰ ջ�ǿյ� �� p==T !
								//��˼��һ�£� 
								
//	while(p||!StackEmpty(S)){ //�����ֻ������ѭ��������p�㲻Ϊ0 
	//������һ����whileѭ����ʵ�ָ�����������ͬʱ�����������Ѷȣ�����˵�һ�û���ҵ�ʵ�ֵķ����� 
	//����ֱ𹹽������������������������ڶ��α�����������ʱ�������Ƿ����������� 
	//�ڶ��α����������������ǣ�   ջΪ�� ��
	 
	while(!StackEmpty(S)){
		while(scanf("%c",&ch)&&ch!='#'){
			CSTree cur=(CSNode*)malloc(sizeof(CSNode));
			cur->data=ch;cur->firstchild=nullptr;cur->nextsibling=nullptr;
			Push(S,cur);
			if(!p->firstchild)p->firstchild=cur;
			else if(!p->nextsibling)p->nextsibling=cur;
			p=cur;
		}
		if(!StackEmpty(S)){
			Pop(S,p);
			if(scanf("%c",&ch)&&ch!='#'){
				CSTree cur=(CSNode*)malloc(sizeof(CSNode));
				cur->data=ch;cur->firstchild=nullptr;cur->nextsibling=nullptr;
				Push(S,cur);
				p->nextsibling=cur;
				p=cur;
			}
			else if(!StackEmpty(S))Pop(S,p);
		}
	} //��һ���ǹ���������������
	//��һ������������������������ctrl+c v ���뼴�ɡ� 
	bool rightTree=true;
	if(StackEmpty(S)){ //�������ɴ����У� �Ը��ڵ��Ƿ�������������
								//�ڶ��η��ʸ��ڵ��ʱ��ջ�ǿյģ�
								//���ø�����������˵�һ�θս���������д���������� 
			if(scanf("%c",&ch)&&ch!='#'||ch==13){
				CSTree cur=(CSNode*)malloc(sizeof(CSNode));
				cur->data=ch;cur->firstchild=nullptr;cur->nextsibling=nullptr;
				Push(S,cur);
				T->nextsibling=cur;
				p=cur;
			}
			else rightTree=false;//����������������ơ� 
	}
	while(rightTree&&!StackEmpty(S)){
		while(scanf("%c",&ch)&&ch!='#'){
			CSTree cur=(CSNode*)malloc(sizeof(CSNode));
			cur->data=ch;cur->firstchild=nullptr;cur->nextsibling=nullptr;
			Push(S,cur);
			if(!p->firstchild)p->firstchild=cur;
			else if(!p->nextsibling)p->nextsibling=cur;
			p=cur;
		}
		if(!StackEmpty(S)){
			Pop(S,p);
			if(scanf("%c",&ch)&&ch!='#'){
				CSTree cur=(CSNode*)malloc(sizeof(CSNode));
				cur->data=ch;cur->firstchild=nullptr;cur->nextsibling=nullptr;
				Push(S,cur);
				p->nextsibling=cur;
				p=cur;
			}
			else if(!StackEmpty(S))Pop(S,p);
		}
	}
}

Status PreOrderCSTree(CSTree T)
{
	SqStack S;InitStack(S);
	while(T||!StackEmpty(S)){
		while(T){
			cout<<T->data;Push(S,T);
			T=T->firstchild;
		}
		if(!StackEmpty(S)){
			Pop(S,T);
			T=T->nextsibling;
		}
	}
	return Ok;
 }
 
Status PostOrderCSTree(CSTree T)
{
	SqStack S;InitStack(S);
	while(T||!StackEmpty(S)){
		while(T){
			Push(S,T);T=T->firstchild;
		}
		if(!StackEmpty(S)){
			Pop(S,T);cout<<T->data;
			T=T->nextsibling;
		}
	}
	return Ok;
}

	//���ȸ�ջ�����ƺ�ʵ�ֲ�������Ƚ����ѡ���ֱ������һ������� 
//Status LevelOrderCSTree(CSTree T)  
//{
//	LinkQueue Q;InitQueue(Q);
//	EnQueue(Q,T);
//	while(!QueueEmpty(Q)){
//		int len=QueueLength(Q);
//	//	DeQueue(Q,T);
//	//	GetHead(Q,T);
//		while(len--){
//			GetHead(Q,T); 
//			while(T->nextsibling){
//				T=T->nextsibling;EnQueue(Q,T);
//			}
//			if(T->firstchild){
//				T=T->firstchild;EnQueue(Q,T);
//			}
//			DeQueue(Q,T);
//		}
//	}
//}

int DepthCSTree(CSTree T)
{
	SqStack S;InitStack(S);
	int Depth=0,maxDepth=0;
	CSTree pre=T;
	while(T||!StackEmpty(S)){
		while(T){
			Push(S,T);
			pre=T;
			T=T->firstchild;
			Depth++;
		//	if(T)pre=T;
		}
		if(maxDepth<Depth)maxDepth=Depth;
		if(!StackEmpty(S)){
			Pop(S,T);
		//	if(maxDepth<Depth)maxDepth=Depth;
			if(T->nextsibling!=pre)Depth--;//�Ƿ�Ҫ�����ֻ��Ҫ�ж���һ�����ʵĽ��
											//�뵱ǰPop�����Ľ���Ƿ�Ϊ�ֵܹ�ϵ�� 
			T=T->nextsibling;
		}
	}
	return maxDepth;
}

int main()
{
	CSTree T;
	printf("���������ֵ�������ȸ���������");
	CreatCSTree(T);
	printf("�ȸ���������"); 
	PreOrderCSTree(T);cout<<endl;
	printf("�����������");
	PostOrderCSTree(T);cout<<endl;
	printf("���������ȣ�%d",DepthCSTree(T));
	cout<<endl;
	return 0;
}


















