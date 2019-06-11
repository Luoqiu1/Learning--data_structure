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

Status InsertSort(SqList &L)
{
	for(int i=2;i<=L.length;++i){ 
		if(L.r[i].key<L.r[i-1].key){
		//	L.r[0].key=L.r[i].key;
		//	L.r[i].key=L.r[i-1].key;      //��Щע�͵ļ��У�û��Ū��������������Լ�ʵ�ʣ�
									//if�����бȽϵ��ǹؼ��ִ�С��ͨ���ؼ������������ݣ�
									//������ֻ��ȥ�����ؼ������ݣ�
									//��ͨ���ؼ��֣������������򽻻���
					
			L.r[0]=L.r[i];
			L.r[i]=L.r[i-1];		//�����Ŷԣ� 
					 
			int j;
		//	for(j=i-2;L.r[j].key<L.r[0].key;--j){
								//Ҫ��֤�ȶ��ԣ����ʱ��������������ں��棡
	//		for(j=i-2;L.r[j].key<=L.r[0].key;--j){//Ԫ�غ���һλ���� 
	
	//		for(j=i-2;j>=0&&L.r[j].key<=L.r[0].key;--j){
	
	 
//�������ٸ�			for(j=i-2;j>=0&&L.r[0].key<L.r[j].key;--j){//Ԫ�غ���һλ����
					//��ϸ���� �����ڱ���Ԫ��С������� �������ߣ�  ǰ�������ȫ���ˣ�����һ��Ҫ��ϸ�������� 
							//�Ѿ�����ʱҲҪ������Ϊ�˱�֤�ȶ��ԣ� 
													//����Ҫ��֤ j>=0!������ʲ�Խ�磡 
													
										//����������ע����⻹�ǲ���λ��
										//Ӧ���ǵ�j�ҵ������Ԫ�أ��ȼ�¼������Ԫ�ظ�С��ֹͣ��
										//����δ�ҵ��ͼ�������Ԫ�غ��ƣ�
										//��L.r[j].key>L.r[0].key ����ѭ������δ�ҵ�С��L.r[0].key��Ԫ��
										//��δ�ҵ�L.r[0].key�����ģ��ŵ��ĸ�λ�ã� 
										//ֱ���ҵ�������ȼ�¼Ԫ��С��Ԫ�أ��ٽ���Ԫ�ط��������棡
										//��д�����ǣ���j�ҵ���0λ��ʱ����Ȼ��ȣ�Ҫ���� 
										
			for(j=i-2;L.r[j].key>L.r[0].key;--j){
		//		L.r[j+1].key=L.r[j].key;
				L.r[j+1]=L.r[j];
			}
		//	L.r[j+1].key=L.r[0].key;
			L.r[j+1]=L.r[0];
		
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
	InsertSort(L);
	printf("ֱ�Ӳ������������£�\n");
	DispList(L); 
	return 0;
}
