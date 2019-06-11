typedef int KeyType;
typedef struct {
	KeyType key;
	InfoType *otherinfo;
	
}RedType;
typedef struct{
	RedType r[MAXSIZE+1];
	int length;
}SqList;

int Partition(SqList &L,int low,int high)
{
	L.r[0]=L.r[low];
	while(low<high){
	//	while(L.r[high].key>L.r[0].key&&low<high)--high;
		//需要将比基准小的放在基准前面！必须找到小于pivot，即L.r[0].key的数！等于不能换！
		while(L.r[hign].key>=L.r[0].key&&low<high)--high; //未找到，自减！ 
		L.r[low]=L.r[high];
	//	while(L.r[low].key<L.r[0].key&&low<high)++low;
		while(L.r[low].key<=L.r[0].key&&low<hign)++low;//未找到，自增！ 
		L.r[high]=L.r[low];
		
		//其实为什么要设置成先判断对high操作，再对low操作是有原因的！
		//因为我们借助了L.r[0]先存储了L.r[low](初始low)，所以先操作high，将满足L.r[high].key<pivot的元素换过来！
		//节省了空间！ 
		
	}
	L.r[low]=L.r[0];
	return low;
}

Status QSort(SqList &L,int low,int high)
{
	if(low<high){
		int pivotloc=Partition(L,low,high);
		QSort(L,low,pivotloc-1);
		QSort(L,pivotloc+1,high);
	}
	return Ok;
 } 
