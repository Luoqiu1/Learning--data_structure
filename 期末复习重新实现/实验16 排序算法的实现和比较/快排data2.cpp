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
		//��Ҫ���Ȼ�׼С�ķ��ڻ�׼ǰ�棡�����ҵ�С��pivot����L.r[0].key���������ڲ��ܻ���
		while(L.r[hign].key>=L.r[0].key&&low<high)--high; //δ�ҵ����Լ��� 
		L.r[low]=L.r[high];
	//	while(L.r[low].key<L.r[0].key&&low<high)++low;
		while(L.r[low].key<=L.r[0].key&&low<hign)++low;//δ�ҵ��������� 
		L.r[high]=L.r[low];
		
		//��ʵΪʲôҪ���ó����ж϶�high�������ٶ�low��������ԭ��ģ�
		//��Ϊ���ǽ�����L.r[0]�ȴ洢��L.r[low](��ʼlow)�������Ȳ���high��������L.r[high].key<pivot��Ԫ�ػ�������
		//��ʡ�˿ռ䣡 
		
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
