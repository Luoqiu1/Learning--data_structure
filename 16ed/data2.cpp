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

int Partition(SqList &L,int low,int high)
{
	L.r[0]=L.r[low];
	while(low<high){    //这别忘了。。。！没有这个循环，下面两个循环只会进行一次！
						//不会排到最终需要的 low等于high成立！ 
		while(low<high&&L.r[0].key<=L.r[high].key)--high;
		//这里需要注意！必须是小于等于，或者下面的必须是大于等于！
		//因为相等的情况下不需要交换！交换了也是白换，而且实际上会导致程序错误！没有正确按要求
		//换位置！将小的换到前面，将大的换到后面（与基准pivot相比！） 
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
	if(low<high){			//仔细啊！这里若用while必定是死循环！
							//因为在这个循环体内没有改变判断条件中low或者high的值！！ 
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
	printf("初始化顺序表，");
	InitList(L);
	if(L.length==0)printf("顺序表为空！\n");
	printf("输入顺序表的元素个数：");
	scanf("%d",&n);
	CreateList(L,n);
	printf("输出%d个元素的顺序表如下：\n",n);
	DispList(L);
	QSort(L,1,n);
	printf("快速排序结果如下：\n");
	DispList(L); 
	return 0;
}
