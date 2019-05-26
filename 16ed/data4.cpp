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
//	for(int j=2*s;j<=m;++j){
	for(int j=2*s;j<=m;j*=2){	//这里要仔细！！！每次j是指向j的子树！
												//通常是左子树！
								//若只是++j 则会指向j的右兄弟了！
								 
		if(j<m&&L.r[j].key<L.r[j+1].key)++j;//注意是比较j和j+1 ！不是s和j+1！ 
		if(rc.key>L.r[j].key)break;//因为对无序堆的排序是从最下往上排的，必然保证了
		//右边解释不全对！其实是因为一开始用rc做比较
		//rc是一开始对无序序列建立成大顶堆后
		//将最大元素跟最靠后的元素（已经很小了，第一或者第二小！）
		//若找j坐标，已经找到了比这个rc已经很小的数还小的位置！
		//则可以停止了！因为j之后的数必然又比j小！
		//这是由对无序堆排列成大顶堆之后所形成的特征！									
											//必然保证了当找到了一个j小于rc的关键字的时候可以结束循环！
											//一两句说不清楚，再加强理解！ 
											//简单理解就是 从局部到整体 的思想！
											//从最开始的小局部每一个都满足
											//则整体满足！ 
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
	for(int i=L.length;i>1;--i){ //此处的i要联系下文循环体理解！。 
		printf("%d ",L.r[1].key);
		RedType tmp=L.r[1];
		L.r[1]=L.r[i];
		L.r[i]=tmp;
		HeapAdjust(L,1,i-1);//将 L.r[1...i-1]重新调整为大顶堆！... 
	}
	printf("%d",L.r[1].key);//最后一次只剩一个根结点了，此时尚未输出！(输出是在每一次重新调整为大顶堆前
																			//故遗留了最后一次！ 
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
	printf("堆排序结果如下：\n");
	HeapSort(L);
	return 0;
}
