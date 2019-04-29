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
typedef struct LinkQueue{//头结点。存放了队头指针和队尾指针。 
						//    Q.front  是头结点，注意！Q.front没有存储第一个数据！ 
	Queueptr rear,front;
}LinkQueue;

int QueueLength(LinkQueue Q)
{
	if(Q.front==Q.rear)return Error;
//	return Q.front-Q.rear;  //错！不是顺序存储结构的队列！
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
	Q.front->next=Q.front->next->next;//这样的话原来的 Q.front->next 结点丢失且未释放！
									//之后想找到丢失的结点已经做不到了，无法释放其空间，造成了浪费！
									//故应在丢失这个结点之前标记其位置，丢失之后释放其空间！ 
									
//	if(Q.front->next==Q.rear){			//不对！想找的是队列只有一个结点的那种情况。
									//若此时是该情况，则现在的Q.front==nullptr了！
									//因为之前的Q.front->next已指向了队尾指针
									// Q.front->next=Q.front->next->next;这条语句让 Q.front==nullptr了！
									//故上设的p指针还有这一作用，判断是否空列，让头指针尾指针相等！
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
//	while(p!=T||!StackEmpty(S)){ //p!=T这一条件会使在还没建立T的右子树前便结束。。
								//因为 push 结点是在进入条件之后，就算右子树不等于 '#' 
								//在进入右子树前 栈是空的 且 p==T !
								//再思考一下！ 
								
//	while(p||!StackEmpty(S)){ //这样又会造成死循环。。！p恒不为0 
	//故想在一个大while循环中实现根结点的左右树同时构建，稍有难度（或者说我还没有找到实现的方法） 
	//不如分别构建根结点的左子树和右子树。第二次遍历到根结点的时候特判是否有左子树！ 
	//第二次遍历到根结点的特征是：   栈为空 ！
	 
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
	} //上一段是构建根结点的左子树
	//下一段先特判有无右子树，有再ctrl+c v 代码即可。 
	bool rightTree=true;
	if(StackEmpty(S)){ //！！！干脆特判！ 对根节点是否有右子树特判
								//第二次访问根节点的时候，栈是空的！
								//设置该条件便避免了第一次刚进入根结点进行创建的情况！ 
			if(scanf("%c",&ch)&&ch!='#'||ch==13){
				CSTree cur=(CSNode*)malloc(sizeof(CSNode));
				cur->data=ch;cur->firstchild=nullptr;cur->nextsibling=nullptr;
				Push(S,cur);
				T->nextsibling=cur;
				p=cur;
			}
			else rightTree=false;//如果无右子树，打破。 
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

	//用先根栈输入似乎实现层序遍历比较困难。。直接用另一个程序吧 
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
			if(T->nextsibling!=pre)Depth--;//是否要减深度只需要判断上一个访问的结点
											//与当前Pop出来的结点是否为兄弟关系！ 
			T=T->nextsibling;
		}
	}
	return maxDepth;
}

int main()
{
	CSTree T;
	printf("请输入结点的值，进行先根构造树：");
	CreatCSTree(T);
	printf("先根遍历树："); 
	PreOrderCSTree(T);cout<<endl;
	printf("后根遍历树：");
	PostOrderCSTree(T);cout<<endl;
	printf("输出树的深度：%d",DepthCSTree(T));
	cout<<endl;
	return 0;
}


















