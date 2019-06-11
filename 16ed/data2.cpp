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

int Partition(SqList &L,int low,int high)
{
	L.r[0]=L.r[low];
	while(low<high){    //������ˡ�������û�����ѭ������������ѭ��ֻ�����һ�Σ�
						//�����ŵ�������Ҫ�� low����high������ 
		while(low<high&&L.r[0].key<=L.r[high].key)--high;
		//������Ҫע�⣡������С�ڵ��ڣ���������ı����Ǵ��ڵ��ڣ�
		//��Ϊ��ȵ�����²���Ҫ������������Ҳ�ǰ׻�������ʵ���ϻᵼ�³������û����ȷ��Ҫ��
		//��λ�ã���С�Ļ���ǰ�棬����Ļ������棨���׼pivot��ȣ��� 
		L.r[low]=L.r[high];
		while(low<high&&L.r[0].key>=L.r[low].key)++low;
		L.r[high]=L.r[low];	
	}
	L.r[low]=L.r[0];
	return low;
}

Status QSort(SqList &L,int low,int high)
{
//	while(low<high){
	if(low<high){			//��ϸ������������while�ض�����ѭ����
							//��Ϊ�����ѭ������û�иı��ж�������low����high��ֵ���� 
		int pivotloc=Partition(L,low,high);
		QSort(L,low,pivotloc-1);
		QSort(L,pivotloc+1,high);
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
	QSort(L,1,n);
	printf("�������������£�\n");
	DispList(L); 
	return 0;
}
