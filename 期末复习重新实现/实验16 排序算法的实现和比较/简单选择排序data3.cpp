typedef int KeyType;
typedef struct {
	KeyType key;
	InfoType *otherinfo;
	
}RedType;
typedef struct{
	RedType r[MAXSIZE+1];
	int length;
}SqList;

Status SelectSort(SqList &L)
{
	for(int i=1;i<=L.length;++i){
		int min=0x3f3f3f3f;
		int k;
		for(j=i;j<=L.length;++j){
			if(L.r[j].key<min){
				k=j;min=L.r[j].key;
			}
		}
		if(k!=i){
			L.r[0]=L.r[k];
			L.r[k]=L.r[i];
			L.r[i]=L.r[0];
		}
	}
 } 
