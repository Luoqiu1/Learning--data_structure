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
			L.r[0].key=L.r[i].key;
			L.r[i].key=L.r[i-1].key;
			int j;
			for(j=i-2;L.r[j].key<L.r[0].key;--j){
				L.r[j+1].key=L.r[j].key;
			}
			L.r[j+1].key=L.r[0].key;
		}
	}
	return Ok;
}

int main ()
{
	return 0;
}
