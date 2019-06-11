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
		if(j+1<=m&&L.r[j+1].key>L.r[j].key)++j;//����������˭�� 
		if(L.r[j].key<rc.key)break;//������������д�Ķ���rc.keyС��������������С��rc.key�����˳�ѭ����������
		//�������������棬32��ע��������ǳ��ؾ��裡ǿ���ﵽ������pivot����׼��Ŀ�ģ� 
	
	
	//	L.r[0]=L.r[j];
	//	L.r[j]=L.r[j/2];//�������ǰ�С�ĸ�������ȥ�����������������Ϊ����! 
	//	L.r[j/2]=L.r[j]; 		//���������ƺ�Ҳû���⣡���������裡
								//�������� rc=L.r[s]���е�������֮ǰ��
								//�ڿ����У����õ�L.r[0]�����һ������
								//�ﵽ��ʡ�ռ��Ŀ�ģ�
								//�������ǣ� 
								//�㲻��Ҫÿ�ν���Ԫ�أ���������ʡ�ռ��ʱ�䣡
								//����Ԫ����Ҫ������䣡��
								
								//������������Ȼ���Ա�֤��ʼ��s�������棨�õ���λ�ã�����Ϊ���������Ǹ�rc.key�Ƚ�
								//��rc=L.r[s]����ʼ��s��!����ǿ�ʼ����RedType rc=L.r[s]���������ڡ�	 
		L.r[s]=L.r[j];
		s=j;
	}
	L.r[s]=rc;
	return Ok; 
}

Status HeapSort(SqList &L)
{
//	for(int i=L.length/2;i>=0;--i){
	//��������⡣������Ϊ��Щ��¼���Ǵ�L.r[1]��ʼ�ģ����Ǵ�L.r[0]��ʼ����ϸ��
	for(int i=L.length/2;i>=1;--i){
		HeapAdjust(L,i,L.length);
	}//����ѳ�ʼΪ�󶥶ѳɹ���
	for(int j=L.length;j>=2;--j){
		L.r[0]=L.r[j];
		L.r[j]=L.r[1];
		L.r[1]=L.r[0];
		HeapAdjust(L,1,j-1);
	}
	return Ok;
 } 
