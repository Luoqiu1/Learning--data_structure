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
	InfoType *otherInfo;
}RedType;
typedef struct{
	RedType r[MAXSIZE+1];
	int length;
}SqList;

Status InsertSort(SqList &L)
{
	for(int i=2;i<=L.length;++i){
		if(L.r[i].key<L.r[i-1].key){
		//	L.r[0].key=L.r[i].key;
		//	L.r[i].key=L.r[i-1].key;      //��Щע�͵ļ��У�û��Ū��������������Լ�ʵ�ʣ�
									//if�����бȽϵ��ǹؼ��ִ�С��ͨ���ؼ������������ݣ�
									//������ֻ��ȥ�����ؼ������ݣ�
									//��ͨ���ؼ��֣������������򽻻���
					
			L.r[0]=L.r[i];
			L.r[i]=L.r[i-1];		//�����Ŷԣ� 
					 
			int j;
		//	for(j=i-2;L.r[j].key<L.r[0].key;--j){
								//Ҫ��֤�ȶ��ԣ����ʱ��������������ں��棡
			for(j=i-2;L.r[j].key<=L.r[0].key;--j){
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
	return 0;
}
