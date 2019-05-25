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
	printf("输入%d个元素：\n",n); 
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
	for(int j=2*s;j<=m;++j){
		if(j<m&&L.r[j].key<L.r[j+1].key)++j;
		if(rc.key>L.r[j].key)break;
		L.r[s]=L.r[j];
		s=j;
	}
	L.r[s]=rc;
}

Status HeapSort(SqList &L,int s,int m)
{
	for(int i=m/2;i>=1;--i){
		HeapAdjust(L,i,m);
	}
	for(int i=1;i<=m;++i){
		printf("%d ",L.r[1].key);
		RedType tmp=L.r[1];
		L.r[1]=L.r[i];
		L.r[i]=tmp;
		HeapAdjust(L,1,i-1);
	}
}

int main ()
{
	SqList L;
	int n;
	printf("初始化顺序表，");
	InitList(L);
	if(L.length==0)printf("顺序表为空！\n");
	printf("输入顺序表的元素个数：");
	scanf("%d",&n);
	CreateList(L,n);
	printf("输出%d个元素的顺序表如下：\n",n);
	DispList(L);
	printf("简单选择排序结果如下：\n");
	HeapSort(L,1,n);
	return 0;
}
