typedef int KeyType;
typedef struct {
	KeyType key;
	InfoType *otherinfo;
	
}RedType;
typedef struct{
	RedType r[MAXSIZE+1];
	int length;
}SqList; 

Status InsertSord(SqList &L)
{
	for(int i=2;i<=L.length;++i){
		if(L.r[i-1].key>L.r[i].key){
			L.r[0]=L.r[i];
			L.r[i]=L.r[i-1];
			for(int j=i-2;L.r[j].key>L.r[0].key;--j){
				L.r[j+1]=L.r[j];
			}
			L.r[j+1]=L.r[0];
		}
	}
}

Status InsertSort(SqList &L)
{
	for(int i=2;i<=L.length;++i){
		if(L.r[i].key<L.r[i-1].key){//如果i小于i-1，即这个元素小于其上一个元素，则需要重新排序！
			L.r[0]=L.r[i];
			L.r[i]=L.r[i-1];
			for(int j=i-2;L.r[j].key>L.r[0].key;--j){//如果当前索引下，即坐标j下的元素大于记录坐标值，则未找到位置！
													//因为记录值是要放在j+1下的，必须放在一个比它小的数后！
													//则需要找到j元素值小于r[0]的！ 
				L.r[j+1]=L.r[j];
			}
			L.r[j+1]=L.r[0];
		}
	}
 } 










