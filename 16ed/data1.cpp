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
		//	L.r[i].key=L.r[i-1].key;      //这些注释的几行，没有弄清楚交换的条件以及实质！
									//if条件中比较的是关键字大小，通过关键字来排序数据！
									//而不是只是去交换关键字数据！
									//是通过关键字，将整块数据域交换！
					
			L.r[0]=L.r[i];
			L.r[i]=L.r[i-1];		//这样才对！ 
					 
			int j;
		//	for(j=i-2;L.r[j].key<L.r[0].key;--j){
								//要保证稳定性！相等时，后面的数据仍在后面！
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
