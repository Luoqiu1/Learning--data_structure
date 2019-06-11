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
		//这里不够完善啊！也不是，是不够高效！
		//当i==loc，即没找到最大的时候，没有交换的必要了！
		//简单选择排序是不稳定的！ 例如 8 5 8 7 9 两次外循环后前后8交换了相对次序! 
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
	printf("初始化顺序表，");
	InitList(L);
	if(L.length==0)printf("顺序表为空！\n");
	printf("输入顺序表的元素个数：");
	scanf("%d",&n);
	CreateList(L,n);
	printf("输出%d个元素的顺序表如下：\n",n);
	DispList(L);
	SelectSort(L,n);
	printf("简单选择排序结果如下：\n");
	DispList(L); 
	return 0;
}
