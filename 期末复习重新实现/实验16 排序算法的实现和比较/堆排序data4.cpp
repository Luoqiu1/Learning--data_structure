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

Status HeapAdjust(SqList &L,int s,int m)
{
	RedType rc=L.r[s];
	for(int j=2*s;j<=m;j*=2){
		if(j+1<=m&&L.r[j+1].key>L.r[j].key)++j;//左右子树看谁大 
		if(L.r[j].key<rc.key)break;//如果左右子树中大的都比rc.key小（即左右子树均小于rc.key），退出循环。父树大
		//这条语句配合下面，32行注释所释则非常地精髓！强。达到了类似pivot，基准的目的！ 
	
	
	//	L.r[0]=L.r[j];
	//	L.r[j]=L.r[j/2];//这三步是把小的父树换下去变成子树，子树升级为父树! 
	//	L.r[j/2]=L.r[j]; 		//我这三步似乎也没问题！但不够精髓！
								//题上设了 rc=L.r[s]，有点类似于之前的
								//在快排中，利用的L.r[0]来存放一个数据
								//达到节省空间的目的！
								//这里如是！ 
								//便不需要每次交换元素，这样可以省空间和时间！
								//交换元素需要三个语句！。
								
								//这样交换，必然可以保证起始的s到最下面（该到的位置）！因为左右子树是跟rc.key比较
								//而rc=L.r[s]（初始的s）!这便是开始设置RedType rc=L.r[s]的意义所在。	 
		L.r[s]=L.r[j];
		s=j;
	}
	L.r[s]=rc;
	return Ok; 
}

Status HeapSort(SqList &L)
{
//	for(int i=L.length/2;i>=0;--i){
	//这句有问题。。。因为这些记录都是从L.r[1]开始的！不是从L.r[0]开始！仔细了
	for(int i=L.length/2;i>=1;--i){
		HeapAdjust(L,i,L.length);
	}//无序堆初始为大顶堆成功！
	for(int j=L.length;j>=2;--j){
		L.r[0]=L.r[j];
		L.r[j]=L.r[1];
		L.r[1]=L.r[0];
		HeapAdjust(L,1,j-1);
	}
	return Ok;
 } 
