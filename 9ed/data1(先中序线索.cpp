#include <iostream>
using namespace std;
#define True 1
#define Error 0
#define Overflow -2
#define Ok 1
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef char TElemType;
typedef int Status;
typedef enum PointerTag{Link,Thread//Link==0��ָ�룬Thread==1������ 
}PointerTag;//����typedef�Ļ�ֱ�� enum PointerTag{Link,Thread};  
typedef struct BiThrNode{
	TElemType data;
	struct BiThrNode *lchild,*rchild;
	PointerTag LTag,RTag;
}BiThrNode,*BiThrTree;
BiThrTree pre=nullptr;

Status CreateBiThrTree(BiThrTree &T)
{
	T=(BiThrNode*)malloc(sizeof(BiThrNode));
	if(!T)exit(Overflow);
	char ch;scanf("%c",&ch);
	if(ch=='#')exit(Overflow);
	T->data=ch;T->lchild=nullptr;T->rchild=nullptr;T->LTag=Link;T->RTag=Link;//�տ�ʼ��ʼ����ʱ��
										//�ڴ���������������ʱ�򣬱�־�����ʼ��ΪLink�� 
	int FatherNum=1;
	BiThrNode **FatherTree=(BiThrNode**)malloc(sizeof(BiThrNode*)*FatherNum);
	FatherTree[0]=T;
	while(FatherNum){
		int ChildNum=FatherNum*2;
		BiThrNode **ChildTree=(BiThrNode**)malloc(sizeof(BiThrNode*)*ChildNum);
		int j=0;int NewChildNum=0;
		while(ChildNum--){
			scanf("%c",&ch);if(ch=='#')j++;
			else{
				BiThrTree q=(BiThrNode*)malloc(sizeof(BiThrNode));
				if(!q)exit(Overflow);
				q->data=ch;q->lchild=nullptr;q->rchild=nullptr;
q->LTag=Link;q->RTag=Link;  //������ϸ���������ٿ���Ϊʲô����������� 
				ChildTree[NewChildNum++]=q;
				if(j%2==0){//���� 
					FatherTree[j/2]->lchild=q;
				}
				else{
					FatherTree[j/2]->rchild=q;
				}
				j++;
			}
		}
		FatherNum=NewChildNum;
		free(FatherTree);
		FatherTree=ChildTree;
	}
}

void InThreading(BiThrTree p)
{//���������� 
	if(p){
		InThreading(p->lchild);
		if(!p->lchild){
			p->LTag=Thread;p->lchild=pre;
		}
		if(!pre->rchild){
			pre->RTag=Thread;pre->rchild=p;
		}
		pre=p;
		InThreading(p->rchild);
	}
}

Status InOrderThreading(BiThrTree T,BiThrTree &Thrt)
{
	Thrt=(BiThrNode*)malloc(sizeof(BiThrNode));if(!Thrt)exit(Overflow);
	Thrt->LTag=Link;  //ͷ��㡰����������Ӧ�ã��ǿ� 
	Thrt->RTag=Thread;//ͷ��㡰���������ݿ� 
	Thrt->rchild=Thrt;//��ָ�����Է�ֹ��������ʱ����ָ���׽�㣨�׽���ǵ�һ��������Ľ�㣬����ͷ��㣩 
	if(!T)Thrt->lchild=Thrt;
	else{
		Thrt->lchild=T;
		pre=Thrt;
		InThreading(T);
		pre->rchild=Thrt;pre->RTag=Thread;//���һ�����ָ��ͷ��� 
		Thrt->rchild=pre;
	}
}

Status InOrderTraverse_Thr(BiThrTree T)
{//������� 
	BiThrTree p=T->lchild;
	while(p!=T){
		while(p->LTag==Link){//���ʵ����������� 
			p=p->lchild;
		}
		cout<<p->data;//���������� 
		while(p->RTag==Thread&&p->rchild!=T){//�������ʺ�� 
		p=p->rchild;cout<<p->data;//ֱ�������� 
		}
		p=p->rchild;//1���������������룬������Ѱ����һ����������ĵ�һ����㡣 
					//2��p->rchild==T�����룬����ѭ�� 
	}
	return Ok;
}

void PreThreading(BiThrTree p)
{
	if(p){
		if(!p->lchild){//�������գ�ǰ�����ȷ�� 
			p->lchild=pre;p->LTag=Thread;
		}
		if(!pre->rchild){//��һ�����ʵĽ���������գ���̽��ȷ��Ϊ��ǰ��� 
			pre->rchild=p;pre->RTag=Thread;
		}
		pre=p;//���� 
		if(p->LTag==Link)PreThreading(p->lchild);//��ʵ����˵����ĳ��������
		if(p->RTag==Link)PreThreading(p->rchild);//p->L/R Tag==0(Link)��ʾ�� ��/�� �����ǿգ�
												 //Tag==1(Thread)�� �����ա����ÿ���ȥָ��ǰ������Ԫ�أ� 
	}
}

Status PreOrderThreading(BiThrTree T,BiThrTree &Thrt)
{
	Thrt=(BiThrNode*)malloc(sizeof(BiThrNode));if(!Thrt)exit(Overflow);
	Thrt->LTag=Link;Thrt->RTag=Thread;Thrt->rchild=Thrt;
	if(!T)Thrt->lchild=Thrt;
	else{
		Thrt->lchild=T;
		pre=Thrt;
		PreThreading(T);
		pre->rchild=Thrt;pre->RTag=Thread;
		Thrt->rchild=pre;
	}
	return Ok;
}

Status PreOrderTraverse_Thr(BiThrTree T)
{
	BiThrTree p=T->lchild;
	while(p!=T){
		cout<<p->data;
		while(p->LTag==Link){//�ҵ������½� 
		p=p->lchild;cout<<p->data;//���� ÿ��ֱ�ӷ��� 
		}//ѭ��������ʾ���������ˣ�Ҫ������һ�� 
//		while(p->RTag==Thread&&p->rchild!=T){
//			p=p->rchild;cout<<p->data;
//		}
//		cout<<p->data; 
		p=p->rchild;//�����Ǻ�̽�㻹������������p->rchild�С���ȥֱ�����������������ֱ������� 
	}
}

void PostThreading(BiThrTree p)
{
	if(p){
		if(p->LTag==Link)PostThreading(p->lchild);
		if(p->RTag==Link)PostThreading(p->rchild);
		if(!p->lchild){
			p->LTag=Thread;p->lchild=pre;
		}
		if(!pre->rchild){
			pre->RTag=Thread;pre->rchild=p;
		}
		pre=p;
	}
 } 

Status PostOrderThreading(BiThrTree T,BiThrTree Thrt)
{
	Thrt=(BiThrNode*)malloc(sizeof(BiThrNode));if(!Thrt)exit(Overflow);
	Thrt->LTag=Link;Thrt->RTag=Thread;Thrt->rchild=Thrt;
	if(!T)Thrt->lchild=Thrt;
	else{
		Thrt->lchild=T;
		pre=Thrt;
		PostThreading(T);
		pre->rchild=Thrt;pre->RTag=Thread;
		Thrt->rchild=pre;
	}
	return Ok;
}

Status PostOrderTraverse_Thr(BiThrTree T)
{
	BiThrTree p=T->lchild;
	while(p!=T){
		while(p->LTag==Link){
			p=p->lchild;
		}
		while(p->RTag==Link){
			p=p->rchild;
		}
		if(p->LTag==Thread&&p->RTag==Thread){
			cout<<p->data;p=p->rchild;
		}
		else{
		//	if(p->LTag==Link)p=p->lchild;
		}
	}
}

int main ()
{
	BiThrTree T,ThrtIn,ThrtPre,ThrtPost;
	printf("���򴴽����������������ֵ��\n");
	CreateBiThrTree(T);
//	printf("�������������������������������");
//	InOrderThreading(T,ThrtIn);
//	InOrderTraverse_Thr(ThrtIn);cout<<endl;
//	printf("ǰ�����������������������������");
//	PreOrderThreading(T,ThrtPre);
//	PreOrderTraverse_Thr(ThrtPre);cout<<endl;
	printf("�������������������������������");
	PostOrderThreading(T,ThrtPost);
	PostOrderTraverse_Thr(ThrtPost);cout<<endl;
	cout<<"here";
	return 0; 
}
