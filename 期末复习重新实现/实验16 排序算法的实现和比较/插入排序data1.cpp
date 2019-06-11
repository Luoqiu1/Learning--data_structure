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
		if(L.r[i].key<L.r[i-1].key){//���iС��i-1�������Ԫ��С������һ��Ԫ�أ�����Ҫ��������
			L.r[0]=L.r[i];
			L.r[i]=L.r[i-1];
			for(int j=i-2;L.r[j].key>L.r[0].key;--j){//�����ǰ�����£�������j�µ�Ԫ�ش��ڼ�¼����ֵ����δ�ҵ�λ�ã�
													//��Ϊ��¼ֵ��Ҫ����j+1�µģ��������һ������С������
													//����Ҫ�ҵ�jԪ��ֵС��r[0]�ģ� 
				L.r[j+1]=L.r[j];
			}
			L.r[j+1]=L.r[0];
		}
	}
 } 










