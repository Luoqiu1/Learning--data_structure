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

Status HeapAdjust(SqList &L,int s,int m)
{
	RedType rc=L.r[s];
//	for(int j=2*s;j<=m;++j){
	for(int j=2*s;j<=m;j*=2){	//����Ҫ��ϸ������ÿ��j��ָ��j��������
												//ͨ������������
								//��ֻ��++j ���ָ��j�����ֵ��ˣ�
								 
		if(j<m&&L.r[j].key<L.r[j+1].key)++j;//ע���ǱȽ�j��j+1 ������s��j+1�� 
		if(rc.key>L.r[j].key)break;//��Ϊ������ѵ������Ǵ����������ŵģ���Ȼ��֤��
		//�ұ߽��Ͳ�ȫ�ԣ���ʵ����Ϊһ��ʼ��rc���Ƚ�
		//rc��һ��ʼ���������н����ɴ󶥶Ѻ�
		//�����Ԫ�ظ�����Ԫ�أ��Ѿ���С�ˣ���һ���ߵڶ�С����
		//����j���꣬�Ѿ��ҵ��˱����rc�Ѿ���С������С��λ�ã�
		//�����ֹͣ�ˣ���Ϊj֮�������Ȼ�ֱ�jС��
		//�����ɶ���������гɴ󶥶�֮�����γɵ�������									
											//��Ȼ��֤�˵��ҵ���һ��jС��rc�Ĺؼ��ֵ�ʱ����Խ���ѭ����
											//һ����˵��������ټ�ǿ��⣡ 
											//�������� �Ӿֲ������� ��˼�룡
											//���ʼ��С�ֲ�ÿһ��������
											//���������㣡 
		L.r[s]=L.r[j];
		s=j;
	}
	L.r[s]=rc;
	return Ok;
}

Status HeapSort(SqList &L)
{
	for(int i=L.length/2;i>0;--i){
		HeapAdjust(L,i,L.length);
	}
//	for(int i=1;i<=m;++i){
	for(int i=L.length;i>1;--i){ //�˴���iҪ��ϵ����ѭ������⣡�� 
		printf("%d ",L.r[1].key);
		RedType tmp=L.r[1];
		L.r[1]=L.r[i];
		L.r[i]=tmp;
		HeapAdjust(L,1,i-1);//�� L.r[1...i-1]���µ���Ϊ�󶥶ѣ�... 
	}
	printf("%d",L.r[1].key);//���һ��ֻʣһ��������ˣ���ʱ��δ�����(�������ÿһ�����µ���Ϊ�󶥶�ǰ
																			//�����������һ�Σ� 
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
	printf("�����������£�\n");
	HeapSort(L);
	return 0;
}
