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

Status InsertSort(SqList &L)
{
	for(int i=2;i<=L.length;++i){ 
		if(L.r[i].key<L.r[i-1].key){
		//	L.r[0].key=L.r[i].key;
		//	L.r[i].key=L.r[i-1].key;      //这些注释的几行，没有弄清楚交换的条件以及实质！
									//if条件中比较的是关键字大小，通过关键字来排序数据！
									//而不是只是去交换关键字数据！
									//是通过关键字，将整块数据域交换！
					
			L.r[0]=L.r[i];
			L.r[i]=L.r[i-1];		//这样才对！ 
					 
			int j;
		//	for(j=i-2;L.r[j].key<L.r[0].key;--j){
								//要保证稳定性！相等时，后面的数据仍在后面！
	//		for(j=i-2;L.r[j].key<=L.r[0].key;--j){//元素后移一位操作 
	
	//		for(j=i-2;j>=0&&L.r[j].key<=L.r[0].key;--j){
	
	 
//有问题再改			for(j=i-2;j>=0&&L.r[0].key<L.r[j].key;--j){//元素后移一位操作
					//仔细啊！ 是若哨兵单元还小于这个数 就往下走！  前面的条件全错了！！！一定要仔细。。。。 
							//已经等于时也要跳出！为了保证稳定性！ 
													//还需要保证 j>=0!数组访问不越界！ 
													
										//上面这三句注释理解还是不到位！
										//应该是当j找到了这个元素，比记录下来的元素更小则停止！
										//倘若未找到就继续将该元素后移！
										//即L.r[j].key>L.r[0].key 继续循环，还未找到小于L.r[0].key的元素
										//即未找到L.r[0].key放在哪，放到哪个位置！ 
										//直到找到了这个比记录元素小的元素，再将该元素放在它后面！
										//不写等于是，当j找到了0位置时，必然相等！要跳出 
										
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
	printf("初始化顺序表，");
	InitList(L);
	if(L.length==0)printf("顺序表为空！\n");
	printf("输入顺序表的元素个数：");
	scanf("%d",&n);
	CreateList(L,n);
	printf("输出%d个元素的顺序表如下：\n",n);
	DispList(L);
	InsertSort(L);
	printf("直接插入排序结果如下：\n");
	DispList(L); 
	return 0;
}
