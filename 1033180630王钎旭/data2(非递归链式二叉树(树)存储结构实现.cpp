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
	e=Q.front->next->data;//队列采取同线性表的单链表一样，为操作方便起见，
							//给链队列也添加一个头结点 Q.front ! 
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
{	//层序输入构建树（不仅限于度为二的二叉树）	例如要建立下图所示树，输入1#234#567###### 
	//														   1
	//												      #		    2
	//													       3        4 
	//														  #  5	  6    7 
	//														    #  # # #  # # 
	//过程通过线性表的链式存储结构实现
	//思路是先建立树的根结点，建立一个存放结点指针的指针空间（类似指针数组的功能，不同的是这里是动态的）
	//建立了根结点首先确立了第一个指针空间的大小。 
	//每次循环完一次（循环完一层）得到子树的个数，通过记录字数的个数来重新分配二重指针的空间。
	//下面的 j 标记着这在这一层中循环到了第几棵树（j=0表示第一颗树） 
	//通过j%2和j/2表示左右子树和其父树处于二重指针中的位置
	//结束后释放二重指针的空间，子树升级为父树重新分配二重指针的空间 
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
		ParentsTree[ParentsTreeNum-1]=T;//用来存储父亲结点指针,ParentsTree以及下面的childTree相当于指针数组 
		//申请了空间，可将申请的空间看作是“数组 ”的空间，即申请的空间是用来存放结点的，结点及其的空间还需要另设 
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
			free(ParentsTree);//先释放空间 
			ParentsTree=childTree;//再重新分配空间及其内容 
			ParentsTreeNum=NewParentsTree;//子树升级为父树 
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
	//该段代码为何出错再议 
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
	//我的做法，一次循环内嵌套循环遍历完左子树 
 
	SqStack(S);InitStack(S);
	while(T||!StackEmpty(S)){
		while(T){//一次直接找到左子树的最深处，最后是空指针退出，但不影响后续。
					//因为后续中弹出栈重新给T赋值，是空指针的时候没有用到！ 
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
	//课本做法 
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
	
	// 该段代码为何出错再议
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
	
	// 该段代码为何出错再议	
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
	
	
/*	思路一 判断每个结点是否两次出现于栈顶，若为第二次出现栈顶，输出 
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

//思路二 判断结点是否有左右子树或者左右子树是否已被访问 
	SqStack S;InitStack(S);
	Push(S,T);
	LinkBiTree pre=nullptr; 
//	while(T||!StackEmpty(S)){ ←是错误的判断条件！！尤其注意！这一次没有 “T是否为真”这一条件！
//								除了这一次的其他每次循环的条件都是(T||!StackEmpty(S)_) 
//								因为在该思路下，尚未开始判断条件就已经压入一个结点了！
//								该条件恒为真！  
	while(!StackEmpty(S)){//这是该思路的正确判断条件 
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
{//利用后序遍历和栈的深度实现 
//	int cnt=0;
//	while(T){
//		cnt++;
//		T=T->lchild;
//	}
//	return cnt;

	//后序似乎出现了点小问题，再议。 
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
	//似乎不用队列（层序）不方便实现 
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
	printf("请输入树："); 
	LinkBiTree T; 
	InitBiTree(T);
//	int cnt=0;
//	while(T){
//		cnt++;
//		cout<<T->data;
//		T=T->lchild; 
//		cout<<cnt<<endl;
//	}
	printf("输出树的先序遍历结果：\n");
	PreOrderTraverse(T);
	cout<<endl;
	printf("输出树的中序遍历结果：\n");
	InOrderTraverse(T);
	cout<<endl;
	printf("输出树的后序遍历结果：\n");
	PostOrderTraverse(T);
	cout<<endl;
	printf("输出树的层序遍历结果：\n");
	LevelOrderTraverse(T);
	cout<<endl;
	printf("求树的深度，其深度为：%d\n",DeepLinkBiTree(T));
	printf("求树的叶子结点数，其叶子结点数为：%d\n",LeafLinkBiTree(T));
	printf("交换树的左右子树。\n");
	ExchangeLinkBiTree(T);
	printf("输出子树交换后的树的先序遍历结果：\n");
	PreOrderTraverse(T);
	cout<<endl;
	printf("输出子树交换后的中序遍历结果：\n");
	InOrderTraverse(T);
	cout<<endl;
	printf("输出子树交换后的后序遍历结果：\n");
	PostOrderTraverse(T);
	cout<<endl;
	printf("输出子树交换后的层序遍历结果：\n");
	LevelOrderTraverse(T);
	cout<<endl;
	return Ok;
 }
