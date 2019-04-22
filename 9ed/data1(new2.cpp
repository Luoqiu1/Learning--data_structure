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

//void CreateBiThrTree(BiThrTree &T){
//    char data;
//    cin>>data;
//    if(data=='#') T=NULL;
//    else{
//    	T=(BiThrNode *)malloc(sizeof(BiThrNode));
//		T->data=data;
//    	T->LTag=Link;
//    	T->RTag=Link;
//    	//printf("here\n");
//    	CreateBiThrTree(T->lchild);
//    	CreateBiThrTree(T->rchild);
//	}
//}

//void CreateBiThrTree(BiThrTree * tree){
//    char data;
//    scanf("%c",&data);
//    if (data!='#'){
//        if (!((*tree)=(BiThrNode*)malloc(sizeof(BiThrNode)))){
//            printf("������ռ�ʧ��");
//            return;
//        }else{
//            (*tree)->data=data;//����ǰ�������ʽ��ʼ��������
//      //      (*tree)->LTag=Link;(*tree)->RTag=Link; 
//            CreateBiThrTree(&((*tree)->lchild));//��ʼ��������
//            CreateBiThrTree(&((*tree)->rchild));//��ʼ��������
//        }
//    }else{
//        *tree=NULL;
//    }
//}

void InThreading(BiThrTree p)
{
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
	Thrt->LTag=Link;Thrt->RTag=Thread;
	Thrt->rchild=Thrt;
	if(!T)Thrt->lchild=Thrt;
	else{
		Thrt->lchild=T;
		pre=Thrt;
		InThreading(T);
		pre->rchild=Thrt;pre->RTag=Thread;
		Thrt->rchild=pre;
	}
}

Status InOrderTraverse_Thr(BiThrTree T)
{
	BiThrTree p=T->lchild;
	while(p!=T){
		while(p->LTag==Link){
			p=p->lchild;
		}
		cout<<p->data;
		while(p->RTag==Thread&&p->rchild!=T){
		p=p->rchild;cout<<p->data;
		}
		p=p->rchild;
	}

//	while(T){
//		while(T->LTag==Link)T=T->lchild;
//		cout<<T->data;
//		while(T->RTag==Thread&&T->rchild){
//			T=T->rchild;
//			cout<<T->data;
//		}
//		T=T->rchild;
//	}
	return Ok;
}

void PreThreading(BiThrTree p)
{
	if(p){
			//	cout<<"here3";
		
//		if(p->data=='5'){
//			printf("pre:%c ,preRTag:%d pre->data:%c",pre->data,pre->RTag,pre->rchild->data);
//			
//		}
		BiThrTree four=(BiThrTree)0x4ac030;
		printf("  %c  %d  ",p->data,four->RTag);
		if(pre->data=='4'){
			printf("p:%c preThr:%d \n",p->data,pre->RTag);
		//	cout<<&pre<<endl;
		}
		if(p->data=='4'){
			printf("p:%c pThr:%d \n",p->data,p->RTag);
		}
			
		if(!p->lchild){
			p->lchild=pre;p->LTag=Thread;
		}
		if(!pre->rchild){
				if(pre->data=='4'){
					cout<<"here";cout<<pre->RTag;
				}
			pre->rchild=p;pre->RTag=Thread;
		}
		pre=p;
		if(p->LTag==Link)PreThreading(p->lchild);
	//	if(!p->rchild)p->RTag=Thread;
		if(p->RTag==Link)PreThreading(p->rchild);
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
	BiThrTree p=T->lchild;cout<<p->data;
	while(p!=T){
		int cnt=0;
		while(p->LTag==Link){
			cnt++;
	//	p=p->lchild;cout<<p->data;
	//	cout<<"here1"<<endl;
		}
	//	cout<<' '<<cnt<<' ';
//		while(p->RTag==Thread&&p->rchild!=T){
//			p=p->rchild;cout<<p->data;
//		}
	//	cout<<"here32413"<<endl;
	//	cout<<p->data; 
	//	if(p->data=='4')cout<<p->rchild->data; 
		p=p->rchild;
	}
}

int main ()
{
	BiThrTree T,ThrtIn,ThrtPre,ThrtPost;
	printf("���򴴽����������������ֵ��\n");
	CreateBiThrTree(T);
	printf("�������������������������������");
	InOrderThreading(T,ThrtIn);
	InOrderTraverse_Thr(ThrtIn);cout<<endl;
	printf("ǰ�����������������������������");
	PreOrderThreading(T,ThrtPre);
	PreOrderTraverse_Thr(ThrtPre);cout<<endl;
//	printf("�������������������������������");
//	PostOrderThreading(T,ThrtPost);
//	PostOrderTraverse_Thr(ThrtPost);cout<<endl;
	return 0; 
}
