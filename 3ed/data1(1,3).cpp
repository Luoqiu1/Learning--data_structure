#include <bits/stdc++.h>

typedef int ElemType;
#define add 10
#define MAXN 100
using namespace std;
typedef struct{
	ElemType *elem;
	int length;
	int listsize;
}SqList;

int CreatList(SqList &L,int n)
{
	L.elem=(ElemType*)malloc(MAXN*sizeof(ElemType));L.length=0;L.listsize+=MAXN;
	if(!L.elem) return 0;
	while(n>L.listsize){
		ElemType *newbase=(ElemType*)realloc(L.elem,(L.listsize+add)*sizeof(ElemType));
		L.listsize+=add; 
	}
	return 1;
}

void AddElemType(SqList &L,int n)
{
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&L.elem[i]);
	}
}

void Nput(SqList &L,int n)
{
	n-=1;
	for( ;n>=0;n--){
		printf("%d ",L.elem[n]);
	}
	cout<<endl;
}

void put(SqList &L,int n)
{
	int i;
	for(i=0;i<n;i++){
		printf("%d ",L.elem[i]);
	}
	cout<<endl;
}

void zeng(SqList &L,int n)
{
	int i,j;
	ElemType min=L.elem[0];
	ElemType cur=0;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(L.elem[j]<min){
				min=L.elem[j];cur=j;
			}
		}
		ElemType mid=L.elem[i];L.elem[i]=min;L.elem[cur]=mid;
		min=L.elem[i+1];
	}
}
int main ()
{
	SqList L;
	printf("���������������Ԫ�ظ���n��������������n��Ԫ���Դ������Ա�\n");
	int n;
	scanf("%d",&n);
	CreatList(L,n);
	AddElemType(L,n);
	printf("�������ò�����\n������ú�����Ա�\n");
	Nput(L,n);
	printf("�����Ա���зǵݼ�������\n����ǵݼ�����������Ա�\n"); 
	zeng(L,n);
	put(L,n);
	return 0;
}
