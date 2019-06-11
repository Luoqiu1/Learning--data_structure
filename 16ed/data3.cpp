#include <iostream>
#define Ok 1
#define True 1
#define False 0
#define Error 0
#define MAXSIZE 20
typedef int Status;
typedef int KeyType;
typedef char InfoType;
typedef struct{
	KeyType key;
	InfoType *otherInfo=nullptr;
}RedType;
typedef struct{
	RedType r[MAXSIZE+1];
	int length;
}SqList;

Status InitList(SqList &L)
{
	L.length=0;
	return Ok;
}

Status CreateList(SqList &L,int n)
{
	printf("����%d��Ԫ�أ�\n",n); 
	for(int i=1;i<=n;++i){
		scanf("%d",&L.r[i].key);
		++L.length;
	}
	if(L.length==0)return Error;
	return Ok;
}

Status DispList(SqList L)
{
	if(L.length==0)return Error;
	for(int i=1;i<=L.length;++i){
		printf("%d ",L.r[i].key);
	}
	printf("\n");
	return Ok;
}

Status SelectSort(SqList &L,int n)
{
	for(int i=1;i<=n;++i){
		int min=0x3f3f3f3f;
		int loc;
		for(int j=i;j<=n;++j){
			if(min>L.r[j].key){
				loc=j;min=L.r[j].key;
			}
		}
		//���ﲻ�����ư���Ҳ���ǣ��ǲ�����Ч��
		//��i==loc����û�ҵ�����ʱ��û�н����ı�Ҫ�ˣ�
		//��ѡ�������ǲ��ȶ��ģ� ���� 8 5 8 7 9 ������ѭ����ǰ��8��������Դ���! 
		if(i!=loc){
		 
			L.r[0]=L.r[i];
			L.r[i]=L.r[loc];
			L.r[loc]=L.r[0];
		} 
	}
	return Ok;
}

int main ()
{
	SqList L;
	int n;
	printf("��ʼ��˳���");
	InitList(L);
	if(L.length==0)printf("˳���Ϊ�գ�\n");
	printf("����˳����Ԫ�ظ�����");
	scanf("%d",&n);
	CreateList(L,n);
	printf("���%d��Ԫ�ص�˳������£�\n",n);
	DispList(L);
	SelectSort(L,n);
	printf("��ѡ�����������£�\n");
	DispList(L); 
	return 0;
}
